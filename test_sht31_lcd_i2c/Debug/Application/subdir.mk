################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/App_TempHum.c 

OBJS += \
./Application/App_TempHum.o 

C_DEPS += \
./Application/App_TempHum.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o Application/%.su Application/%.cyclo: ../Application/%.c Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/test_sht31_lcd_i2c/Application" -I"D:/Workspace/test_sht31_lcd_i2c/ECU_Abstraction" -I"D:/Workspace/test_sht31_lcd_i2c/MCAL" -I"D:/Workspace/test_sht31_lcd_i2c/RTE" -I"D:/Workspace/test_sht31_lcd_i2c/Service" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/App_TempHum.cyclo ./Application/App_TempHum.d ./Application/App_TempHum.o ./Application/App_TempHum.su

.PHONY: clean-Application

