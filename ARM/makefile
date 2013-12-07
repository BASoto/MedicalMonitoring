################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/WorkerThread/subdir.mk
-include src/Utils/subdir.mk
-include src/Labjack/subdir.mk
-include src/Initialization/subdir.mk
-include src/DBConnector/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MM-x86

# Tool invocations
MM-x86: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	arm-linux-gnueabihf-g++ -L/usr/lib/arm-linux-gnueabi -L/usr/arm-linux-gnueabihf/lib -L/home/brydev/ARM_Dependencies/exodriver/liblabjackusb -L/home/brydev/ARM_Dependencies -Wl,-rpath=/usr/lib/arm-linux-gnueabihf,-rpath=/lib,-rpath=/usr/lib -o "MM-x86" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) MM-x86
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
