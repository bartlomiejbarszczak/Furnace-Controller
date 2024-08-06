#ifndef INC_PORT_ENCODER_H_
#define INC_PORT_ENCODER_H_


#include "lvgl.h"
#include "tim.h"
#include "stdio.h"


void lv_port_indev_init(void);

void encoder_handler(void);

lv_indev_t* encoder_get_ptr(void);


#endif /* INC_PORT_ENCODER_H_ */
