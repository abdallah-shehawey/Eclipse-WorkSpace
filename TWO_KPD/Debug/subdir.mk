################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_prog.c \
../DIO_prog.c \
../KPD1_prog.c \
../KPD2_prog.c \
../main.c 

OBJS += \
./CLCD_prog.o \
./DIO_prog.o \
./KPD1_prog.o \
./KPD2_prog.o \
./main.o 

C_DEPS += \
./CLCD_prog.d \
./DIO_prog.d \
./KPD1_prog.d \
./KPD2_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


