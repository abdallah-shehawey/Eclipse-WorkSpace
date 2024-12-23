################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_driver.c \
../DIO.c \
../LCD.c \
../TempMeter_with_negative_degree.c 

OBJS += \
./ADC_driver.o \
./DIO.o \
./LCD.o \
./TempMeter_with_negative_degree.o 

C_DEPS += \
./ADC_driver.d \
./DIO.d \
./LCD.d \
./TempMeter_with_negative_degree.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


