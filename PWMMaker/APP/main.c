/*
 * main.c
 *
 *  Created on: September 18, 2024
 *      Author: ahmed
 */

#include"DIO_Interface.h"

#include"GIE_Interface.h"

#include"TIMER1_Interface.h"


int main(){

	//Timer1
	TIMER1_voidPwm1Init();

	TIMER1_voidPwm1SetTop();

	TIMER1_voidPwm1SetDutyCycle();

	TIMER1_voidPwm1Start();

	//Global Interrupt Enable
	GIE_Enable();

	while (1){

	}
	return 0;
}
