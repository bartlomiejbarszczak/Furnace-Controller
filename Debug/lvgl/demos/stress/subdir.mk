################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/stress/lv_demo_stress.c 

OBJS += \
./lvgl/demos/stress/lv_demo_stress.o 

C_DEPS += \
./lvgl/demos/stress/lv_demo_stress.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/stress/%.o lvgl/demos/stress/%.su lvgl/demos/stress/%.cyclo: ../lvgl/demos/stress/%.c lvgl/demos/stress/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-stress

clean-lvgl-2f-demos-2f-stress:
	-$(RM) ./lvgl/demos/stress/lv_demo_stress.cyclo ./lvgl/demos/stress/lv_demo_stress.d ./lvgl/demos/stress/lv_demo_stress.o ./lvgl/demos/stress/lv_demo_stress.su

.PHONY: clean-lvgl-2f-demos-2f-stress

