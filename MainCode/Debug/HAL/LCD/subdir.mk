################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/LCD_Program.c 

OBJS += \
./HAL/LCD/LCD_Program.o 

C_DEPS += \
./HAL/LCD/LCD_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/%.o: ../HAL/LCD/%.c HAL/LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\LIB" -I"D:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\MCAL\DIO" -I"D:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\MCAL\EXTINT" -I"D:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\MCAL\GIE" -I"D:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\MCAL\TMR0" -I"D:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\HAL\LCD" -I"D:\Courses\Programming\Embedded_Systems_Course\MyProjects\PWM-Drawer\MainCode\APP" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

