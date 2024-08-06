################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/libs/tiny_ttf/lv_tiny_ttf.c 

OBJS += \
./lvgl/src/libs/tiny_ttf/lv_tiny_ttf.o 

C_DEPS += \
./lvgl/src/libs/tiny_ttf/lv_tiny_ttf.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/libs/tiny_ttf/%.o lvgl/src/libs/tiny_ttf/%.su lvgl/src/libs/tiny_ttf/%.cyclo: ../lvgl/src/libs/tiny_ttf/%.c lvgl/src/libs/tiny_ttf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-libs-2f-tiny_ttf

clean-lvgl-2f-src-2f-libs-2f-tiny_ttf:
	-$(RM) ./lvgl/src/libs/tiny_ttf/lv_tiny_ttf.cyclo ./lvgl/src/libs/tiny_ttf/lv_tiny_ttf.d ./lvgl/src/libs/tiny_ttf/lv_tiny_ttf.o ./lvgl/src/libs/tiny_ttf/lv_tiny_ttf.su

.PHONY: clean-lvgl-2f-src-2f-libs-2f-tiny_ttf

