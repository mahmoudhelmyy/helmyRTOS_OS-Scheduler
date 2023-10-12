################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/Systick/Systick.c 

OBJS += \
./Src/MCAL/Systick/Systick.o 

C_DEPS += \
./Src/MCAL/Systick/Systick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/Systick/Systick.o: ../Src/MCAL/Systick/Systick.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/MCAL/Systick/Systick.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

