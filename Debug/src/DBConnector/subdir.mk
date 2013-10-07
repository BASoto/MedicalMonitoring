################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DBConnector/Database.cpp 

OBJS += \
./src/DBConnector/Database.o 

CPP_DEPS += \
./src/DBConnector/Database.d 


# Each subdirectory must supply rules for building sources it contributes
src/DBConnector/%.o: ../src/DBConnector/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include -I/home/brydev/workspace/MM-x86/src/DBConnector -I/home/brydev/Documents/exodriver-master/examples/U3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


