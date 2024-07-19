#include "sd_controll.h"

#define BUFFER_SIZE 75


static void prepare_date(char* time_string) {
	RTC_TimeTypeDef current_time = {0};
	RTC_DateTypeDef current_date = {0};

	if (HAL_RTC_GetTime(&hrtc, &current_time, RTC_FORMAT_BCD) != HAL_OK){
		// TODO error handle
	}

	if (HAL_RTC_GetDate(&hrtc, &current_date, RTC_FORMAT_BCD) != HAL_OK){
		// TODO error handle
	}

	sprintf(time_string, "%d-%d-20%d %d:%d:%d", current_date.Date, current_date.Month, current_date.Year, current_time.Hours, current_time.Minutes, current_time.Seconds);
}

static void prepare_prefix(char* buffer, float temperature) {
	char str[BUFFER_SIZE] = {0};
	char date[30];
	prepare_date(date);

	sprintf(str, "%s\r\nTemperature: %f\r\n\n", date, temperature);

	strcpy(buffer, str);
}


HAL_StatusTypeDef set_rtc_datatime() {
	RTC_TimeTypeDef sTime = {0};
	sTime.Hours = 11;
	sTime.Minutes = 59;
	sTime.Seconds = 55;
	sTime.TimeFormat = RTC_HOURFORMAT_24;
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation = RTC_STOREOPERATION_RESET;

	RTC_DateTypeDef sDate = {0};
	sDate.WeekDay = RTC_WEEKDAY_TUESDAY;
	sDate.Month = RTC_MONTH_JULY;
	sDate.Date = 16;
	sDate.Year = 24;

	if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
		return HAL_ERROR;

	if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
		return HAL_ERROR;

	return HAL_OK;
}


SD_Controll_Status log_data(float temperature) {
	FRESULT sd_result;
	FATFS SD_FatFS;
	FIL SD_File;
	char buffer[BUFFER_SIZE] = {0};
	UINT bytes_written = 0;

	sd_result = f_mount(&SD_FatFS, "/", 1);
	if (sd_result != FR_OK) {
		return SD_MOUNT_ERROR;
	}

	sd_result = f_open(&SD_File, "temp.txt", FA_OPEN_APPEND | FA_WRITE);
	if (sd_result != FR_OK) {
		return SD_FILE_OPEN_ERROR;
	}

	prepare_prefix(buffer, temperature);

	sd_result = f_write(&SD_File, buffer, sizeof(buffer), &bytes_written);
	if (sd_result != FR_OK || bytes_written == 0) {
		return SD_FILE_WRITE_ERROR;
	}

	sd_result = f_close(&SD_File);
	if (sd_result != FR_OK) {
		return SD_CLOSE_ERROR;
	}

	sd_result = f_mount(NULL, "/", 1);
	if (sd_result != FR_OK) {
		return SD_DEMOUNT_ERROR;
	}

	return SD_OK;
}
