################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/tests/src/lv_test_helpers.c \
../Drivers/lvgl/tests/src/lv_test_indev.c \
../Drivers/lvgl/tests/src/lv_test_init.c 

OBJS += \
./Drivers/lvgl/tests/src/lv_test_helpers.o \
./Drivers/lvgl/tests/src/lv_test_indev.o \
./Drivers/lvgl/tests/src/lv_test_init.o 

C_DEPS += \
./Drivers/lvgl/tests/src/lv_test_helpers.d \
./Drivers/lvgl/tests/src/lv_test_indev.d \
./Drivers/lvgl/tests/src/lv_test_init.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/tests/src/%.o Drivers/lvgl/tests/src/%.su Drivers/lvgl/tests/src/%.cyclo: ../Drivers/lvgl/tests/src/%.c Drivers/lvgl/tests/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/Drivers/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-tests-2f-src

clean-Drivers-2f-lvgl-2f-tests-2f-src:
	-$(RM) ./Drivers/lvgl/tests/src/lv_test_helpers.cyclo ./Drivers/lvgl/tests/src/lv_test_helpers.d ./Drivers/lvgl/tests/src/lv_test_helpers.o ./Drivers/lvgl/tests/src/lv_test_helpers.su ./Drivers/lvgl/tests/src/lv_test_indev.cyclo ./Drivers/lvgl/tests/src/lv_test_indev.d ./Drivers/lvgl/tests/src/lv_test_indev.o ./Drivers/lvgl/tests/src/lv_test_indev.su ./Drivers/lvgl/tests/src/lv_test_init.cyclo ./Drivers/lvgl/tests/src/lv_test_init.d ./Drivers/lvgl/tests/src/lv_test_init.o ./Drivers/lvgl/tests/src/lv_test_init.su

.PHONY: clean-Drivers-2f-lvgl-2f-tests-2f-src

