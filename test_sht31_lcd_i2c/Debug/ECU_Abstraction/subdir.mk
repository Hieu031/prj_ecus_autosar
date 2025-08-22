################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_Abstraction/LCD_Driver.c \
../ECU_Abstraction/SHT31_Driver.c 

OBJS += \
./ECU_Abstraction/LCD_Driver.o \
./ECU_Abstraction/SHT31_Driver.o 

C_DEPS += \
./ECU_Abstraction/LCD_Driver.d \
./ECU_Abstraction/SHT31_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_Abstraction/%.o ECU_Abstraction/%.su ECU_Abstraction/%.cyclo: ../ECU_Abstraction/%.c ECU_Abstraction/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/test_sht31_lcd_i2c/Application" -I"D:/Workspace/test_sht31_lcd_i2c/ECU_Abstraction" -I"D:/Workspace/test_sht31_lcd_i2c/MCAL" -I"D:/Workspace/test_sht31_lcd_i2c/RTE" -I"D:/Workspace/test_sht31_lcd_i2c/Service" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ECU_Abstraction

clean-ECU_Abstraction:
	-$(RM) ./ECU_Abstraction/LCD_Driver.cyclo ./ECU_Abstraction/LCD_Driver.d ./ECU_Abstraction/LCD_Driver.o ./ECU_Abstraction/LCD_Driver.su ./ECU_Abstraction/SHT31_Driver.cyclo ./ECU_Abstraction/SHT31_Driver.d ./ECU_Abstraction/SHT31_Driver.o ./ECU_Abstraction/SHT31_Driver.su

.PHONY: clean-ECU_Abstraction

