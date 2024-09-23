/*
 * TIMER1_Program.c
 *
 *  Created on: September 18, 2024
 *      Author: ahmed
 */


#include <TIMER1_Interface.h>
#include <TIMER1_Private.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "TIMER1_config.h"



void TIMER1_voidPwm1Init(void)
{
	/* to enable output circuit for PD5 pin */

	DIO_voidSetPinDirection(PORTD_ID,PIN5,PIN_OUTPUT);

	/* to select mode 14 in table 47 */
	CLR_BIT(TCCR1A_REG,WGM10);
	SET_BIT(TCCR1A_REG,WGM11);
	SET_BIT(TCCR1B_REG,WGM12);
	SET_BIT(TCCR1B_REG,WGM13);

	/* to select non inverting mode */
	SET_BIT(TCCR1A_REG,COM1A1);
	CLR_BIT(TCCR1A_REG,COM1A0);
}
void TIMER1_voidPwm1SetTop(void)
{
	//PRESCALER = 256  at  16M F
	/*ICR1_REG=624;*/
	ICR1_REG = 40000;
}

void TIMER1_voidPwm1SetDutyCycle(void)
{
	// pass num between 25 and 65
	//OCR1A_REG = 62;

	OCR1A_REG = 20000;

}
void TIMER1_voidPwm1Start(void)
{
#if   TIMER1_PRESCALER   ==   1024
	SET_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);
#elif TIMER1_PRESCALER   ==   256
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	SET_BIT(TCCR1B_REG,CS12);
#elif TIMER1_PRESCALER   ==   64
	SET_BIT(TCCR1B_REG,CS10);
	SET_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
#elif TIMER1_PRESCALER   ==   8
	CLR_BIT(TCCR1B_REG,CS10);
	SET_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
#endif
}
void TIMER1_voidPwm1Stop(void)
{
	CLR_BIT(TCCR1B_REG,CS10);
	CLR_BIT(TCCR1B_REG,CS11);
	CLR_BIT(TCCR1B_REG,CS12);
}
