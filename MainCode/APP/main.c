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

/***********************************************************************************/

//PWM read using Timer0 and INT0

/***********************************************************************************/
BOOL HighState = FALSE;

BOOL LowState  = FALSE;
/***********************************************************************************/

/***********************************************************************************/
f32 TickTime = 0.004, TotalONTime = 0, TotalTime = 0, DutyCycle = 0; //ms

u32 OverFlowCounter = 0;

u8 edge = RISING_EDGE, RemainingTime = 0;
/***********************************************************************************/

void OverFlowFunction(){
	OverFlowCounter++;
}

void EXTINT_voidTriger(){

	//rising edge state
	if (edge==RISING_EDGE){

		LowState = FALSE;

		HighState = TRUE;

		RemainingTime = TIMER0_VoidVal();

		TotalTime = (RemainingTime + (256*OverFlowCounter) );

		DutyCycle = (TotalONTime / TotalTime);

		TIMER0_VoidSetPreload(0);

		OverFlowCounter = 0;

		EXTINT_voidInit(EXT0_ID,FALLING_EDGE);

		edge = FALLING_EDGE;

	}

	//falling edge state
	else if (edge==FALLING_EDGE){

		HighState = FALSE;

		LowState = TRUE;

		RemainingTime = TIMER0_VoidVal();

		TotalONTime = (RemainingTime + (256*OverFlowCounter) );

		EXTINT_voidInit(EXT0_ID,RISING_EDGE);

		edge = RISING_EDGE;
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

	//EXTINT0

	DIO_voidSetPinDirection(PORTD_ID,PIN2,PIN_INPUT);

	DIO_voidSetPinValue(PORTD_ID,PIN2,PIN_HIGH);

	EXTINT_voidInit(EXT0_ID,RISING_EDGE);

	EXTINT_voidSetCallBack(EXTINT_voidTriger,EXT0_ID);

	//Timer0
	TIMER0_VoidInit();

	TIMER_voidSetCallBack(OverFlowFunction);

	TIMER0_VoidStart();

	//Global Interrupt Enable
	GIE_Enable();

	//Send the custom characters to the CGRAM
	LCD_voidWriteSpecialCharToCGRAM(High,HIGH_ADDRESS);

	LCD_voidWriteSpecialCharToCGRAM(Low,LOW_ADDRESS);

	while (1){


		//Frequency
		LCD_voidGoToXY(0,0);

		LCD_voidWriteString("F: ");

		LCD_voidWriteNumber((u8)((1 / DutyCycle) *1000));

		LCD_voidWriteString(" KHz");

		//Duty Cycle
		LCD_voidGoToXY(0,12);

		LCD_voidWriteString("D: ");

		LCD_voidWriteNumber((u8)(DutyCycle *100));

		LCD_voidWriteString(" %");

		//Illustration
		LCD_voidGoToXY(2,LCDLocation);

		while(HighState==TRUE){
			LCD_voidDisplaySpecialChar(HIGH_ADDRESS);
			_delay_ms(50);
			LCDLocation++;

		}

		while(LowState==TRUE){
			LCD_voidDisplaySpecialChar(LOW_ADDRESS);
			_delay_ms(50);
			LCDLocation++;

		}


		if(LCDLocation>=18){
			LCD_voidClear();
			LCDLocation = 0;
		}

		_delay_ms(50);
	}
	return 0;
}
