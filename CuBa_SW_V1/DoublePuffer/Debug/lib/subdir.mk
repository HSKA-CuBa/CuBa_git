################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/AComponentBase.cpp \
../lib/Assertion.cpp \
../lib/CBinarySemaphore.cpp \
../lib/CContainer.cpp \
../lib/CCountingSemaphore.cpp \
../lib/CDoubleBuffer.cpp \
../lib/CMessage.cpp \
../lib/CMutex.cpp \
../lib/CProxy.cpp 

OBJS += \
./lib/AComponentBase.o \
./lib/Assertion.o \
./lib/CBinarySemaphore.o \
./lib/CContainer.o \
./lib/CCountingSemaphore.o \
./lib/CDoubleBuffer.o \
./lib/CMessage.o \
./lib/CMutex.o \
./lib/CProxy.o 

CPP_DEPS += \
./lib/AComponentBase.d \
./lib/Assertion.d \
./lib/CBinarySemaphore.d \
./lib/CContainer.d \
./lib/CCountingSemaphore.d \
./lib/CDoubleBuffer.d \
./lib/CMessage.d \
./lib/CMutex.d \
./lib/CProxy.d 


# Each subdirectory must supply rules for building sources it contributes
lib/%.o: ../lib/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/DoublePuffer/lib" -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/DoublePuffer/CommComponent" -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/DoublePuffer/TimerTask" -I"/home/michael/Desktop/CuBa_git/CuBa_SW_V1/DoublePuffer/ControlComponent" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


