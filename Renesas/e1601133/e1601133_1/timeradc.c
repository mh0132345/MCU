/***********************************************************************************
FILE NAME  	:	TimerADC.c
DESCRIPTION	:	Function to Flash the user LEDs for a period of time.

				Function will exit if a key is pressed

Copyright   : 2005 Renesas Technology Europe Ltd.
Copyright   : 2005 Renesas Technology Corporation.
All Rights Reserved

***********************************************************************************/

/***********************************************************************************
Revision History
DD.MM.YYYY OSO-UID Description
14.09.2005 RTE-DDE First Release
***********************************************************************************/

/**********************************************************************************
System Includes
***********************************************************************************/

/**********************************************************************************
User Includes
***********************************************************************************/
/* sfr62P.h provides a structure to access all of the device registers. */
#include "sfr62P.h"
/* rskM16C62Pdef.h provides common defines for widely used items. */
#include "rskM16C62Pdef.h"
#include "TimerADC.h"

/**********************************************************************************
Global variables
***********************************************************************************/
extern volatile char gucKeyPressed;

/**********************************************************************************
User Program Code
***********************************************************************************/

/**********************************************************************************
Function Name: 	Timer_AD
Description:	Uses the ADC to change the Duty of the timer, used to flash the LEDs
Parameters: 	none
Return value: 	none
***********************************************************************************/
void TimerADC(void)
{     
	StartTimer();
		
	StartADC();
}     
/**********************************************************************************
End of function Timer_AD
***********************************************************************************/

/**********************************************************************************
Function Name: 	StartADC
Description:	Starts the ADC
Parameters: 	none
Return value: 	none
***********************************************************************************/
void StartADC(void)
{
	/* Set ADC to 8 MHz, p10 group, no s/h */
	adcon2 = 0x10;

	/* Set ADC to 8 MHz, vref on, 8 bit */
	adcon1 = 0x30; // 8MHz, vfref, 8 bit

	/* Set ADC to oneshot, 8MHz, s/w trig, start, ch0 */	 
	adcon0 = 0xC0; 
}
/**********************************************************************************
End of function StartADC
***********************************************************************************/

/**********************************************************************************
Function Name: 	StartTimer
Description:	Configures and starts the timer
Parameters: 	none
Return value: 	none
***********************************************************************************/
void StartTimer(void)
{
	/* Set timer A0 to continuous timer mode clocked by f/8 */
	ta0mr = 0x40;
			
	/* Timer A0 starts acounting down from  0xfff */
	ta0 = (int)0xfff;
	   
	/* start timer A0 (defaults to down)*/
	ta0s = 1; 		
}
/**********************************************************************************
End of function StartTimer
***********************************************************************************/
