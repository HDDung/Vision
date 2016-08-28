################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Core/DataHandler.cpp \
../src/Core/FaceDetector.cpp \
../src/Core/FaceRecognition.cpp \
../src/Core/NewFaces.cpp 

OBJS += \
./src/Core/DataHandler.o \
./src/Core/FaceDetector.o \
./src/Core/FaceRecognition.o \
./src/Core/NewFaces.o 

CPP_DEPS += \
./src/Core/DataHandler.d \
./src/Core/FaceDetector.d \
./src/Core/FaceRecognition.d \
./src/Core/NewFaces.d 


# Each subdirectory must supply rules for building sources it contributes
src/Core/%.o: ../src/Core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


