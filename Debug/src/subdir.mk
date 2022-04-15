################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/calculos.c \
../src/input.c \
../src/tp_1_prototipo.c 

OBJS += \
./src/calculos.o \
./src/input.o \
./src/tp_1_prototipo.o 

C_DEPS += \
./src/calculos.d \
./src/input.d \
./src/tp_1_prototipo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


