################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTINT/EXTINT_Program.c 

OBJS += \
./MCAL/EXTINT/EXTINT_Program.o 

C_DEPS += \
./MCAL/EXTINT/EXTINT_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTINT/%.o: ../MCAL/EXTINT/%.c MCAL/EXTINT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\LIB" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\MCAL\DIO" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\MCAL\EXTINT" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\MCAL\GIE" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\MCAL\TMR0" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\HAL\LCD" -I"S:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\APP" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


