################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/widgets/msgbox/lv_msgbox.c 

OBJS += \
./Drivers/lvgl/src/widgets/msgbox/lv_msgbox.o 

C_DEPS += \
./Drivers/lvgl/src/widgets/msgbox/lv_msgbox.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/widgets/msgbox/%.o Drivers/lvgl/src/widgets/msgbox/%.su Drivers/lvgl/src/widgets/msgbox/%.cyclo: ../Drivers/lvgl/src/widgets/msgbox/%.c Drivers/lvgl/src/widgets/msgbox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/Drivers/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-msgbox

clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-msgbox:
	-$(RM) ./Drivers/lvgl/src/widgets/msgbox/lv_msgbox.cyclo ./Drivers/lvgl/src/widgets/msgbox/lv_msgbox.d ./Drivers/lvgl/src/widgets/msgbox/lv_msgbox.o ./Drivers/lvgl/src/widgets/msgbox/lv_msgbox.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-msgbox

