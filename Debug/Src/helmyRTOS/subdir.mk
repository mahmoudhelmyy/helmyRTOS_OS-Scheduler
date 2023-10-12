################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/helmyRTOS/helmyRTOS.c 

OBJS += \
./Src/helmyRTOS/helmyRTOS.o 

C_DEPS += \
./Src/helmyRTOS/helmyRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Src/helmyRTOS/helmyRTOS.o: ../Src/helmyRTOS/helmyRTOS.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/helmyRTOS/helmyRTOS.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

