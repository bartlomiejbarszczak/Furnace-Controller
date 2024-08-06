################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/label/lv_example_label_1.c \
../lvgl/examples/widgets/label/lv_example_label_2.c \
../lvgl/examples/widgets/label/lv_example_label_3.c \
../lvgl/examples/widgets/label/lv_example_label_4.c \
../lvgl/examples/widgets/label/lv_example_label_5.c 

OBJS += \
./lvgl/examples/widgets/label/lv_example_label_1.o \
./lvgl/examples/widgets/label/lv_example_label_2.o \
./lvgl/examples/widgets/label/lv_example_label_3.o \
./lvgl/examples/widgets/label/lv_example_label_4.o \
./lvgl/examples/widgets/label/lv_example_label_5.o 

C_DEPS += \
./lvgl/examples/widgets/label/lv_example_label_1.d \
./lvgl/examples/widgets/label/lv_example_label_2.d \
./lvgl/examples/widgets/label/lv_example_label_3.d \
./lvgl/examples/widgets/label/lv_example_label_4.d \
./lvgl/examples/widgets/label/lv_example_label_5.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/label/%.o lvgl/examples/widgets/label/%.su lvgl/examples/widgets/label/%.cyclo: ../lvgl/examples/widgets/label/%.c lvgl/examples/widgets/label/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-label

clean-lvgl-2f-examples-2f-widgets-2f-label:
	-$(RM) ./lvgl/examples/widgets/label/lv_example_label_1.cyclo ./lvgl/examples/widgets/label/lv_example_label_1.d ./lvgl/examples/widgets/label/lv_example_label_1.o ./lvgl/examples/widgets/label/lv_example_label_1.su ./lvgl/examples/widgets/label/lv_example_label_2.cyclo ./lvgl/examples/widgets/label/lv_example_label_2.d ./lvgl/examples/widgets/label/lv_example_label_2.o ./lvgl/examples/widgets/label/lv_example_label_2.su ./lvgl/examples/widgets/label/lv_example_label_3.cyclo ./lvgl/examples/widgets/label/lv_example_label_3.d ./lvgl/examples/widgets/label/lv_example_label_3.o ./lvgl/examples/widgets/label/lv_example_label_3.su ./lvgl/examples/widgets/label/lv_example_label_4.cyclo ./lvgl/examples/widgets/label/lv_example_label_4.d ./lvgl/examples/widgets/label/lv_example_label_4.o ./lvgl/examples/widgets/label/lv_example_label_4.su ./lvgl/examples/widgets/label/lv_example_label_5.cyclo ./lvgl/examples/widgets/label/lv_example_label_5.d ./lvgl/examples/widgets/label/lv_example_label_5.o ./lvgl/examples/widgets/label/lv_example_label_5.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-label

