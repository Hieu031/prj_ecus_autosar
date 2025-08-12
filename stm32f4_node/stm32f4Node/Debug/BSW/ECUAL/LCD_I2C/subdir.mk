################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/ECUAL/LCD_I2C/Lcd_I2c.c 

OBJS += \
./BSW/ECUAL/LCD_I2C/Lcd_I2c.o 

C_DEPS += \
./BSW/ECUAL/LCD_I2C/Lcd_I2c.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/ECUAL/LCD_I2C/%.o BSW/ECUAL/LCD_I2C/%.su BSW/ECUAL/LCD_I2C/%.cyclo: ../BSW/ECUAL/LCD_I2C/%.c BSW/ECUAL/LCD_I2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/stm32f4Node/Core/Inc" -I"D:/Workspace/stm32f4Node/RTE" -I"D:/Workspace/stm32f4Node/Application" -I"D:/Workspace/stm32f4Node/Application/SWC_Comm" -I"D:/Workspace/stm32f4Node/Application/SWC_Display" -I"D:/Workspace/stm32f4Node/Application/SWC_Sensor" -I"D:/Workspace/stm32f4Node/BSW/MCAL" -I"D:/Workspace/stm32f4Node/BSW/ECUAL/DHT22" -I"D:/Workspace/stm32f4Node/BSW/ECUAL/LCD_I2C" -I"D:/Workspace/stm32f4Node/BSW/Services/CanIf" -I"D:/Workspace/stm32f4Node/BSW/Services/Comm" -I"D:/Workspace/stm32f4Node/BSW/Services/Det" -I"D:/Workspace/stm32f4Node/BSW/Services/UartIf" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSW-2f-ECUAL-2f-LCD_I2C

clean-BSW-2f-ECUAL-2f-LCD_I2C:
	-$(RM) ./BSW/ECUAL/LCD_I2C/Lcd_I2c.cyclo ./BSW/ECUAL/LCD_I2C/Lcd_I2c.d ./BSW/ECUAL/LCD_I2C/Lcd_I2c.o ./BSW/ECUAL/LCD_I2C/Lcd_I2c.su

.PHONY: clean-BSW-2f-ECUAL-2f-LCD_I2C

