#include "menu_cb.h"



void setting_button_cb(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);

    if(code == LV_EVENT_CLICKED) {
        button_data_t* btn_data = lv_event_get_user_data(e);
        lv_obj_t* label = lv_obj_get_child(target, 0);

        if(btn_data != NULL || label != NULL) {
            set_specific_option(btn_data->id);
            void (*create_screen_func)() = &create_specific_setting_screen;
            switch_screen(create_screen_func);
        }
    }
}


void goto_settings_button_cb(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED) {
        void (*create_screen_func)() = &create_settings_screen;
        switch_screen(create_screen_func);
    }
}


void float_back_button_event_cb(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * float_btn = lv_event_get_target(e);

    if (code == LV_EVENT_CLICKED) {
        button_data_t* float_btn_data = lv_obj_get_user_data(float_btn);

        if (float_btn_data != NULL) {
            switch (float_btn_data->id) {
                case 0: {
                    void (*create_screen_func)() = &create_main_screen;
                    switch_screen(create_screen_func);
                    break;
                }
                case 1: {
                    void (*create_screen_func)() = &create_settings_screen;
                    switch_screen(create_screen_func);
                    break;
                }
                default: {
                    void (*create_screen_func)() = &create_main_screen;
                    switch_screen(create_screen_func);
                    break;
                }
            }
        }
    }
}
