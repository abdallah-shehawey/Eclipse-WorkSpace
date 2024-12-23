################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC\ Motor\ with\ L293D.c 

OBJS += \
./DC\ Motor\ with\ L293D.o 

C_DEPS += \
./DC\ Motor\ with\ L293D.d 


# Each subdirectory must supply rules for building sources it contributes
DC\ Motor\ with\ L293D.o: ../DC\ Motor\ with\ L293D.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"DC Motor with L293D.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


