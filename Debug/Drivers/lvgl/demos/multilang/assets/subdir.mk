################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/demos/multilang/assets/img_multilang_like.c 

OBJS += \
./Drivers/lvgl/demos/multilang/assets/img_multilang_like.o 

C_DEPS += \
./Drivers/lvgl/demos/multilang/assets/img_multilang_like.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/demos/multilang/assets/%.o Drivers/lvgl/demos/multilang/assets/%.su Drivers/lvgl/demos/multilang/assets/%.cyclo: ../Drivers/lvgl/demos/multilang/assets/%.c Drivers/lvgl/demos/multilang/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/Drivers/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-demos-2f-multilang-2f-assets

clean-Drivers-2f-lvgl-2f-demos-2f-multilang-2f-assets:
	-$(RM) ./Drivers/lvgl/demos/multilang/assets/img_multilang_like.cyclo ./Drivers/lvgl/demos/multilang/assets/img_multilang_like.d ./Drivers/lvgl/demos/multilang/assets/img_multilang_like.o ./Drivers/lvgl/demos/multilang/assets/img_multilang_like.su

.PHONY: clean-Drivers-2f-lvgl-2f-demos-2f-multilang-2f-assets

