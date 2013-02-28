################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Account.cpp \
../src/AuxiliaryTransaction.cpp \
../src/Entry.cpp \
../src/EventTransaction.cpp \
../src/FileIO.cpp \
../src/Main.cpp \
../src/Refund.cpp \
../src/Ticket.cpp \
../src/Transaction.cpp 

OBJS += \
./src/Account.o \
./src/AuxiliaryTransaction.o \
./src/Entry.o \
./src/EventTransaction.o \
./src/FileIO.o \
./src/Main.o \
./src/Refund.o \
./src/Ticket.o \
./src/Transaction.o 

CPP_DEPS += \
./src/Account.d \
./src/AuxiliaryTransaction.d \
./src/Entry.d \
./src/EventTransaction.d \
./src/FileIO.d \
./src/Main.d \
./src/Refund.d \
./src/Ticket.d \
./src/Transaction.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


