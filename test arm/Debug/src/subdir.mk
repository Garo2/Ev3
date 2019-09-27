################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/test\ arm.c 

OBJS += \
./src/test\ arm.o 

C_DEPS += \
./src/test\ arm.d 


# Each subdirectory must supply rules for building sources it contributes
src/test\ arm.o: ../src/test\ arm.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-linux-gnueabi-gcc -mcpu=arm9 -marm -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -IC:/ev3/API -MMD -MP -MF"src/test arm.d" -MT"src/test\ arm.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


