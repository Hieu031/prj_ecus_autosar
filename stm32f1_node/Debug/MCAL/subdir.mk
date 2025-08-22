################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Can.c \
../MCAL/Dio.c 

OBJS += \
./MCAL/Can.o \
./MCAL/Dio.o 

C_DEPS += \
./MCAL/Can.d \
./MCAL/Dio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/stm32f1_node/Config" -I"D:/Workspace/stm32f1_node/EcuA" -I"D:/Workspace/stm32f1_node/MCAL" -I"D:/Workspace/stm32f1_node/RTE" -I"D:/Workspace/stm32f1_node/Services" -I"D:/Workspace/stm32f1_node/SWC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/Can.cyclo ./MCAL/Can.d ./MCAL/Can.o ./MCAL/Can.su ./MCAL/Dio.cyclo ./MCAL/Dio.d ./MCAL/Dio.o ./MCAL/Dio.su

.PHONY: clean-MCAL

