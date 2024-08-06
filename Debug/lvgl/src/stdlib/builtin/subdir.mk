################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/stdlib/builtin/lv_mem_core_builtin.c \
../lvgl/src/stdlib/builtin/lv_sprintf_builtin.c \
../lvgl/src/stdlib/builtin/lv_string_builtin.c \
../lvgl/src/stdlib/builtin/lv_tlsf.c 

OBJS += \
./lvgl/src/stdlib/builtin/lv_mem_core_builtin.o \
./lvgl/src/stdlib/builtin/lv_sprintf_builtin.o \
./lvgl/src/stdlib/builtin/lv_string_builtin.o \
./lvgl/src/stdlib/builtin/lv_tlsf.o 

C_DEPS += \
./lvgl/src/stdlib/builtin/lv_mem_core_builtin.d \
./lvgl/src/stdlib/builtin/lv_sprintf_builtin.d \
./lvgl/src/stdlib/builtin/lv_string_builtin.d \
./lvgl/src/stdlib/builtin/lv_tlsf.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/stdlib/builtin/%.o lvgl/src/stdlib/builtin/%.su lvgl/src/stdlib/builtin/%.cyclo: ../lvgl/src/stdlib/builtin/%.c lvgl/src/stdlib/builtin/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-stdlib-2f-builtin

clean-lvgl-2f-src-2f-stdlib-2f-builtin:
	-$(RM) ./lvgl/src/stdlib/builtin/lv_mem_core_builtin.cyclo ./lvgl/src/stdlib/builtin/lv_mem_core_builtin.d ./lvgl/src/stdlib/builtin/lv_mem_core_builtin.o ./lvgl/src/stdlib/builtin/lv_mem_core_builtin.su ./lvgl/src/stdlib/builtin/lv_sprintf_builtin.cyclo ./lvgl/src/stdlib/builtin/lv_sprintf_builtin.d ./lvgl/src/stdlib/builtin/lv_sprintf_builtin.o ./lvgl/src/stdlib/builtin/lv_sprintf_builtin.su ./lvgl/src/stdlib/builtin/lv_string_builtin.cyclo ./lvgl/src/stdlib/builtin/lv_string_builtin.d ./lvgl/src/stdlib/builtin/lv_string_builtin.o ./lvgl/src/stdlib/builtin/lv_string_builtin.su ./lvgl/src/stdlib/builtin/lv_tlsf.cyclo ./lvgl/src/stdlib/builtin/lv_tlsf.d ./lvgl/src/stdlib/builtin/lv_tlsf.o ./lvgl/src/stdlib/builtin/lv_tlsf.su

.PHONY: clean-lvgl-2f-src-2f-stdlib-2f-builtin

