################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Dio/Dio.c 

OBJS += \
./MCAL/Dio/Dio.o 

C_DEPS += \
./MCAL/Dio/Dio.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Dio/%.o MCAL/Dio/%.su MCAL/Dio/%.cyclo: ../MCAL/Dio/%.c MCAL/Dio/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Workplace/Autosar_project_VTI/stm32f103_control_can/MCAL/Dio" -I"D:/Workplace/Autosar_project_VTI/stm32f103_control_can/MCAL/Can" -I"D:/Workplace/Autosar_project_VTI/stm32f103_control_can/ECUAL" -I"D:/Workplace/Autosar_project_VTI/stm32f103_control_can/Application" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL-2f-Dio

clean-MCAL-2f-Dio:
	-$(RM) ./MCAL/Dio/Dio.cyclo ./MCAL/Dio/Dio.d ./MCAL/Dio/Dio.o ./MCAL/Dio/Dio.su

.PHONY: clean-MCAL-2f-Dio

