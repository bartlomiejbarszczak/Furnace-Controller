################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/libs/lodepng/lodepng.c \
../Drivers/lvgl/src/libs/lodepng/lv_lodepng.c 

OBJS += \
./Drivers/lvgl/src/libs/lodepng/lodepng.o \
./Drivers/lvgl/src/libs/lodepng/lv_lodepng.o 

C_DEPS += \
./Drivers/lvgl/src/libs/lodepng/lodepng.d \
./Drivers/lvgl/src/libs/lodepng/lv_lodepng.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/libs/lodepng/%.o Drivers/lvgl/src/libs/lodepng/%.su Drivers/lvgl/src/libs/lodepng/%.cyclo: ../Drivers/lvgl/src/libs/lodepng/%.c Drivers/lvgl/src/libs/lodepng/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/Drivers/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-lodepng

clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-lodepng:
	-$(RM) ./Drivers/lvgl/src/libs/lodepng/lodepng.cyclo ./Drivers/lvgl/src/libs/lodepng/lodepng.d ./Drivers/lvgl/src/libs/lodepng/lodepng.o ./Drivers/lvgl/src/libs/lodepng/lodepng.su ./Drivers/lvgl/src/libs/lodepng/lv_lodepng.cyclo ./Drivers/lvgl/src/libs/lodepng/lv_lodepng.d ./Drivers/lvgl/src/libs/lodepng/lv_lodepng.o ./Drivers/lvgl/src/libs/lodepng/lv_lodepng.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-lodepng

