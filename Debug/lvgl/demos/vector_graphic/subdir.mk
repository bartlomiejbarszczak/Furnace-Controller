################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/demos/vector_graphic/lv_demo_vector_graphic.c 

OBJS += \
./lvgl/demos/vector_graphic/lv_demo_vector_graphic.o 

C_DEPS += \
./lvgl/demos/vector_graphic/lv_demo_vector_graphic.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/demos/vector_graphic/%.o lvgl/demos/vector_graphic/%.su lvgl/demos/vector_graphic/%.cyclo: ../lvgl/demos/vector_graphic/%.c lvgl/demos/vector_graphic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-demos-2f-vector_graphic

clean-lvgl-2f-demos-2f-vector_graphic:
	-$(RM) ./lvgl/demos/vector_graphic/lv_demo_vector_graphic.cyclo ./lvgl/demos/vector_graphic/lv_demo_vector_graphic.d ./lvgl/demos/vector_graphic/lv_demo_vector_graphic.o ./lvgl/demos/vector_graphic/lv_demo_vector_graphic.su

.PHONY: clean-lvgl-2f-demos-2f-vector_graphic

