################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp 

OBJS += \
./main.o 

CPP_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/DoublePuffer/lib" -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/DoublePuffer/CommComponent" -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/DoublePuffer/TimerTask" -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/DoublePuffer/ControlComponent" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

