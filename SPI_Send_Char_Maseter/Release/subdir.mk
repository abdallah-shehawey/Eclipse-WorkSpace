################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../KPD_prog.c \
../SPI_prog.c \
../USART_prog.c \
../master.c 

OBJS += \
./DIO_prog.o \
./KPD_prog.o \
./SPI_prog.o \
./USART_prog.o \
./master.o 

C_DEPS += \
./DIO_prog.d \
./KPD_prog.d \
./SPI_prog.d \
./USART_prog.d \
./master.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


