################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Data/Face.cpp \
../src/Data/ListFace.cpp 

OBJS += \
./src/Data/Face.o \
./src/Data/ListFace.o 

CPP_DEPS += \
./src/Data/Face.d \
./src/Data/ListFace.d 


# Each subdirectory must supply rules for building sources it contributes
src/Data/%.o: ../src/Data/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


