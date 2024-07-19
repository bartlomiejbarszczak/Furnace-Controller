/*
 * LCD.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Bartlomiej
 */

#pragma once

#include "main.h"
#include <stdint.h>
#include "spi.h"
#include "stdbool.h"

/* LCD resolution */
#define LCD_WIDTH	160
#define LCD_HEIGHT	128


/* Offsets */
#define LCD_OFFSET_X  1
#define LCD_OFFSET_Y  2


/* Steering commands */
#define ST7735S_SLPOUT			0x11
#define ST7735S_DISPOFF			0x28
#define ST7735S_DISPON			0x29
#define ST7735S_CASET			0x2a
#define ST7735S_RASET			0x2b
#define ST7735S_RAMWR			0x2c
#define ST7735S_MADCTL			0x36
#define ST7735S_COLMOD			0x3a
#define ST7735S_FRMCTR1			0xb1
#define ST7735S_FRMCTR2			0xb2
#define ST7735S_FRMCTR3			0xb3
#define ST7735S_INVCTR			0xb4
#define ST7735S_PWCTR1			0xc0
#define ST7735S_PWCTR2			0xc1
#define ST7735S_PWCTR3			0xc2
#define ST7735S_PWCTR4			0xc3
#define ST7735S_PWCTR5			0xc4
#define ST7735S_VMCTR1			0xc5
#define ST7735S_GAMCTRP1		0xe0
#define ST7735S_GAMCTRN1		0xe1


/* Colors */
#define BLACK     0x0000
#define RED       0xf800
#define GREEN     0x07e0
#define BLUE      0x001f
#define YELLOW    0xffe0
#define MAGENTA   0xf81f
#define CYAN      0x07ff
#define WHITE     0xffff


typedef enum LCD_STATE{
	LCD_OK = 0,
	LCD_BUSY
} LCD_STATE;


typedef struct LCD_GPIO {
	GPIO_TypeDef* Port;
	uint16_t Pin;
} LCD_GPIO;


void lcd_full_box(int x, int y, int width, int height, uint16_t color);

void lcd_put_pixel(int x, int y, uint16_t color);

HAL_StatusTypeDef lcd_init(SPI_HandleTypeDef* lcd_spi, LCD_GPIO* lcd_cs, LCD_GPIO* lcd_dc, LCD_GPIO* lcd_rst);

void lcd_show(void);

void lcd_transfer_done(void);

LCD_STATE lcd_is_busy(void);

void lcd_draw_circle_full(int x, int y, int radius, uint16_t color);

void lcd_draw_circle(int x, int y, int radius, uint16_t color);

void lcd_draw_line(int start_x, int start_y, int end_x, int end_y, uint16_t color);

void lcd_draw_backgroud();
