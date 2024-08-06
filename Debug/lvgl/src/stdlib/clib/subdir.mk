################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/stdlib/clib/lv_mem_core_clib.c \
../lvgl/src/stdlib/clib/lv_sprintf_clib.c \
../lvgl/src/stdlib/clib/lv_string_clib.c 

OBJS += \
./lvgl/src/stdlib/clib/lv_mem_core_clib.o \
./lvgl/src/stdlib/clib/lv_sprintf_clib.o \
./lvgl/src/stdlib/clib/lv_string_clib.o 

C_DEPS += \
./lvgl/src/stdlib/clib/lv_mem_core_clib.d \
./lvgl/src/stdlib/clib/lv_sprintf_clib.d \
./lvgl/src/stdlib/clib/lv_string_clib.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/stdlib/clib/%.o lvgl/src/stdlib/clib/%.su lvgl/src/stdlib/clib/%.cyclo: ../lvgl/src/stdlib/clib/%.c lvgl/src/stdlib/clib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-stdlib-2f-clib

clean-lvgl-2f-src-2f-stdlib-2f-clib:
	-$(RM) ./lvgl/src/stdlib/clib/lv_mem_core_clib.cyclo ./lvgl/src/stdlib/clib/lv_mem_core_clib.d ./lvgl/src/stdlib/clib/lv_mem_core_clib.o ./lvgl/src/stdlib/clib/lv_mem_core_clib.su ./lvgl/src/stdlib/clib/lv_sprintf_clib.cyclo ./lvgl/src/stdlib/clib/lv_sprintf_clib.d ./lvgl/src/stdlib/clib/lv_sprintf_clib.o ./lvgl/src/stdlib/clib/lv_sprintf_clib.su ./lvgl/src/stdlib/clib/lv_string_clib.cyclo ./lvgl/src/stdlib/clib/lv_string_clib.d ./lvgl/src/stdlib/clib/lv_string_clib.o ./lvgl/src/stdlib/clib/lv_string_clib.su

.PHONY: clean-lvgl-2f-src-2f-stdlib-2f-clib

