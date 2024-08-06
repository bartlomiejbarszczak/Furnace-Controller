#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#include "stdint.h"
#include "stdbool.h"

/* LCD Resolution */
//#define LCD_WIDTH 	160U
//#define LCD_HEIGHT 	128U
#define LCD_MAX_TIMEOUT 100U

/* LCD COMMANDS */
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


void lcd_init(void);
void lcd_set_window(int x, int y, int width, int height);
void lcd_draw_bitmap(uint16_t width, uint16_t height, uint8_t* px_map);


#endif /* LCD_LCD_H_ */
