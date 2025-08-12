################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Services/Comm/Com.c 

OBJS += \
./BSW/Services/Comm/Com.o 

C_DEPS += \
./BSW/Services/Comm/Com.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/Services/Comm/%.o BSW/Services/Comm/%.su BSW/Services/Comm/%.cyclo: ../BSW/Services/Comm/%.c BSW/Services/Comm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/stm32f4Node/Core/Inc" -I"D:/Workspace/stm32f4Node/RTE" -I"D:/Workspace/stm32f4Node/Application" -I"D:/Workspace/stm32f4Node/Application/SWC_Comm" -I"D:/Workspace/stm32f4Node/Application/SWC_Display" -I"D:/Workspace/stm32f4Node/Application/SWC_Sensor" -I"D:/Workspace/stm32f4Node/BSW/MCAL" -I"D:/Workspace/stm32f4Node/BSW/ECUAL/DHT22" -I"D:/Workspace/stm32f4Node/BSW/ECUAL/LCD_I2C" -I"D:/Workspace/stm32f4Node/BSW/Services/CanIf" -I"D:/Workspace/stm32f4Node/BSW/Services/Comm" -I"D:/Workspace/stm32f4Node/BSW/Services/Det" -I"D:/Workspace/stm32f4Node/BSW/Services/UartIf" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSW-2f-Services-2f-Comm

clean-BSW-2f-Services-2f-Comm:
	-$(RM) ./BSW/Services/Comm/Com.cyclo ./BSW/Services/Comm/Com.d ./BSW/Services/Comm/Com.o ./BSW/Services/Comm/Com.su

.PHONY: clean-BSW-2f-Services-2f-Comm

