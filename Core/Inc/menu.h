<<<<<<< HEAD
#ifndef MENU_H
#define MENU_H

#include "lvgl.h"
#include "stdio.h"
#include "menu_cb.h"
#include "stdlib.h"
#include "stdbool.h"
#include "fire_controller_configuration.h"


typedef struct {
    uint8_t id;
} button_data_t;

typedef struct {
    uint8_t fsm_mode;
    int8_t furnace;
    int8_t tank_top;
    int8_t tank_bottom;
    uint8_t active_f_pump;
    uint8_t active_m_pump;
    uint8_t active_u_pump;
    uint8_t active_blower;
} input_data_t;



void switch_screen(void (*create_screen_func)());
void set_specific_option(uint8_t option);
void create_settings_screen(void);
void create_main_screen(void);
void create_specific_setting_screen(void);
void start_menu();
bool should_start();
void send_input_data(const input_data_t* idata);
void menu_init(FCC* fcc);
void get_settings_data(FCC* fcc);
void check_if_inactive(void);


#endif //MENU_H
=======
#ifndef INC_MENU_H_
#define INC_MENU_H_

#include "main.h"
#include "tim.h"
#include "lcd.h"
#include "fire_controller_configuration.h"


typedef enum {
	MENU_MAIN = 0,
	MENU_FURNACE_TEMP,
	MENU_BLOWER_HYST,
	MENU_BLOWER_MIN,
	MENU_BLOWER_MAX,
	MENU_BLOWOUT_TIME,
	MENU_BLOWOUT_BREAK,
	MENU_WATER_TANK_TEMP,
	MENU_WATER_TANK_PUMP_ACTIV,
	MENU_WATER_TANK_PUMP_HYST,
	MENU_WATER_TANK_TEMP_DIFF,
	MENU_FURNACE_PUMP_ACTIV,
	MENU_FURNACE_PUMP_HYST,
	MENU_TEMP_OFFSET,
	MENU_FURNACE_TURN_OFF_TEMP,
	MENU_UNDERFLOOR_PUMP_ACTIV,
	MENU_BLOWER_ACTIV
} Menu;


void menu_init(uint8_t* encoder_value, LCD_GPIO* encoder_button, FCC* furnace_config, float* temperature_array);
HAL_StatusTypeDef render_menu();


#endif /* INC_MENU_H_ */

>>>>>>> 69c5dae536fbfef5287070d68229e71fd461c5fb
