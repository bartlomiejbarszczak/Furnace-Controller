################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/porting/lv_port_disp_template.c \
../lvgl/examples/porting/lv_port_fs_template.c \
../lvgl/examples/porting/lv_port_indev_template.c \
../lvgl/examples/porting/lv_port_lcd_stm32_template.c 

OBJS += \
./lvgl/examples/porting/lv_port_disp_template.o \
./lvgl/examples/porting/lv_port_fs_template.o \
./lvgl/examples/porting/lv_port_indev_template.o \
./lvgl/examples/porting/lv_port_lcd_stm32_template.o 

C_DEPS += \
./lvgl/examples/porting/lv_port_disp_template.d \
./lvgl/examples/porting/lv_port_fs_template.d \
./lvgl/examples/porting/lv_port_indev_template.d \
./lvgl/examples/porting/lv_port_lcd_stm32_template.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/porting/%.o lvgl/examples/porting/%.su lvgl/examples/porting/%.cyclo: ../lvgl/examples/porting/%.c lvgl/examples/porting/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-porting

clean-lvgl-2f-examples-2f-porting:
	-$(RM) ./lvgl/examples/porting/lv_port_disp_template.cyclo ./lvgl/examples/porting/lv_port_disp_template.d ./lvgl/examples/porting/lv_port_disp_template.o ./lvgl/examples/porting/lv_port_disp_template.su ./lvgl/examples/porting/lv_port_fs_template.cyclo ./lvgl/examples/porting/lv_port_fs_template.d ./lvgl/examples/porting/lv_port_fs_template.o ./lvgl/examples/porting/lv_port_fs_template.su ./lvgl/examples/porting/lv_port_indev_template.cyclo ./lvgl/examples/porting/lv_port_indev_template.d ./lvgl/examples/porting/lv_port_indev_template.o ./lvgl/examples/porting/lv_port_indev_template.su ./lvgl/examples/porting/lv_port_lcd_stm32_template.cyclo ./lvgl/examples/porting/lv_port_lcd_stm32_template.d ./lvgl/examples/porting/lv_port_lcd_stm32_template.o ./lvgl/examples/porting/lv_port_lcd_stm32_template.su

.PHONY: clean-lvgl-2f-examples-2f-porting
