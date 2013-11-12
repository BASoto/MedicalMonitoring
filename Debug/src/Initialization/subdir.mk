################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Initialization/Initializer.cpp \
../src/Initialization/adc.cpp 

OBJS += \
./src/Initialization/Initializer.o \
./src/Initialization/adc.o 

CPP_DEPS += \
./src/Initialization/Initializer.d \
./src/Initialization/adc.d 


# Each subdirectory must supply rules for building sources it contributes
src/Initialization/%.o: ../src/Initialization/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/home/brydev/workspace/MM-x86/src/DBConnector -I/home/brydev/Documents/exodriver-master/examples/U3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


