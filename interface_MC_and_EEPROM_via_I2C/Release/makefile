################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := interface_MC_and_EEPROM_via_I2C
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
interface_MC_and_EEPROM_via_I2C.lss \

FLASH_IMAGE += \
interface_MC_and_EEPROM_via_I2C.hex \

EEPROM_IMAGE += \
interface_MC_and_EEPROM_via_I2C.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: interface_MC_and_EEPROM_via_I2C.elf secondary-outputs

# Tool invocations
interface_MC_and_EEPROM_via_I2C.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,interface_MC_and_EEPROM_via_I2C.map -mmcu=atmega32 -o "interface_MC_and_EEPROM_via_I2C.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

interface_MC_and_EEPROM_via_I2C.lss: interface_MC_and_EEPROM_via_I2C.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S interface_MC_and_EEPROM_via_I2C.elf  >"interface_MC_and_EEPROM_via_I2C.lss"
	@echo 'Finished building: $@'
	@echo ' '

interface_MC_and_EEPROM_via_I2C.hex: interface_MC_and_EEPROM_via_I2C.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex interface_MC_and_EEPROM_via_I2C.elf  "interface_MC_and_EEPROM_via_I2C.hex"
	@echo 'Finished building: $@'
	@echo ' '

interface_MC_and_EEPROM_via_I2C.eep: interface_MC_and_EEPROM_via_I2C.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex interface_MC_and_EEPROM_via_I2C.elf  "interface_MC_and_EEPROM_via_I2C.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: interface_MC_and_EEPROM_via_I2C.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 interface_MC_and_EEPROM_via_I2C.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) interface_MC_and_EEPROM_via_I2C.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
