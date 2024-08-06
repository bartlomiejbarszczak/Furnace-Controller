################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/sw/blend/lv_draw_sw_blend.c \
../lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.c \
../lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.c \
../lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.c \
../lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.c \
../lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.c \
../lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.c 

OBJS += \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend.o \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.o \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.o \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.o \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.o \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.o \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.o 

C_DEPS += \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend.d \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.d \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.d \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.d \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.d \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.d \
./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sw/blend/%.o lvgl/src/draw/sw/blend/%.su lvgl/src/draw/sw/blend/%.cyclo: ../lvgl/src/draw/sw/blend/%.c lvgl/src/draw/sw/blend/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-draw-2f-sw-2f-blend

clean-lvgl-2f-src-2f-draw-2f-sw-2f-blend:
	-$(RM) ./lvgl/src/draw/sw/blend/lv_draw_sw_blend.cyclo ./lvgl/src/draw/sw/blend/lv_draw_sw_blend.d ./lvgl/src/draw/sw/blend/lv_draw_sw_blend.o ./lvgl/src/draw/sw/blend/lv_draw_sw_blend.su ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.cyclo ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.d ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.o ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_al88.su ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.cyclo ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.d ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.o ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.su ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.cyclo ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.d ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.o ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_i1.su ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.cyclo ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.d ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.o ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_l8.su ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.cyclo ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.d ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.o ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.su ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.cyclo ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.d ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.o ./lvgl/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.su

.PHONY: clean-lvgl-2f-src-2f-draw-2f-sw-2f-blend

