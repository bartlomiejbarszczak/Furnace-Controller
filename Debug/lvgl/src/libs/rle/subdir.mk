################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/libs/rle/lv_rle.c 

OBJS += \
./lvgl/src/libs/rle/lv_rle.o 

C_DEPS += \
./lvgl/src/libs/rle/lv_rle.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/libs/rle/%.o lvgl/src/libs/rle/%.su lvgl/src/libs/rle/%.cyclo: ../lvgl/src/libs/rle/%.c lvgl/src/libs/rle/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-libs-2f-rle

clean-lvgl-2f-src-2f-libs-2f-rle:
	-$(RM) ./lvgl/src/libs/rle/lv_rle.cyclo ./lvgl/src/libs/rle/lv_rle.d ./lvgl/src/libs/rle/lv_rle.o ./lvgl/src/libs/rle/lv_rle.su

.PHONY: clean-lvgl-2f-src-2f-libs-2f-rle

