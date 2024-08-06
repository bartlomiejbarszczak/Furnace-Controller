################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/lottie/lv_example_lottie_1.c \
../lvgl/examples/widgets/lottie/lv_example_lottie_2.c \
../lvgl/examples/widgets/lottie/lv_example_lottie_approve.c 

OBJS += \
./lvgl/examples/widgets/lottie/lv_example_lottie_1.o \
./lvgl/examples/widgets/lottie/lv_example_lottie_2.o \
./lvgl/examples/widgets/lottie/lv_example_lottie_approve.o 

C_DEPS += \
./lvgl/examples/widgets/lottie/lv_example_lottie_1.d \
./lvgl/examples/widgets/lottie/lv_example_lottie_2.d \
./lvgl/examples/widgets/lottie/lv_example_lottie_approve.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/lottie/%.o lvgl/examples/widgets/lottie/%.su lvgl/examples/widgets/lottie/%.cyclo: ../lvgl/examples/widgets/lottie/%.c lvgl/examples/widgets/lottie/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-lottie

clean-lvgl-2f-examples-2f-widgets-2f-lottie:
	-$(RM) ./lvgl/examples/widgets/lottie/lv_example_lottie_1.cyclo ./lvgl/examples/widgets/lottie/lv_example_lottie_1.d ./lvgl/examples/widgets/lottie/lv_example_lottie_1.o ./lvgl/examples/widgets/lottie/lv_example_lottie_1.su ./lvgl/examples/widgets/lottie/lv_example_lottie_2.cyclo ./lvgl/examples/widgets/lottie/lv_example_lottie_2.d ./lvgl/examples/widgets/lottie/lv_example_lottie_2.o ./lvgl/examples/widgets/lottie/lv_example_lottie_2.su ./lvgl/examples/widgets/lottie/lv_example_lottie_approve.cyclo ./lvgl/examples/widgets/lottie/lv_example_lottie_approve.d ./lvgl/examples/widgets/lottie/lv_example_lottie_approve.o ./lvgl/examples/widgets/lottie/lv_example_lottie_approve.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-lottie

