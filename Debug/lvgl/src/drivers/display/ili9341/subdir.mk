################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/drivers/display/ili9341/lv_ili9341.c 

OBJS += \
./lvgl/src/drivers/display/ili9341/lv_ili9341.o 

C_DEPS += \
./lvgl/src/drivers/display/ili9341/lv_ili9341.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/drivers/display/ili9341/%.o lvgl/src/drivers/display/ili9341/%.su lvgl/src/drivers/display/ili9341/%.cyclo: ../lvgl/src/drivers/display/ili9341/%.c lvgl/src/drivers/display/ili9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-drivers-2f-display-2f-ili9341

clean-lvgl-2f-src-2f-drivers-2f-display-2f-ili9341:
	-$(RM) ./lvgl/src/drivers/display/ili9341/lv_ili9341.cyclo ./lvgl/src/drivers/display/ili9341/lv_ili9341.d ./lvgl/src/drivers/display/ili9341/lv_ili9341.o ./lvgl/src/drivers/display/ili9341/lv_ili9341.su

.PHONY: clean-lvgl-2f-src-2f-drivers-2f-display-2f-ili9341

