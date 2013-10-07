################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Labjack.cpp \
../src/MM-x86.cpp 

OBJS += \
./src/Labjack.o \
./src/MM-x86.o 

CPP_DEPS += \
./src/Labjack.d \
./src/MM-x86.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/home/brydev/workspace/MM-x86/src/DBConnector -I/home/brydev/Documents/exodriver-master/examples/U3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


