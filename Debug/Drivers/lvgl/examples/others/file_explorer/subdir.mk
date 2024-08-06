################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_1.c \
../Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_2.c \
../Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_3.c 

OBJS += \
./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_1.o \
./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_2.o \
./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_3.o 

C_DEPS += \
./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_1.d \
./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_2.d \
./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_3.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/others/file_explorer/%.o Drivers/lvgl/examples/others/file_explorer/%.su Drivers/lvgl/examples/others/file_explorer/%.cyclo: ../Drivers/lvgl/examples/others/file_explorer/%.c Drivers/lvgl/examples/others/file_explorer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/Drivers/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-others-2f-file_explorer

clean-Drivers-2f-lvgl-2f-examples-2f-others-2f-file_explorer:
	-$(RM) ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_1.cyclo ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_1.d ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_1.o ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_1.su ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_2.cyclo ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_2.d ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_2.o ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_2.su ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_3.cyclo ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_3.d ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_3.o ./Drivers/lvgl/examples/others/file_explorer/lv_example_file_explorer_3.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-others-2f-file_explorer
