################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Service/Com.c \
../Service/PduR.c 

OBJS += \
./Service/Com.o \
./Service/PduR.o 

C_DEPS += \
./Service/Com.d \
./Service/PduR.d 


# Each subdirectory must supply rules for building sources it contributes
Service/%.o Service/%.su Service/%.cyclo: ../Service/%.c Service/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Mcal" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/ECual" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Service" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/RTE" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Application" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Service

clean-Service:
	-$(RM) ./Service/Com.cyclo ./Service/Com.d ./Service/Com.o ./Service/Com.su ./Service/PduR.cyclo ./Service/PduR.d ./Service/PduR.o ./Service/PduR.su

.PHONY: clean-Service

