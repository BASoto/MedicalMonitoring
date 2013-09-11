################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Initialization/Initializer.cpp 

OBJS += \
./src/Initialization/Initializer.o 

CPP_DEPS += \
./src/Initialization/Initializer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Initialization/%.o: ../src/Initialization/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/brydev/Documents/exodriver-master/examples/U3 -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


