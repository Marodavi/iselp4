################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -D__weak=__attribute__((weak)) -D__packed=__attribute__((__packed__)) -DUSE_HAL_DRIVER -DSTM32F051x8 -I"C:/STM32/workspace/ISEL4/Inc" -I"C:/STM32/workspace/ISEL4/Drivers/STM32F0xx_HAL_Driver/Inc" -I"C:/STM32/workspace/ISEL4/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"C:/STM32/workspace/ISEL4/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/STM32/workspace/ISEL4/Drivers/CMSIS/Include" -I"C:/STM32/workspace/ISEL4/Inc" -I"C:/STM32/workspace/ISEL4/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0" -I"C:/STM32/workspace/ISEL4/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/STM32/workspace/ISEL4/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


