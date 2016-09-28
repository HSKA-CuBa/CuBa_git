################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TimerTask/STimer.cpp 

OBJS += \
./TimerTask/STimer.o 

CPP_DEPS += \
./TimerTask/STimer.d 


# Each subdirectory must supply rules for building sources it contributes
TimerTask/%.o: ../TimerTask/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/CuBa_FW/lib" -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/CuBa_FW/TimerTask" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


