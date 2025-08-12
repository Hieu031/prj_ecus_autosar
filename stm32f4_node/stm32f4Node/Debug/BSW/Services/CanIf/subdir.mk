################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Services/CanIf/CanIf.c 

OBJS += \
./BSW/Services/CanIf/CanIf.o 

C_DEPS += \
./BSW/Services/CanIf/CanIf.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/Services/CanIf/%.o BSW/Services/CanIf/%.su BSW/Services/CanIf/%.cyclo: ../BSW/Services/CanIf/%.c BSW/Services/CanIf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/stm32f4Node/Core/Inc" -I"D:/Workspace/stm32f4Node/RTE" -I"D:/Workspace/stm32f4Node/Application" -I"D:/Workspace/stm32f4Node/Application/SWC_Comm" -I"D:/Workspace/stm32f4Node/Application/SWC_Display" -I"D:/Workspace/stm32f4Node/Application/SWC_Sensor" -I"D:/Workspace/stm32f4Node/BSW/MCAL" -I"D:/Workspace/stm32f4Node/BSW/ECUAL/DHT22" -I"D:/Workspace/stm32f4Node/BSW/ECUAL/LCD_I2C" -I"D:/Workspace/stm32f4Node/BSW/Services/CanIf" -I"D:/Workspace/stm32f4Node/BSW/Services/Comm" -I"D:/Workspace/stm32f4Node/BSW/Services/Det" -I"D:/Workspace/stm32f4Node/BSW/Services/UartIf" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSW-2f-Services-2f-CanIf

clean-BSW-2f-Services-2f-CanIf:
	-$(RM) ./BSW/Services/CanIf/CanIf.cyclo ./BSW/Services/CanIf/CanIf.d ./BSW/Services/CanIf/CanIf.o ./BSW/Services/CanIf/CanIf.su

.PHONY: clean-BSW-2f-Services-2f-CanIf

