################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Labjack/U3/u3.c 

OBJS += \
./src/Labjack/U3/u3.o 

C_DEPS += \
./src/Labjack/U3/u3.d 


# Each subdirectory must supply rules for building sources it contributes
src/Labjack/U3/%.o: ../src/Labjack/U3/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabi-gcc -I/home/brydev/ARM_Dependencies/exodriver/liblabjackusb -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


