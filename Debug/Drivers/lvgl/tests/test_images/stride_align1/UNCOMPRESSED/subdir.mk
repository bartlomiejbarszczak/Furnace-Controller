################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A1_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A2_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A4_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A8_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_ARGB8888_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I1_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I2_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I4_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I8_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_L8_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565A8_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB888_NONE_align1.c \
../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_XRGB8888_NONE_align1.c 

OBJS += \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A1_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A2_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A4_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A8_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_ARGB8888_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I1_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I2_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I4_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I8_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_L8_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565A8_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB888_NONE_align1.o \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_XRGB8888_NONE_align1.o 

C_DEPS += \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A1_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A2_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A4_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A8_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_ARGB8888_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I1_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I2_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I4_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I8_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_L8_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565A8_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB888_NONE_align1.d \
./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_XRGB8888_NONE_align1.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/%.o Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/%.su Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/%.cyclo: ../Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/%.c Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/Drivers/lvgl" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-tests-2f-test_images-2f-stride_align1-2f-UNCOMPRESSED

clean-Drivers-2f-lvgl-2f-tests-2f-test_images-2f-stride_align1-2f-UNCOMPRESSED:
	-$(RM) ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A1_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A1_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A1_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A1_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A2_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A2_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A2_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A2_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A4_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A4_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A4_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A4_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A8_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A8_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A8_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_A8_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_ARGB8888_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_ARGB8888_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_ARGB8888_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_ARGB8888_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I1_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I1_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I1_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I1_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I2_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I2_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I2_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I2_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I4_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I4_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I4_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I4_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I8_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I8_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I8_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_I8_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_L8_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_L8_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_L8_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_L8_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565A8_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565A8_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565A8_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565A8_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB565_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB888_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB888_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB888_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_RGB888_NONE_align1.su ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_XRGB8888_NONE_align1.cyclo ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_XRGB8888_NONE_align1.d ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_XRGB8888_NONE_align1.o ./Drivers/lvgl/tests/test_images/stride_align1/UNCOMPRESSED/test_XRGB8888_NONE_align1.su

.PHONY: clean-Drivers-2f-lvgl-2f-tests-2f-test_images-2f-stride_align1-2f-UNCOMPRESSED

