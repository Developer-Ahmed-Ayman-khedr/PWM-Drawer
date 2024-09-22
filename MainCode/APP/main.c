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

/***********************************************************************************/
//LCD CGRAM Locations
#define HIGH_ADDRESS 		(u8)1

#define LOW_ADDRESS			(u8)2

#define FALLING_ADDRESS		(u8)3

#define RISING_ADDRESS		(u8)4

/***********************************************************************************/

//PWM read using Timer0 and INT0

BOOL State = FALSE;

//BOOL HighState = FALSE;

//BOOL LowState = FALSE;

BOOL RisingState = FALSE;

BOOL FallingState = FALSE;

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

		RisingState = TRUE;

		State = TRUE;

		TIMER0_VoidSetPreload(0);
		//TIMER0_start(TIMER0_DIV64);

		OverFlowCounter = 0;

		EXTINT_voidInit(EXT0_ID,FALLING_EDGE);

		edge = RISING_EDGE;

	}
	//falling edge state
	else if (edge==FALLING_EDGE){

		FallingState = TRUE;

		State = FALSE;

		TIMER0_VoidStop();

		//TIMER0_start(TIMER0_STOP);
		//TimeOn = TIMER0_getCounts();

		//TONTime = Ttick*(TimeOn+(256*OverFlowCounter));
		//dis = 17 * TONTime;

		EXTINT_voidInit(EXT0_ID,RISING_EDGE);

		edge = FALLING_EDGE;
	}
}

int main(){

	//LCD

	LCD_voidInit();

	u8 LCDLocation = 0;

	u8 High[8] = {
	   (u8)0b11111111,
	   (u8)0b00000000,
	   (u8)0b00000000,
	   (u8)0b00000000,
	   (u8)0b00000000,
	   (u8)0b00000000,
	   (u8)0b00000000,
	   (u8)0b00000000
	};

	u8 Low[8] = {
		(u8)0b00000000,
		(u8)0b00000000,
		(u8)0b00000000,
		(u8)0b00000000,
		(u8)0b00000000,
		(u8)0b00000000,
		(u8)0b11111111,
		(u8)0b11111111
	};


	u8 Rising[8] = {
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b11111111,
		(u8)0b11111111
	};

	u8 Falling[8] = {
		(u8)0b11111111,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b00000001,
		(u8)0b11111111
	};


	//EXTINT0
	EXTINT_voidInit(EXT0_ID,RISING_EDGE);

	EXTINT_voidSetCallBack(EXTINT_voidTriger,EXT0_ID);
	//Timer0
	TIMER0_VoidInit();

	TIMER_voidSetCallBack(OverFlowFunction);

	TIMER0_VoidStart();

	//Global Interrupt Enable
	GIE_Enable();

	while (1){

		LCD_voidWriteSpecialCharToCGRAM(High,HIGH_ADDRESS);

		LCD_voidWriteSpecialCharToCGRAM(Falling,LOW_ADDRESS);

		LCD_voidWriteSpecialCharToCGRAM(Low,FALLING_ADDRESS);

		LCD_voidWriteSpecialCharToCGRAM(Rising,RISING_ADDRESS);

		if(RisingState==TRUE){
			LCD_voidDisplaySpecialChar(RISING_ADDRESS);
			RisingState = FALSE;
		}
		if(FallingState==TRUE){
			LCD_voidDisplaySpecialChar(FALLING_ADDRESS);
			FallingState = FALSE;
		}

		if(State==TRUE){
			LCD_voidDisplaySpecialChar(HIGH_ADDRESS);
		}
		else if(State==FALSE){
			LCD_voidDisplaySpecialChar(LOW_ADDRESS);
		}
		//Normal LCD send
/*		LCD_voidWriteSpecialCharToCGRAM(High,HIGH_ADDRESS);

		LCD_voidWriteSpecialCharToCGRAM(Falling,LOW_ADDRESS);

		LCD_voidWriteSpecialCharToCGRAM(Low,FALLING_ADDRESS);

		LCD_voidWriteSpecialCharToCGRAM(Rising,RISING_ADDRESS);


		LCD_voidGoToXY(0,LCDLocation);

		LCD_voidDisplaySpecialChar(HIGH_ADDRESS);

		LCD_voidDisplaySpecialChar(LOW_ADDRESS);

		LCD_voidDisplaySpecialChar(FALLING_ADDRESS);

		LCD_voidDisplaySpecialChar(RISING_ADDRESS);

		LCDLocation+=4;

		_delay_ms(100);*/

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
