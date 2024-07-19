#include "lcd_seven_segment.h"

static Segment seg_A;
static Segment seg_B;
static Segment seg_C;
static Segment seg_D;
static Segment seg_E;
static Segment seg_F;
static Segment seg_G;
static Segment seg_Decimal;
static Segment seg_Unit;
static bool is_set = false;
static bool show_error = false;
static uint8_t current_number = 0;
static uint8_t active_segment = 0;


static void show_digit(uint8_t mask) {
	HAL_GPIO_WritePin(seg_A.Port, seg_A.Pin, mask & 0x01);
	HAL_GPIO_WritePin(seg_B.Port, seg_B.Pin, mask & 0x02);
	HAL_GPIO_WritePin(seg_C.Port, seg_C.Pin, mask & 0x04);
	HAL_GPIO_WritePin(seg_D.Port, seg_D.Pin, mask & 0x08);
	HAL_GPIO_WritePin(seg_E.Port, seg_E.Pin, mask & 0x10);
	HAL_GPIO_WritePin(seg_F.Port, seg_F.Pin, mask & 0x20);
	HAL_GPIO_WritePin(seg_G.Port, seg_G.Pin, mask & 0x40);
}


static void choose_digit(uint32_t value) {
	const uint8_t digit[] = {
		0b0111111,
		0b0000110,
		0b1011011,
		0b1001111,
		0b1100110,
		0b1101101,
		0b1111101,
		0b0000111,
		0b1111111,
		0b1101111,
	};

	if (!show_error)
		show_digit(digit[value % 10]);
	else
		show_digit(0b1111001);
}


void seg7_update(void) {
	HAL_GPIO_WritePin(seg_Decimal.Port, seg_Decimal.Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(seg_Unit.Port, seg_Unit.Pin, GPIO_PIN_SET);

	switch (active_segment) {
	case 0:
		choose_digit(current_number / 10);
		HAL_GPIO_WritePin(seg_Decimal.Port, seg_Decimal.Pin, GPIO_PIN_RESET);
		active_segment = 1;
		break;
	case 1:
		choose_digit(current_number);
		HAL_GPIO_WritePin(seg_Unit.Port, seg_Unit.Pin, GPIO_PIN_RESET);
		active_segment = 0;
		break;
	}
}


void seg7_init(Segment A, Segment B, Segment C, Segment D, Segment E, Segment F, Segment G, Segment decimal, Segment unit) {
	seg_A = A;
	seg_B = B;
	seg_C = C;
	seg_D = D;
	seg_E = E;
	seg_F = F;
	seg_G = G;
	seg_Decimal = decimal;
	seg_Unit = unit;
	is_set = true;
}


HAL_StatusTypeDef seg7_display_number(uint8_t number, bool set_error) {
	if (!is_set)
		return HAL_ERROR;

	current_number = number;
	show_error = set_error;

	return HAL_OK;
}

