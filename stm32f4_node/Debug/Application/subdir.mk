################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/SWC_Comm.c \
../Application/SWC_Display.c \
../Application/SWC_Scheduler.c \
../Application/SWC_Sensor.c 

OBJS += \
./Application/SWC_Comm.o \
./Application/SWC_Display.o \
./Application/SWC_Scheduler.o \
./Application/SWC_Sensor.o 

C_DEPS += \
./Application/SWC_Comm.d \
./Application/SWC_Display.d \
./Application/SWC_Scheduler.d \
./Application/SWC_Sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o Application/%.su Application/%.cyclo: ../Application/%.c Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Mcal" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/ECual" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Service" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/RTE" -I"D:/Workspace/prj_ecus_autosar/stm32f4_node/Application" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application

clean-Application:
	-$(RM) ./Application/SWC_Comm.cyclo ./Application/SWC_Comm.d ./Application/SWC_Comm.o ./Application/SWC_Comm.su ./Application/SWC_Display.cyclo ./Application/SWC_Display.d ./Application/SWC_Display.o ./Application/SWC_Display.su ./Application/SWC_Scheduler.cyclo ./Application/SWC_Scheduler.d ./Application/SWC_Scheduler.o ./Application/SWC_Scheduler.su ./Application/SWC_Sensor.cyclo ./Application/SWC_Sensor.d ./Application/SWC_Sensor.o ./Application/SWC_Sensor.su

.PHONY: clean-Application

