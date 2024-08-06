################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/drivers/glfw/lv_glfw_mouse.c \
../lvgl/src/drivers/glfw/lv_glfw_mouse_private.c \
../lvgl/src/drivers/glfw/lv_glfw_window.c \
../lvgl/src/drivers/glfw/lv_opengles_debug.c \
../lvgl/src/drivers/glfw/lv_opengles_driver.c 

OBJS += \
./lvgl/src/drivers/glfw/lv_glfw_mouse.o \
./lvgl/src/drivers/glfw/lv_glfw_mouse_private.o \
./lvgl/src/drivers/glfw/lv_glfw_window.o \
./lvgl/src/drivers/glfw/lv_opengles_debug.o \
./lvgl/src/drivers/glfw/lv_opengles_driver.o 

C_DEPS += \
./lvgl/src/drivers/glfw/lv_glfw_mouse.d \
./lvgl/src/drivers/glfw/lv_glfw_mouse_private.d \
./lvgl/src/drivers/glfw/lv_glfw_window.d \
./lvgl/src/drivers/glfw/lv_opengles_debug.d \
./lvgl/src/drivers/glfw/lv_opengles_driver.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/drivers/glfw/%.o lvgl/src/drivers/glfw/%.su lvgl/src/drivers/glfw/%.cyclo: ../lvgl/src/drivers/glfw/%.c lvgl/src/drivers/glfw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"D:/Studies/0myfiles/STM32L476/Controller/lvgl/src" -Oz -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-drivers-2f-glfw

clean-lvgl-2f-src-2f-drivers-2f-glfw:
	-$(RM) ./lvgl/src/drivers/glfw/lv_glfw_mouse.cyclo ./lvgl/src/drivers/glfw/lv_glfw_mouse.d ./lvgl/src/drivers/glfw/lv_glfw_mouse.o ./lvgl/src/drivers/glfw/lv_glfw_mouse.su ./lvgl/src/drivers/glfw/lv_glfw_mouse_private.cyclo ./lvgl/src/drivers/glfw/lv_glfw_mouse_private.d ./lvgl/src/drivers/glfw/lv_glfw_mouse_private.o ./lvgl/src/drivers/glfw/lv_glfw_mouse_private.su ./lvgl/src/drivers/glfw/lv_glfw_window.cyclo ./lvgl/src/drivers/glfw/lv_glfw_window.d ./lvgl/src/drivers/glfw/lv_glfw_window.o ./lvgl/src/drivers/glfw/lv_glfw_window.su ./lvgl/src/drivers/glfw/lv_opengles_debug.cyclo ./lvgl/src/drivers/glfw/lv_opengles_debug.d ./lvgl/src/drivers/glfw/lv_opengles_debug.o ./lvgl/src/drivers/glfw/lv_opengles_debug.su ./lvgl/src/drivers/glfw/lv_opengles_driver.cyclo ./lvgl/src/drivers/glfw/lv_opengles_driver.d ./lvgl/src/drivers/glfw/lv_opengles_driver.o ./lvgl/src/drivers/glfw/lv_opengles_driver.su

.PHONY: clean-lvgl-2f-src-2f-drivers-2f-glfw

