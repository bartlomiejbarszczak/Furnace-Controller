################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/others/file_explorer/lv_example_file_explorer_1.c \
../lvgl/examples/others/file_explorer/lv_example_file_explorer_2.c \
../lvgl/examples/others/file_explorer/lv_example_file_explorer_3.c 

OBJS += \
./lvgl/examples/others/file_explorer/lv_example_file_explorer_1.o \
./lvgl/examples/others/file_explorer/lv_example_file_explorer_2.o \
./lvgl/examples/others/file_explorer/lv_example_file_explorer_3.o 

C_DEPS += \
./lvgl/examples/others/file_explorer/lv_example_file_explorer_1.d \
./lvgl/examples/others/file_explorer/lv_example_file_explorer_2.d \
./lvgl/examples/others/file_explorer/lv_example_file_explorer_3.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/others/file_explorer/%.o lvgl/examples/others/file_explorer/%.su lvgl/examples/others/file_explorer/%.cyclo: ../lvgl/examples/others/file_explorer/%.c lvgl/examples/others/file_explorer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-others-2f-file_explorer

clean-lvgl-2f-examples-2f-others-2f-file_explorer:
	-$(RM) ./lvgl/examples/others/file_explorer/lv_example_file_explorer_1.cyclo ./lvgl/examples/others/file_explorer/lv_example_file_explorer_1.d ./lvgl/examples/others/file_explorer/lv_example_file_explorer_1.o ./lvgl/examples/others/file_explorer/lv_example_file_explorer_1.su ./lvgl/examples/others/file_explorer/lv_example_file_explorer_2.cyclo ./lvgl/examples/others/file_explorer/lv_example_file_explorer_2.d ./lvgl/examples/others/file_explorer/lv_example_file_explorer_2.o ./lvgl/examples/others/file_explorer/lv_example_file_explorer_2.su ./lvgl/examples/others/file_explorer/lv_example_file_explorer_3.cyclo ./lvgl/examples/others/file_explorer/lv_example_file_explorer_3.d ./lvgl/examples/others/file_explorer/lv_example_file_explorer_3.o ./lvgl/examples/others/file_explorer/lv_example_file_explorer_3.su

.PHONY: clean-lvgl-2f-examples-2f-others-2f-file_explorer

