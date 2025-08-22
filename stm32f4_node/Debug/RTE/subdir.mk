################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTE/Rte.c \
../RTE/Rte_Buffer.c 

OBJS += \
./RTE/Rte.o \
./RTE/Rte_Buffer.o 

C_DEPS += \
./RTE/Rte.d \
./RTE/Rte_Buffer.d 


# Each subdirectory must supply rules for building sources it contributes
RTE/%.o RTE/%.su RTE/%.cyclo: ../RTE/%.c RTE/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Mcal" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/ECual" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Service" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/RTE" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Application" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-RTE

clean-RTE:
	-$(RM) ./RTE/Rte.cyclo ./RTE/Rte.d ./RTE/Rte.o ./RTE/Rte.su ./RTE/Rte_Buffer.cyclo ./RTE/Rte_Buffer.d ./RTE/Rte_Buffer.o ./RTE/Rte_Buffer.su

.PHONY: clean-RTE

