################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Sensor.c \
../src/cr_startup_lpc17.c \
../src/main.c 

OBJS += \
./src/Sensor.o \
./src/cr_startup_lpc17.o \
./src/main.o 

C_DEPS += \
./src/Sensor.d \
./src/cr_startup_lpc17.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__USE_CMSIS=CMSISv1p30_LPC17xx -D__CODE_RED -D__NEWLIB__ -I"C:\Users\MarcosRubioJunior\Documents\LPCXpresso_8.2.2_650\workspace\Lib_CMSISv1p30_LPC17xx\inc" -I"C:\Users\MarcosRubioJunior\Documents\LPCXpresso_8.2.2_650\workspace\Lib_EaBaseBoard\inc" -I"C:\Users\MarcosRubioJunior\Documents\LPCXpresso_8.2.2_650\workspace\Lib_MCU\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


