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
