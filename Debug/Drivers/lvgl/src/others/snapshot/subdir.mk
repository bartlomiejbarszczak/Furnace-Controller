################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/others/snapshot/lv_snapshot.c 

OBJS += \
./Drivers/lvgl/src/others/snapshot/lv_snapshot.o 

C_DEPS += \
./Drivers/lvgl/src/others/snapshot/lv_snapshot.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/others/snapshot/%.o Drivers/lvgl/src/others/snapshot/%.su Drivers/lvgl/src/others/snapshot/%.cyclo: ../Drivers/lvgl/src/others/snapshot/%.c Drivers/lvgl/src/others/snapshot/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/Drivers/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-others-2f-snapshot

clean-Drivers-2f-lvgl-2f-src-2f-others-2f-snapshot:
	-$(RM) ./Drivers/lvgl/src/others/snapshot/lv_snapshot.cyclo ./Drivers/lvgl/src/others/snapshot/lv_snapshot.d ./Drivers/lvgl/src/others/snapshot/lv_snapshot.o ./Drivers/lvgl/src/others/snapshot/lv_snapshot.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-others-2f-snapshot

