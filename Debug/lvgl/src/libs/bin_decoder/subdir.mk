################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/libs/bin_decoder/lv_bin_decoder.c 

OBJS += \
./lvgl/src/libs/bin_decoder/lv_bin_decoder.o 

C_DEPS += \
./lvgl/src/libs/bin_decoder/lv_bin_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/libs/bin_decoder/%.o lvgl/src/libs/bin_decoder/%.su lvgl/src/libs/bin_decoder/%.cyclo: ../lvgl/src/libs/bin_decoder/%.c lvgl/src/libs/bin_decoder/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-libs-2f-bin_decoder

clean-lvgl-2f-src-2f-libs-2f-bin_decoder:
	-$(RM) ./lvgl/src/libs/bin_decoder/lv_bin_decoder.cyclo ./lvgl/src/libs/bin_decoder/lv_bin_decoder.d ./lvgl/src/libs/bin_decoder/lv_bin_decoder.o ./lvgl/src/libs/bin_decoder/lv_bin_decoder.su

.PHONY: clean-lvgl-2f-src-2f-libs-2f-bin_decoder

