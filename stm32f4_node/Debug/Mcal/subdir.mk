################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/Can.c \
../Mcal/Dio.c \
../Mcal/I2c.c \
../Mcal/Uart.c 

OBJS += \
./Mcal/Can.o \
./Mcal/Dio.o \
./Mcal/I2c.o \
./Mcal/Uart.o 

C_DEPS += \
./Mcal/Can.d \
./Mcal/Dio.d \
./Mcal/I2c.d \
./Mcal/Uart.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/%.o Mcal/%.su Mcal/%.cyclo: ../Mcal/%.c Mcal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Mcal" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/ECual" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Service" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/RTE" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Application" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Mcal

clean-Mcal:
	-$(RM) ./Mcal/Can.cyclo ./Mcal/Can.d ./Mcal/Can.o ./Mcal/Can.su ./Mcal/Dio.cyclo ./Mcal/Dio.d ./Mcal/Dio.o ./Mcal/Dio.su ./Mcal/I2c.cyclo ./Mcal/I2c.d ./Mcal/I2c.o ./Mcal/I2c.su ./Mcal/Uart.cyclo ./Mcal/Uart.d ./Mcal/Uart.o ./Mcal/Uart.su

.PHONY: clean-Mcal

