################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTE/Rte.c 

OBJS += \
./RTE/Rte.o 

C_DEPS += \
./RTE/Rte.d 


# Each subdirectory must supply rules for building sources it contributes
RTE/%.o RTE/%.su RTE/%.cyclo: ../RTE/%.c RTE/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/stm32f1_node/Config" -I"D:/Workspace/stm32f1_node/EcuA" -I"D:/Workspace/stm32f1_node/MCAL" -I"D:/Workspace/stm32f1_node/RTE" -I"D:/Workspace/stm32f1_node/Services" -I"D:/Workspace/stm32f1_node/SWC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-RTE

clean-RTE:
	-$(RM) ./RTE/Rte.cyclo ./RTE/Rte.d ./RTE/Rte.o ./RTE/Rte.su

.PHONY: clean-RTE

