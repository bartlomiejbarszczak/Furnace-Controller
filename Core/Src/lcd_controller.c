#include "lcd_controller.h"
#include <stdbool.h>

#define MY_DISP_HOR_RES    160
#define MY_DISP_VER_RES    128
#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565))


lv_display_t* disp = NULL;
volatile bool disp_flush_enabled = true;
static uint8_t buf_1[MY_DISP_HOR_RES * 20 * BYTE_PER_PIXEL];         /*A buffer for 40 rows*/


static void disp_init(void) {
    lcd_init();
}


static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map) {
    if(disp_flush_enabled) {
        lcd_set_window(area->x1, area->y1, area->x2, area->y2);

        uint32_t height = area->y2 - area->y1 + 1;
        uint32_t width = area->x2 - area->x1 + 1;

        lcd_draw_bitmap(width, height, px_map);
    }
}


void lv_port_disp_init(void) {
    disp_init();

    disp = lv_display_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_display_set_flush_cb(disp, disp_flush);

    lv_display_set_buffers(disp, buf_1, NULL, sizeof(buf_1), LV_DISPLAY_RENDER_MODE_PARTIAL);
}


void disp_enable_update(void) {
    disp_flush_enabled = true;
}


void disp_disable_update(void) {
    disp_flush_enabled = false;
}


void lcd_transfer_done(void) {
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, GPIO_PIN_SET);
	lv_display_flush_ready(disp);
}


lv_display_t* disp_get_ptr(void) {
	return disp;
}
