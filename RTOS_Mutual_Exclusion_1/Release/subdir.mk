################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../Mutual\ Exclusion\ 1.c \
../event_groups.c \
../heap_2.c \
../list.c \
../port.c \
../queue.c \
../tasks.c 

OBJS += \
./DIO.o \
./Mutual\ Exclusion\ 1.o \
./event_groups.o \
./heap_2.o \
./list.o \
./port.o \
./queue.o \
./tasks.o 

C_DEPS += \
./DIO.d \
./Mutual\ Exclusion\ 1.d \
./event_groups.d \
./heap_2.d \
./list.d \
./port.d \
./queue.d \
./tasks.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Mutual\ Exclusion\ 1.o: ../Mutual\ Exclusion\ 1.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"Mutual Exclusion 1.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


