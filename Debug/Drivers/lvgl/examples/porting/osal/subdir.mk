################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/porting/osal/lv_example_osal.c 

OBJS += \
./Drivers/lvgl/examples/porting/osal/lv_example_osal.o 

C_DEPS += \
./Drivers/lvgl/examples/porting/osal/lv_example_osal.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/porting/osal/%.o Drivers/lvgl/examples/porting/osal/%.su Drivers/lvgl/examples/porting/osal/%.cyclo: ../Drivers/lvgl/examples/porting/osal/%.c Drivers/lvgl/examples/porting/osal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/Drivers/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-porting-2f-osal

clean-Drivers-2f-lvgl-2f-examples-2f-porting-2f-osal:
	-$(RM) ./Drivers/lvgl/examples/porting/osal/lv_example_osal.cyclo ./Drivers/lvgl/examples/porting/osal/lv_example_osal.d ./Drivers/lvgl/examples/porting/osal/lv_example_osal.o ./Drivers/lvgl/examples/porting/osal/lv_example_osal.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-porting-2f-osal

