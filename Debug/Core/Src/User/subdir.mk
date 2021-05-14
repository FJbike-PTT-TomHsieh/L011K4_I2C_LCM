################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/User/I2C_Task.c \
../Core/Src/User/LCM_Task.c 

OBJS += \
./Core/Src/User/I2C_Task.o \
./Core/Src/User/LCM_Task.o 

C_DEPS += \
./Core/Src/User/I2C_Task.d \
./Core/Src/User/LCM_Task.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/User/I2C_Task.o: ../Core/Src/User/I2C_Task.c Core/Src/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L011xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Core/Inc/User -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/User/I2C_Task.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/User/LCM_Task.o: ../Core/Src/User/LCM_Task.c Core/Src/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L011xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Core/Inc/User -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/User/LCM_Task.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

