/*
 * main.c
 *
 *  Created on: September 18, 2024
 *      Author: ahmed
 */

#include"DIO_Interface.h"

#include"GIE_Interface.h"

#include"EXTINT_Interface.h"

#include"TMR0_Interface.h"

#include"LCD_Interface.h"

/*//PWM read using Timer0 and INT0

f32 Ttick = 0.004, TONTime=0; //ms
//u32 dis;
u32 OverFlowCounter=0, TimeOn=0;
u8 edge = RISING_EDGE;

void OverFlowFunction(){
	OverFlowCounter++;
}

void EXTINT_voidTriger(){
	//rising edge state
	if (edge==RISING_EDGE){

		TIMER0_VoidSetPreload(0);
		//TIMER0_start(TIMER0_DIV64);

		OverFlowCounter = 0;

		EXTINT_voidInit(EXT0_ID,FALLING_EDGE);

		edge = RISING_EDGE;

	}
	//falling edge state
	else if (edge==FALLING_EDGE){

		TIMER0_VoidStop();

		//TIMER0_start(TIMER0_STOP);
		//TimeOn = TIMER0_getCounts();

		//TONTime = Ttick*(TimeOn+(256*OverFlowCounter));
		//dis = 17 * TONTime;

		EXTINT_voidInit(EXT0_ID,RISING_EDGE);

		edge = FALLING_EDGE;
	}
}*/

int main(){

	/*u8 Rising[] = {
	   0b11111,
	   0b00000,
	   0b00000,
	   0b00000,
	   0b00000,
	   0b00000,
	   0b00000,
	   0b00000
	};

	u8 Falling [] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b11111
	};

	u8 StateChange [] = {
	    0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
		0b10000,
	    0b10000
	};

	//LCD

	u8 LCDLocation = 0;
*/
	LCD_voidInit();

	/*LCD_voidWriteSpecialCharToCGRAM(StateChange,1);

	LCD_voidWriteSpecialCharToCGRAM(Rising,2);

	LCD_voidWriteSpecialCharToCGRAM(Falling,3);*/

	//Timer0
	/*TIMER0_VoidInit();

	TIMER_voidSetCallBack(OverFlowFunction);

	TIMER0_VoidStart();*/

	//EXTINT0
	/*EXTINT_voidInit(EXT0_ID,RISING_EDGE);

	EXTINT_voidSetCallBack(EXTINT_voidTriger,EXT0_ID);

	GIE_Enable();*/

	while (1){

		//LCD_voidWriteData('H');
		/*if(edge==FALLING_EDGE){
			LCDLocation++;
			LCD_voidGoToXY(0,LCDLocation);
			LCD_voidDisplaySpecialChar(1);

			LCD_voidDisplaySpecialChar(2);


		}*/

	}
	return 0;
}
