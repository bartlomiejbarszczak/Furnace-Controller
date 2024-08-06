/*
 * LCD.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Bartlomiej
 */


#include "lcd.h"


#define CMD(x) 				((x) | 0x100)
#define LCD_MAX_TIMEOUT 	0x64


static SPI_HandleTypeDef* LCD_SPI;
static LCD_GPIO LCD_CS;
static LCD_GPIO LCD_DC;
static LCD_GPIO LCD_RST;
static bool is_set = false;
static uint16_t buffer[LCD_WIDTH * LCD_HEIGHT] = {0};

static const uint16_t init_table[] = {
	CMD(ST7735S_FRMCTR1), 0x01, 0x2c, 0x2d,
	CMD(ST7735S_FRMCTR2), 0x01, 0x2c, 0x2d,
	CMD(ST7735S_FRMCTR3), 0x01, 0x2c, 0x2d, 0x01, 0x2c, 0x2d,
	CMD(ST7735S_INVCTR), 0x07,
	CMD(ST7735S_PWCTR1), 0xa2, 0x02, 0x84,
	CMD(ST7735S_PWCTR2), 0xc5,
	CMD(ST7735S_PWCTR3), 0x0a, 0x00,
	CMD(ST7735S_PWCTR4), 0x8a, 0x2a,
	CMD(ST7735S_PWCTR5), 0x8a, 0xee,
	CMD(ST7735S_VMCTR1), 0x0e,
	CMD(ST7735S_GAMCTRP1), 0x0f, 0x1a, 0x0f, 0x18, 0x2f, 0x28, 0x20, 0x22,
		0x1f, 0x1b, 0x23, 0x37, 0x00, 0x07, 0x02, 0x10,
	CMD(ST7735S_GAMCTRN1), 0x0f, 0x1b, 0x0f, 0x17, 0x33, 0x2c, 0x29, 0x2e,
		0x30, 0x30, 0x39, 0x3f, 0x00, 0x07, 0x03, 0x10,
	CMD(0xf0), 0x01,
	CMD(0xf6), 0x00,
	CMD(ST7735S_COLMOD), 0x05,
	CMD(ST7735S_MADCTL), 0xa0,
};


static HAL_StatusTypeDef lcd_cmd(uint8_t cmd) {
	HAL_GPIO_WritePin(LCD_DC.Port, LCD_DC.Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CS.Port, LCD_CS.Pin, GPIO_PIN_RESET);

	if (HAL_SPI_Transmit(LCD_SPI, &cmd, 1, LCD_MAX_TIMEOUT) != HAL_OK)
		return HAL_ERROR;

	HAL_GPIO_WritePin(LCD_CS.Port, LCD_CS.Pin, GPIO_PIN_SET);
	return HAL_OK;
}

static HAL_StatusTypeDef lcd_data(uint8_t data) {
	HAL_GPIO_WritePin(LCD_DC.Port, LCD_DC.Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_CS.Port, LCD_CS.Pin, GPIO_PIN_RESET);

	if (HAL_SPI_Transmit(LCD_SPI, &data, 1, LCD_MAX_TIMEOUT) != HAL_OK)
		return HAL_ERROR;

	HAL_GPIO_WritePin(LCD_CS.Port, LCD_CS.Pin, GPIO_PIN_SET);
	return HAL_OK;
}

static void lcd_data16(uint16_t value) {
	lcd_data(value >> 8);
	lcd_data(value);
}

static HAL_StatusTypeDef lcd_send(uint16_t value) {
	if (value & 0x100) {
		if (lcd_cmd(value) != HAL_OK)
			return HAL_ERROR;
	}
	else {
		if (lcd_data(value) != HAL_OK)
			return HAL_ERROR;
	}

	return HAL_OK;
}


HAL_StatusTypeDef lcd_init(SPI_HandleTypeDef* lcd_spi, LCD_GPIO* lcd_cs, LCD_GPIO* lcd_dc, LCD_GPIO* lcd_rst) {
	LCD_SPI = lcd_spi;
	LCD_CS = *lcd_cs;
	LCD_DC = *lcd_dc;
	LCD_RST = *lcd_rst;
	// TODO brightness control GPIO
	is_set = true;

	HAL_GPIO_WritePin(LCD_RST.Port, LCD_RST.Pin, GPIO_PIN_RESET);
	HAL_Delay(100); // TODO time could be lower
	HAL_GPIO_WritePin(LCD_RST.Port, LCD_RST.Pin, GPIO_PIN_SET);
	HAL_Delay(100);

	for (uint8_t i = 0; i < sizeof(init_table) / sizeof(init_table[0]); i++) {
		if (lcd_send(init_table[i]) != HAL_OK)
			return HAL_ERROR;
	}

	HAL_Delay(200);
	if (lcd_cmd(ST7735S_SLPOUT) != HAL_OK)
		return HAL_ERROR;
	HAL_Delay(120);

	if (lcd_cmd(ST7735S_DISPON) != HAL_OK)
		return HAL_ERROR;

	return HAL_OK;
}

static void lcd_set_window(int x, int y, int width, int height) {
	lcd_cmd(ST7735S_CASET);
	lcd_data16(LCD_OFFSET_X + x);
	lcd_data16(LCD_OFFSET_X + x + width - 1);

	lcd_cmd(ST7735S_RASET);
	lcd_data16(LCD_OFFSET_Y + y);
	lcd_data16(LCD_OFFSET_Y + y + height- 1);
}

void lcd_put_pixel(int16_t x, int16_t y, uint16_t color)
{
	buffer[x + y * LCD_WIDTH] = __REV16(color);
}

HAL_StatusTypeDef lcd_show(void) {
	lcd_set_window(0, 0, LCD_WIDTH, LCD_HEIGHT);
	lcd_cmd(ST7735S_RAMWR);
	HAL_GPIO_WritePin(LCD_DC.Port, LCD_DC.Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_CS.Port, LCD_CS.Pin, GPIO_PIN_RESET);
	return HAL_SPI_Transmit_DMA(LCD_SPI, (uint8_t*)buffer, sizeof(buffer));
}

void lcd_transfer_done(void) {
	HAL_GPIO_WritePin(LCD_CS.Port, LCD_CS.Pin, GPIO_PIN_SET);
}

bool lcd_is_busy(void) {
	if (HAL_SPI_GetState(LCD_SPI) == HAL_SPI_STATE_BUSY)
		return true;
	else
		return false;
}

void lcd_full_box(int x, int y, int width, int height, uint16_t color) {
	for (uint8_t i = x; i < width + x; i++) {
		for (uint8_t j = y; j < height + y; j++) {
			lcd_put_pixel(i, j, color);
		}
	}
}

void lcd_empty_box(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t color) {
	for (uint8_t i = x; i < width + x; i++) {
		lcd_put_pixel(i, y, color);
		lcd_put_pixel(i, y + height, color);
	}

	for (uint8_t i = y; i < height + y; i++) {
		lcd_put_pixel(x, i, color);
		lcd_put_pixel(x + width, i, color);
	}
}

void lcd_draw_circle_full(int x, int y, int radius, uint16_t color) {
	for (int i = x - 5; i < 100; i++) {

	}
}

void lcd_draw_circle(int x, int y, int radius, uint16_t color);

void lcd_draw_line(int start_x, int start_y, int end_x, int end_y, uint16_t color) {
//	float a = (start_y - end_y) / (start_x - end_x);
//	float b = end_y - a * end_x;

//	for (uint8_t i = min_x; i < max_x; i++) {
//
//	}
}

HAL_StatusTypeDef lcd_draw_background() {
	while (lcd_is_busy()) {
	}
	lcd_full_box(0, 0, LCD_WIDTH, LCD_HEIGHT, WHITE);

	// drawing fire place
	lcd_empty_box(20, 70, 30, 40, BLACK);
	lcd_empty_box(50, 97, 80, 0, BLACK);
	lcd_empty_box(50, 105, 80, 0, BLACK);
	lcd_empty_box(130, 97, 0, 9, BLACK);

	// drawing water tank
	lcd_empty_box(110, 70, 30, 40, BLACK);


	// flush the result
	return lcd_show();
}

HAL_StatusTypeDef lcd_draw_setting_1() {
	while (lcd_is_busy()) {
	}
	lcd_full_box(0, 0, LCD_WIDTH, LCD_HEIGHT, WHITE);

	lcd_full_box(50, 50, 10, 30, RED);

	return lcd_show();
}


HAL_StatusTypeDef lcd_draw_setting_2() {
	while (lcd_is_busy()) {
	}
	lcd_full_box(0, 0, LCD_WIDTH, LCD_HEIGHT, WHITE);

	lcd_full_box(20, 20, 100, 60, GREEN);

	return lcd_show();
}


