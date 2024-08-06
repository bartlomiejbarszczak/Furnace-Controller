################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/libs/barcode/code128.c \
../lvgl/src/libs/barcode/lv_barcode.c 

OBJS += \
./lvgl/src/libs/barcode/code128.o \
./lvgl/src/libs/barcode/lv_barcode.o 

C_DEPS += \
./lvgl/src/libs/barcode/code128.d \
./lvgl/src/libs/barcode/lv_barcode.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/libs/barcode/%.o lvgl/src/libs/barcode/%.su lvgl/src/libs/barcode/%.cyclo: ../lvgl/src/libs/barcode/%.c lvgl/src/libs/barcode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-libs-2f-barcode

clean-lvgl-2f-src-2f-libs-2f-barcode:
	-$(RM) ./lvgl/src/libs/barcode/code128.cyclo ./lvgl/src/libs/barcode/code128.d ./lvgl/src/libs/barcode/code128.o ./lvgl/src/libs/barcode/code128.su ./lvgl/src/libs/barcode/lv_barcode.cyclo ./lvgl/src/libs/barcode/lv_barcode.d ./lvgl/src/libs/barcode/lv_barcode.o ./lvgl/src/libs/barcode/lv_barcode.su

.PHONY: clean-lvgl-2f-src-2f-libs-2f-barcode

