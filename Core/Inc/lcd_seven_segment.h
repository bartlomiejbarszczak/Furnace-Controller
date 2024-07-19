#ifndef INC_LCD_SEVEN_SEGMENT_H_
#define INC_LCD_SEVEN_SEGMENT_H_

#include "main.h"
#include "tim.h"
#include "stdbool.h"


typedef struct Segment {
	GPIO_TypeDef* Port;
	uint16_t Pin;
} Segment;


void seg7_init(Segment A, Segment B, Segment C, Segment D, Segment E, Segment F, Segment G, Segment decimal, Segment unit);
void seg7_update(void);
HAL_StatusTypeDef seg7_display_number(uint8_t number, bool set_error);


#endif /* INC_LCD_SEVEN_SEGMENT_H_ */
