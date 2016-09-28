################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/Assertion.cpp \
../lib/CBinarySemaphore.cpp \
../lib/CCountingSemaphore.cpp \
../lib/CMessage.cpp \
../lib/CMutex.cpp 

OBJS += \
./lib/Assertion.o \
./lib/CBinarySemaphore.o \
./lib/CCountingSemaphore.o \
./lib/CMessage.o \
./lib/CMutex.o 

CPP_DEPS += \
./lib/Assertion.d \
./lib/CBinarySemaphore.d \
./lib/CCountingSemaphore.d \
./lib/CMessage.d \
./lib/CMutex.d 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/CuBa_FW/lib" -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/CuBa_FW/TimerTask" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


