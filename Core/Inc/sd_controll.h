#ifndef INC_SD_CONTROLL_H_
#define INC_SD_CONTROLL_H_


#include "main.h"
#include "fatfs.h"
#include "string.h"
#include "stdio.h"
#include "rtc.h"


typedef enum SD_Controll_Status {
	SD_OK,
	SD_Error,
	SD_MOUNT_ERROR,
	SD_FILE_OPEN_ERROR,
	SD_FILE_WRITE_ERROR,
	SD_CLOSE_ERROR,
	SD_DEMOUNT_ERROR,
}SD_Controll_Status;


HAL_StatusTypeDef set_rtc_datatime();

SD_Controll_Status log_data(float temperature);



#endif /* INC_SD_CONTROLL_H_ */
