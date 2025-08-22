################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTE/RTE_TempHum.c 

OBJS += \
./RTE/RTE_TempHum.o 

C_DEPS += \
./RTE/RTE_TempHum.d 


# Each subdirectory must supply rules for building sources it contributes
RTE/%.o RTE/%.su RTE/%.cyclo: ../RTE/%.c RTE/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/test_sht31_lcd_i2c/Application" -I"D:/Workspace/test_sht31_lcd_i2c/ECU_Abstraction" -I"D:/Workspace/test_sht31_lcd_i2c/MCAL" -I"D:/Workspace/test_sht31_lcd_i2c/RTE" -I"D:/Workspace/test_sht31_lcd_i2c/Service" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-RTE

clean-RTE:
	-$(RM) ./RTE/RTE_TempHum.cyclo ./RTE/RTE_TempHum.d ./RTE/RTE_TempHum.o ./RTE/RTE_TempHum.su

.PHONY: clean-RTE

