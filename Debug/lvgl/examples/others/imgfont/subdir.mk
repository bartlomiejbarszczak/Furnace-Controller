################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/others/imgfont/lv_example_imgfont_1.c 

OBJS += \
./lvgl/examples/others/imgfont/lv_example_imgfont_1.o 

C_DEPS += \
./lvgl/examples/others/imgfont/lv_example_imgfont_1.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/others/imgfont/%.o lvgl/examples/others/imgfont/%.su lvgl/examples/others/imgfont/%.cyclo: ../lvgl/examples/others/imgfont/%.c lvgl/examples/others/imgfont/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-others-2f-imgfont

clean-lvgl-2f-examples-2f-others-2f-imgfont:
	-$(RM) ./lvgl/examples/others/imgfont/lv_example_imgfont_1.cyclo ./lvgl/examples/others/imgfont/lv_example_imgfont_1.d ./lvgl/examples/others/imgfont/lv_example_imgfont_1.o ./lvgl/examples/others/imgfont/lv_example_imgfont_1.su

.PHONY: clean-lvgl-2f-examples-2f-others-2f-imgfont
