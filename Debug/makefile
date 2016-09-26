################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: projeto_Edielson.axf

# Tool invocations
projeto_Edielson.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\MarcosRubioJunior\Documents\LPCXpresso_8.2.2_650\workspace\Lib_CMSISv1p30_LPC17xx\Debug" -L"C:\Users\MarcosRubioJunior\Documents\LPCXpresso_8.2.2_650\workspace\Lib_EaBaseBoard\Debug" -L"C:\Users\MarcosRubioJunior\Documents\LPCXpresso_8.2.2_650\workspace\Lib_MCU\Debug" -Xlinker --gc-sections -Xlinker -Map=projeto_Edielson.map -mcpu=cortex-m3 -mthumb -T "projeto_Edielson_Debug.ld" -o "projeto_Edielson.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) projeto_Edielson.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size projeto_Edielson.axf; # arm-none-eabi-objdump -h -S projeto_Edielson.axf >projeto_Edielson.lss
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
