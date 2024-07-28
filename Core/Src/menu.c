#include "menu.h"


static uint8_t* ENCODER_VALUE;
static LCD_GPIO* ENCODER_BUTTON;
static FCC* FURNACE_CONFIG;
static float* TEMPERATURE_ARRAY;
static bool menu_locked = false;
static bool submenu_locked = true;
static uint8_t menu_option = 0;
static uint8_t submenu_option = 0;


static bool is_clicked() {
	if (HAL_GPIO_ReadPin(ENCODER_BUTTON->Port, ENCODER_BUTTON->Pin) == GPIO_PIN_SET)
		return true;

	return false;
}


static HAL_StatusTypeDef draw_menu_main() {
	lcd_draw_background();


	return HAL_OK;

}


static Menu get_menu_screen() {
	switch (menu_option) {
	case 0:
		return MENU_MAIN;
	case 1:
		return MENU_FURNACE_TEMP;
	case 2:
		return MENU_BLOWER_HYST;
	case 3:
		return MENU_BLOWER_MIN;
	case 4:
		return MENU_BLOWER_MAX;
	case 5:
		return MENU_BLOWOUT_TIME;
	case 6:
		return MENU_BLOWOUT_BREAK;
	case 7:
		return MENU_WATER_TANK_TEMP;
	case 8:
		return MENU_WATER_TANK_PUMP_ACTIV;
	case 9:
		return MENU_WATER_TANK_PUMP_HYST;
	case 10:
		return MENU_WATER_TANK_TEMP_DIFF;
	case 11:
		return MENU_FURNACE_PUMP_ACTIV;
	case 12:
		return MENU_FURNACE_PUMP_HYST;
	case 13:
		return MENU_TEMP_OFFSET;
	case 14:
		return MENU_FURNACE_TURN_OFF_TEMP;
	case 15:
		return MENU_UNDERFLOOR_PUMP_ACTIV;
	case 16:
		return MENU_BLOWER_ACTIV;
	default:
		return MENU_MAIN;
	}
}


void menu_init(uint8_t* encoder_value, LCD_GPIO* encoder_button, FCC* furnace_config, float* temperature_array) {
	ENCODER_VALUE = encoder_value;
	ENCODER_BUTTON = encoder_button;
	FURNACE_CONFIG = furnace_config;
	TEMPERATURE_ARRAY = temperature_array;
}


HAL_StatusTypeDef render_menu() {
	if (!menu_locked) {
		menu_option = *ENCODER_VALUE;
		menu_locked = false;
		submenu_locked = true;
	}
	else if (!submenu_locked) {
		submenu_option = *ENCODER_VALUE;
		menu_locked = true;
		submenu_locked = false;
	}

	Menu screen = get_menu_screen();

	switch (screen) {
		case MENU_MAIN: {
			return lcd_draw_background();
		}
		case MENU_FURNACE_TEMP: {
			return lcd_draw_setting_1();
			break;
		}
		case MENU_BLOWER_HYST: {
			return lcd_draw_setting_2();
			break;
		}
		default: {
			return lcd_draw_background();
			break;
		}
	}

	return HAL_OK;
}
