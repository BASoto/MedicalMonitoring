################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/WorkerThread/SensorWorker.cpp 

OBJS += \
./src/WorkerThread/SensorWorker.o 

CPP_DEPS += \
./src/WorkerThread/SensorWorker.d 


# Each subdirectory must supply rules for building sources it contributes
src/WorkerThread/%.o: ../src/WorkerThread/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	arm-linux-gnueabihf-g++ -I/usr/include/libusb-1.0 -I/usr/arm-linux-gnueabihf/include/c++/4.6.3 -I/home/brydev/ARM_Dependencies/exodriver/liblabjackusb -I/home/brydev/ARM_Dependencies/exodriver/examples/U3 -O3 -Wall -c -fmessage-length=0 -mcpu='cortex-a8' `pkg-config --libs libusb-1.0` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


