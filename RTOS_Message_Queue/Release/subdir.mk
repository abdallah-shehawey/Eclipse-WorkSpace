################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../LCD.c \
../event_groups.c \
../heap_2.c \
../keypad_driver.c \
../list.c \
../message\ Queue.c \
../port.c \
../queue.c \
../tasks.c 

OBJS += \
./DIO.o \
./LCD.o \
./event_groups.o \
./heap_2.o \
./keypad_driver.o \
./list.o \
./message\ Queue.o \
./port.o \
./queue.o \
./tasks.o 

C_DEPS += \
./DIO.d \
./LCD.d \
./event_groups.d \
./heap_2.d \
./keypad_driver.d \
./list.d \
./message\ Queue.d \
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

message\ Queue.o: ../message\ Queue.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"message Queue.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


