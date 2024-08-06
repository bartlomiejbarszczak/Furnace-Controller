#include "menu.h"


#define WIDTH       160
#define HEIGHT      128
#define CONT_WIDTH	WIDTH
#define CONT_HEIGHT	HEIGHT
#define NO_SETTINGS 16


static lv_subject_t setting_slider[NO_SETTINGS];
static lv_group_t* indev_group = NULL;
static lv_obj_t* screen = NULL;
static lv_obj_t* list = NULL;
static lv_obj_t* led_furnace = NULL;
static lv_obj_t* led_mixing = NULL;
static lv_obj_t* led_underfloor = NULL;
static lv_obj_t* led_blower = NULL;

static char fsm_label_buffer[20] = {0};
static lv_subject_t input_fsm_mode;
static lv_subject_t input_furnace;
static lv_subject_t input_tank_top;
static lv_subject_t input_tank_bottom;
static lv_subject_t input_active_f_pump;
static lv_subject_t input_active_m_pump;
static lv_subject_t input_active_u_pump;
static lv_subject_t input_active_blower;
static lv_subject_t output_start;
static uint8_t specific_menu_option = 0;
static uint8_t active_screen_id = 0;

static const char* button_labels[] = {
    "Temperatura pieca", "Histereza dmuchawy", "Min moc dmuchawy", "Max moc dmuchawy", "Czas trwania przedmuchu",
    "Dlugosc przerwy", "Temperatura bojlera", "T pracy pompy mieszajacej", "Hist pompy mieszajacej",
    "Roznica temperatury bojlera", "T pracy pompy obiegowej", "Hist pompy obiegowej",
    "Korekta temperatury", "Temperatura wygaszania", "Aktywna pompa podlogowki", "Aktywna dmuchawa"
};
static const char* fsm_mode_labels[] = {
    "Spoczynek", "Rozpalanie", "Praca", "Wygaszanie", "Przedmuch", "Przegrzanie"
};


static void free_list_user_data() {
    for (uint8_t i = 0; i <= NO_SETTINGS; i++) {
        lv_obj_t* btn = lv_obj_get_child(list, i);
        if (btn == NULL) {
            continue;
        }
        button_data_t* btn_data = lv_obj_get_user_data(btn);
        if(btn_data) {
            free(btn_data);
            btn_data = NULL;
        }
    }
}


static void clear_current_screen() {
    if (indev_group != NULL) {
        lv_group_delete(indev_group);
        indev_group = NULL;
    }

    if (list != NULL) {
        free_list_user_data();
        lv_obj_delete(list);
        list = NULL;
    }

    // clearing button in specific setting screen --- make it easer
    if (screen != NULL) {
        lv_obj_t* content = lv_obj_get_child(screen, 0);
        if (content != NULL) {
            lv_obj_t* button = lv_obj_get_child(content, 3);
            if (button != NULL) {
                button_data_t* button_data = lv_obj_get_user_data(button);
                if (button_data != NULL) {
                    free(button_data);
                    // my_free(btn_data, sizeof(button_data_t));
                }
            }
        }

        lv_obj_delete(screen);
        screen = NULL;
    }
}

static void create_default_screen() {
    screen = lv_obj_create(NULL);
    lv_screen_load(screen);
}


static void slider_set_proper_range(lv_obj_t* slider, lv_obj_t* label) {
    switch (specific_menu_option) {
        case 0: { // Temperatura pieca
            lv_slider_set_range(slider, 26, 75);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 1: { // Histereza dmuchawy
            lv_slider_set_range(slider, 0, 10);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 2: { // Min moc dmuchawy
            lv_slider_set_range(slider, 30, 100);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d %");
            break;
        }
        case 3: { // Max moc dmuchawy
            lv_slider_set_range(slider, 30, 100);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d %");
            break;
        }
        case 4: { // Czas trwania przedmuchu
            lv_slider_set_range(slider, 0, 60);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d s");
            break;
        }
        case 5: { // Dlugosc przerwy
            lv_slider_set_range(slider, 1, 15);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d m");
            break;
        }
        case 6: { // Temperatura bojlera
            lv_slider_set_range(slider, 40, 70);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 7: { // T pracy pompy mieszajacej
            lv_slider_set_range(slider, 40, 70);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 8: { // Hist pompy mieszajacej
            lv_slider_set_range(slider, 0, 10);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 9: { // Roznica temperatury bojlera
            lv_slider_set_range(slider, 0, 30);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 10: { // T pracy pompy obiegowej
            lv_slider_set_range(slider, 30, 70);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 11: { // Hist pompy obiegowej
            lv_slider_set_range(slider, 0, 10);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 12: { // Korekta temperatury
            lv_slider_set_range(slider, -10, 10);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 13: { // Temperatura wygaszania
            lv_slider_set_range(slider, 35, 60);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d °C");
            break;
        }
        case 14: { // Aktywna pompa podlogowki
            lv_slider_set_range(slider, 0, 1);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d");
            break;
        }
        case 15: { // Aktywna dmuchawa
            lv_slider_set_range(slider, 0, 1);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "%d");
            break;
        }
        default: { // NOT AN OPTION
            lv_slider_set_range(slider, 0, 0);
            lv_label_bind_text(label, &setting_slider[specific_menu_option], "NaN");
            break;
        }
    }
}


/* ------------------ Main Screen ----------------------- */
void create_main_screen(void) {
    create_default_screen();
    active_screen_id = 0;

    // Content area
    lv_obj_t* content_area = lv_obj_create(screen);
    lv_obj_set_size(content_area, CONT_WIDTH, CONT_HEIGHT);
    lv_obj_center(content_area);

    lv_obj_set_scrollbar_mode(content_area, LV_SCROLLBAR_MODE_OFF);

    // Floating go to settings button
    lv_obj_t * float_btn = lv_button_create(content_area);
    lv_obj_set_size(float_btn, 25, 25);
    lv_obj_add_flag(float_btn, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(float_btn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_add_event_cb(float_btn, goto_settings_button_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_radius(float_btn, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_image_src(float_btn, LV_SYMBOL_SETTINGS, 0);
    lv_obj_set_style_text_font(float_btn, lv_theme_get_font_large(float_btn), 0);

    // Label furnace temperature
    lv_obj_t* label_furnace_temp = lv_label_create(content_area);
    lv_label_bind_text(label_furnace_temp, &input_furnace, "Piec: %d °C");
    lv_obj_set_style_text_font(label_furnace_temp, &lv_font_montserrat_10, 0);
    lv_obj_align(label_furnace_temp, LV_ALIGN_TOP_RIGHT, 0, 0);

    // Label tank top temperature
    lv_obj_t* label_tank_top_temp = lv_label_create(content_area);
    lv_label_bind_text(label_tank_top_temp, &input_tank_top, "BojlerG: %d °C");
    lv_obj_set_style_text_font(label_tank_top_temp, &lv_font_montserrat_10, 0);
    lv_obj_align(label_tank_top_temp, LV_ALIGN_TOP_LEFT, 0, 0);

    // Label tank bottom temperature
    lv_obj_t* label_tank_bottom_temp = lv_label_create(content_area);
    lv_label_bind_text(label_tank_bottom_temp, &input_tank_bottom, "BojlerD: %d °C");
    lv_obj_set_style_text_font(label_tank_bottom_temp, &lv_font_montserrat_10, 0);
    lv_obj_align(label_tank_bottom_temp, LV_ALIGN_TOP_LEFT, 0, 15);

    // Label mode
    lv_obj_t* label_fsm_mode = lv_label_create(content_area);
    lv_label_bind_text(label_fsm_mode, &input_fsm_mode, "Tryb: %s");
    // lv_label_set_text_fmt(label_fsm_mode, "Tryb: %s", fsm_mode_labels[lv_subject_get_int(&input_fsm_mode)]);
    lv_obj_set_style_text_font(label_fsm_mode, &lv_font_montserrat_10, 0);
    lv_obj_align(label_fsm_mode, LV_ALIGN_LEFT_MID, 0, -10);

    // LED furnace pump
    led_furnace = lv_led_create(content_area);
    lv_obj_set_size(led_furnace, 12, 12);
    lv_obj_align(led_furnace, LV_ALIGN_LEFT_MID, 0, 10);
    lv_led_set_color(led_furnace, lv_color_hex(0x00ff00));
    lv_led_off(led_furnace);

    // Label furnace pump
    lv_obj_t* label_furnace = lv_label_create(content_area);
    lv_label_set_text(label_furnace, "Ob");
    lv_obj_set_style_text_font(label_furnace, &lv_font_montserrat_10, 0);
    lv_obj_align(label_furnace, LV_ALIGN_LEFT_MID, -1, 22);

    // LED mixing pump
    led_mixing = lv_led_create(content_area);
    lv_obj_set_size(led_mixing, 12, 12);
    lv_obj_align(led_mixing, LV_ALIGN_LEFT_MID, 25, 10);
    lv_led_set_color(led_mixing, lv_color_hex(0x00ff00));
    lv_led_off(led_mixing);

    // Label mixing pump
    lv_obj_t* label_mixing = lv_label_create(content_area);
    lv_label_set_text(label_mixing, "Mx");
    lv_obj_set_style_text_font(label_mixing, &lv_font_montserrat_10, 0);
    lv_obj_align(label_mixing, LV_ALIGN_LEFT_MID, 23, 22);

    // LED underfloor pump
    led_underfloor = lv_led_create(content_area);
    lv_obj_set_size(led_underfloor, 12, 12);
    lv_obj_align(led_underfloor, LV_ALIGN_LEFT_MID, 0, 35);
    lv_led_set_color(led_underfloor, lv_color_hex(0x00ff00));
    lv_led_off(led_underfloor);

    // Label underfloor pump
    lv_obj_t* label_underfloor = lv_label_create(content_area);
    lv_label_set_text(label_underfloor, "Pg");
    lv_obj_set_style_text_font(label_underfloor, &lv_font_montserrat_10, 0);
    lv_obj_align(label_underfloor, LV_ALIGN_LEFT_MID, -1, 46);

    // LED blower
    led_blower = lv_led_create(content_area);
    lv_obj_set_size(led_blower, 12, 12);
    lv_obj_align(led_blower, LV_ALIGN_LEFT_MID, 25, 35);
    lv_led_set_color(led_blower, lv_color_hex(0x00ff00));
    lv_led_off(led_blower);

    // Label blower pump
    lv_obj_t* label_blower = lv_label_create(content_area);
    lv_label_set_text(label_blower, "Dm");
    lv_obj_set_style_text_font(label_blower, &lv_font_montserrat_10, 0);
    lv_obj_align(label_blower, LV_ALIGN_LEFT_MID, 23, 46);

    // Switch start
    lv_obj_t* switch_start = lv_slider_create(content_area);
    lv_obj_set_size(switch_start, 12, 24);
    lv_obj_align(switch_start, LV_ALIGN_BOTTOM_MID, 10, -3);
    lv_slider_set_range(switch_start, 0, 1);
    lv_subject_init_int(&output_start, lv_subject_get_int(&output_start));
    lv_slider_bind_value(switch_start, &output_start);

    // Label start
    lv_obj_t* label_start = lv_label_create(content_area);
    lv_label_set_text(label_start, "START");
    lv_obj_set_style_text_font(label_start, &lv_font_montserrat_10, 0);
    lv_obj_align(label_start, LV_ALIGN_BOTTOM_MID, 10, -35);
}


/* ------------------ Settings Screen ----------------------- */
static void create_list_with_buttons() {
    for(uint8_t btn_cnt = 1; btn_cnt <= NO_SETTINGS; btn_cnt++) {
        lv_obj_t * btn = lv_list_add_button(list, NULL, button_labels[btn_cnt - 1]);
        lv_obj_set_style_text_font(btn, &lv_font_montserrat_8, LV_STATE_DEFAULT);

        button_data_t * btn_data = malloc(sizeof(button_data_t));
        btn_data->id = btn_cnt;
        lv_obj_set_user_data(btn, btn_data);
        lv_obj_add_event_cb(btn, setting_button_cb, LV_EVENT_CLICKED, btn_data);

        lv_group_add_obj(indev_group, btn);
    }
}


void create_settings_screen(void) {
    create_default_screen();
    active_screen_id = 1;

    // List
    list = lv_list_create(screen);
    lv_obj_set_size(list, CONT_WIDTH, CONT_HEIGHT);
    lv_obj_center(list);

    // Filling list
    create_list_with_buttons();

    // Floating back button
    lv_obj_t * float_btn = lv_button_create(list);
    lv_obj_set_size(float_btn, 25, 25);
    lv_obj_add_flag(float_btn, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(float_btn, LV_ALIGN_BOTTOM_RIGHT, 0, -lv_obj_get_style_pad_right(list, LV_PART_MAIN));
    lv_obj_add_event_cb(float_btn, float_back_button_event_cb, LV_EVENT_ALL, list);
    lv_obj_set_style_radius(float_btn, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_image_src(float_btn, LV_SYMBOL_LEFT, 0);
    lv_obj_set_style_text_font(float_btn, lv_theme_get_font_large(float_btn), 0);

    // Adding user data to back button
    button_data_t * btn_data = malloc(sizeof(button_data_t));
    btn_data->id = 0;
    lv_obj_set_user_data(float_btn, btn_data);
}


/* ------------------ Specific Setting Screen ----------------------- */
void create_specific_setting_screen(void) {
    create_default_screen();
    active_screen_id = 2;

    // Content area
    lv_obj_t* content_area = lv_obj_create(screen);
    lv_obj_set_size(content_area, CONT_WIDTH, CONT_HEIGHT);
    lv_obj_center(content_area);

    // Setting name label
    lv_obj_t* label_title = lv_label_create(content_area);
    lv_label_set_text(label_title, button_labels[specific_menu_option]);
    lv_obj_align(label_title, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_text_font(label_title, &lv_font_montserrat_10, 0);

    // Slider
    lv_obj_t* slider = lv_slider_create(content_area);
    lv_obj_align(slider, LV_ALIGN_LEFT_MID, 0, -10);
    lv_obj_set_size(slider, 80, 5);

    lv_subject_init_int(&setting_slider[specific_menu_option], lv_subject_get_int(&setting_slider[specific_menu_option])); // TODO change to fcc
    lv_slider_bind_value(slider, &setting_slider[specific_menu_option]);

    // Setting value label
    lv_obj_t* value_label = lv_label_create(content_area);
    lv_obj_align(value_label, LV_ALIGN_RIGHT_MID, 0, -10);

    // Set label and range to slider
    slider_set_proper_range(slider, value_label);

    // Floating back button
    lv_obj_t * float_btn = lv_button_create(content_area);
    lv_obj_set_size(float_btn, 25, 25);
    lv_obj_add_flag(float_btn, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(float_btn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_add_event_cb(float_btn, float_back_button_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_set_style_radius(float_btn, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_image_src(float_btn, LV_SYMBOL_LEFT, 0);
    lv_obj_set_style_text_font(float_btn, lv_theme_get_font_large(float_btn), 0);

    // Adding uset data to back button
    button_data_t * btn_data = malloc(sizeof(button_data_t));
    btn_data->id = 1;
    lv_obj_set_user_data(float_btn, btn_data);
}


void switch_screen(void (*create_screen_func)()) {
    clear_current_screen();
    create_screen_func();
}

void set_specific_option(uint8_t option) {
    specific_menu_option = option - 1;
}

bool should_start() {
    return (bool)lv_subject_get_int(&output_start);
}


static void set_led(lv_obj_t* led, lv_subject_t* input_pump) {
	if (led == NULL)
		return;

    if (lv_subject_get_int(input_pump) == 0) {
        lv_led_off(led);
    } else {
        lv_led_on(led);
    }
}


void send_input_data(const input_data_t* idata) {
    lv_subject_set_int(&input_furnace, idata->furnace);
    lv_subject_set_int(&input_tank_top, idata->tank_top);
    lv_subject_set_int(&input_tank_bottom, idata->tank_bottom);
    lv_subject_set_int(&input_active_f_pump, idata->active_f_pump);
    lv_subject_set_int(&input_active_m_pump, idata->active_m_pump);
    lv_subject_set_int(&input_active_u_pump, idata->active_u_pump);
    lv_subject_set_int(&input_active_blower, idata->active_blower);
    lv_subject_copy_string(&input_fsm_mode, fsm_mode_labels[idata->fsm_mode]);

    if (active_screen_id == 0) {
        set_led(led_furnace, &input_active_f_pump);
        set_led(led_mixing, &input_active_m_pump);
        set_led(led_underfloor, &input_active_u_pump);
        set_led(led_blower, &input_active_blower);
    }
}


void menu_init(FCC* fcc) {
	uint8_t n = sizeof(FCC) / sizeof(uint8_t);
	uint8_t fcc_buffer[n];
	serialize_FCC(fcc, fcc_buffer);

	for (uint8_t i = 0; i < NO_SETTINGS; i++) {
		lv_subject_init_int(&setting_slider[i], fcc_buffer[i]);
	}
	lv_subject_init_int(&input_furnace, 0);
	lv_subject_init_int(&input_tank_top, 0);
	lv_subject_init_int(&input_tank_bottom, 0);
	lv_subject_init_string(&input_fsm_mode, fsm_label_buffer, NULL, sizeof(fsm_label_buffer), "");
	lv_subject_init_int(&input_active_f_pump, 0);
	lv_subject_init_int(&input_active_m_pump, 0);
	lv_subject_init_int(&input_active_u_pump, 0);
	lv_subject_init_int(&input_active_blower, 0);
}


void get_settings_data(FCC* fcc) {
	uint8_t n = sizeof(FCC) / sizeof(uint8_t);
	uint8_t fcc_buffer[n];

	for (uint8_t i = 0; i < NO_SETTINGS; i++) {
		if (fcc_buffer[i] != lv_subject_get_int(&setting_slider[i])) {
			fcc_buffer[i] = lv_subject_get_int(&setting_slider[i]);
			made_changes();
		}
	}

	deserialize_FCC(fcc, fcc_buffer);

//	if (active_screen_id == 0) {
//		write_fc_configuration(fcc);
//	}
}


void check_if_inactive(void) {
    if (lv_display_get_inactive_time(NULL) >= 10000 && active_screen_id != 0) {
        switch_screen(create_main_screen);
    }
    if (lv_display_get_inactive_time(NULL) >= 5000 && lv_subject_get_int(&output_start) == 1) {
        lv_subject_set_int(&output_start, 0);
    }
}


void start_menu() {
    lv_lock();

    create_main_screen();

    lv_unlock();
}


