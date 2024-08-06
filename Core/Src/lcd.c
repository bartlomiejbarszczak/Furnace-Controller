#include "lcd.h"
#include "spi.h"


#define CMD(x)		((x) | 0x100)

/* INIT Table*/
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



static void lcd_cmd(uint8_t cmd) {
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, &cmd, 1, LCD_MAX_TIMEOUT);
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
}


static void lcd_data(uint8_t data) {
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, &data, 1, LCD_MAX_TIMEOUT);
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
}

static void lcd_send(uint16_t value) {
	if (value & 0x100) {
		lcd_cmd(value);
	} else {
		lcd_data(value);
	}
}

static void lcd_data16(uint16_t value)
{
	lcd_data(value >> 8);
	lcd_data(value);
}

static void reverse_color(uint8_t* px_map, uint32_t size) {
	uint8_t temp_px;
	while (size > 0) {
		temp_px = *(px_map + 1);
		*(px_map + 1) = *px_map;
		*px_map = temp_px;
		px_map += 2;
		size -= 2;
	}
}


void lcd_init(void) {
  HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_RESET);
  HAL_Delay(100);
  HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, GPIO_PIN_SET);
  HAL_Delay(100);

  for (uint16_t i = 0; i < sizeof(init_table) / sizeof(uint16_t); i++) {
    lcd_send(init_table[i]);
  }

  HAL_Delay(200);

  lcd_cmd(ST7735S_SLPOUT);
  HAL_Delay(120);

  lcd_cmd(ST7735S_DISPON);
}


void lcd_set_window(int x1, int y1, int x2, int y2) {
  lcd_cmd(ST7735S_CASET);
  lcd_data16(x1);
  lcd_data16(x2);

  lcd_cmd(ST7735S_RASET);
  lcd_data16(y1);
  lcd_data16(y2);
}


void lcd_draw_bitmap(uint16_t width, uint16_t height, uint8_t* px_map) {
	lcd_cmd(ST7735S_RAMWR);
	reverse_color(px_map, width * height * 2);
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit_DMA(&hspi2, px_map, width * height * 2);
}
