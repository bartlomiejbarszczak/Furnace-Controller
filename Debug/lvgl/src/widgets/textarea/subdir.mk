################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/widgets/textarea/lv_textarea.c 

OBJS += \
./lvgl/src/widgets/textarea/lv_textarea.o 

C_DEPS += \
./lvgl/src/widgets/textarea/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/widgets/textarea/%.o lvgl/src/widgets/textarea/%.su lvgl/src/widgets/textarea/%.cyclo: ../lvgl/src/widgets/textarea/%.c lvgl/src/widgets/textarea/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-widgets-2f-textarea

clean-lvgl-2f-src-2f-widgets-2f-textarea:
	-$(RM) ./lvgl/src/widgets/textarea/lv_textarea.cyclo ./lvgl/src/widgets/textarea/lv_textarea.d ./lvgl/src/widgets/textarea/lv_textarea.o ./lvgl/src/widgets/textarea/lv_textarea.su

.PHONY: clean-lvgl-2f-src-2f-widgets-2f-textarea
