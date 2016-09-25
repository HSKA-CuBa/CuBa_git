################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ControlComponent/CControlComponent.cpp 

OBJS += \
./ControlComponent/CControlComponent.o 

CPP_DEPS += \
./ControlComponent/CControlComponent.d 


# Each subdirectory must supply rules for building sources it contributes
ControlComponent/%.o: ../ControlComponent/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I"/home/michael/Desktop/CuBa_SW_V1/DoublePuffer/lib" -I"/home/michael/Desktop/CuBa_SW_V1/DoublePuffer/CommComponent" -I"/home/michael/Desktop/CuBa_SW_V1/DoublePuffer/TimerTask" -I"/home/michael/Desktop/CuBa_SW_V1/DoublePuffer/ControlComponent" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


