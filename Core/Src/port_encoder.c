#include "port_encoder.h"

#define FILTER_SIZE  16



lv_indev_t * indev_encoder;
static int32_t encoder_diff;
static lv_indev_state_t encoder_state;
static uint32_t encoder_value;
static uint32_t last_encoder_value = 0;


static void encoder_init(void) {
	__HAL_TIM_SET_COUNTER(&htim2, 4294967295 >> 1);
	last_encoder_value = __HAL_TIM_GET_COUNTER(&htim2);
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
}

static void encoder_read(lv_indev_t * indev_drv, lv_indev_data_t * data) {
	data->enc_diff = encoder_diff;
	data->state = encoder_state;
	encoder_diff = 0;
}

static bool encoder_is_button_pressed() {
	uint8_t counter = 0;
	uint8_t button_filter[FILTER_SIZE] = {0};
	for (uint8_t i = 0; i < FILTER_SIZE; i++) {
		if (HAL_GPIO_ReadPin(ENCODER_BTN_GPIO_Port, ENCODER_BTN_Pin) == GPIO_PIN_RESET) {
			button_filter[i] = 1;
		} else {
			button_filter[i] = 0;
		}
		HAL_Delay(1);
	}

	for (uint8_t i = 0; i < FILTER_SIZE; i++) {
		if (button_filter[i] == 1) {
			counter++;
		}
	}

	if (counter >= 13) {
		return true;
	}

	return false;
}


void lv_port_indev_init(void) {

    encoder_init();

    indev_encoder = lv_indev_create();
    lv_indev_set_type(indev_encoder, LV_INDEV_TYPE_ENCODER);
    lv_indev_set_read_cb(indev_encoder, encoder_read);
}


void encoder_handler(void) {
	encoder_value = __HAL_TIM_GET_COUNTER(&htim2) >> 1;
	if (encoder_value > last_encoder_value) {
		encoder_diff += 1;
		last_encoder_value = encoder_value;
	} else if (encoder_value < last_encoder_value) {
		encoder_diff -= 1;
		last_encoder_value = encoder_value;
	}

    encoder_state = encoder_is_button_pressed() ? LV_INDEV_STATE_PRESSED : LV_INDEV_STATE_RELEASED;
}


lv_indev_t* encoder_get_ptr(void) {
	return indev_encoder;
}
