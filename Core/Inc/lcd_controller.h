#ifndef INC_LCD_CONTROLLER_H_
#define INC_LCD_CONTROLLER_H_

#include "lcd.h"
#include "main.h"
#include "lvgl.h"



void lv_port_disp_init(void);

void disp_enable_update(void);

void disp_disable_update(void);

void lcd_transfer_done(void);

lv_display_t* disp_get_ptr(void);


#endif /* INC_LCD_CONTROLLER_H_ */
