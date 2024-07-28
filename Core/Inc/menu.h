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

