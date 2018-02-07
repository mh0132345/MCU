/***********************************************************************************
FILE NAME  		main.c
DESCRIPTION		Main Program

	This is the main tutorial code. This code will call three functions to demonstrate
	Port pin control (FlashLEDs), Interrupt usage (TimerADC) and C variable
	initialisation (Statics_Test). Code is also included to drive the optional LCD
	module.

	Please refer to the tutorial manual for more information on the program flow.

Copyright   : 2005 Renesas Technology Europe Ltd.
Copyright   : 2005 Renesas Technology Corporation.
All Rights Reserved

***********************************************************************************/

/***********************************************************************************
Revision History
DD.MM.YYYY OSO-UID Description
07.07.2005 RTE-MAB First Release
***********************************************************************************/

/**********************************************************************************
System Includes
***********************************************************************************/

/**********************************************************************************
User Includes
***********************************************************************************/
/* sfr62P.h provides common defines for widely used items. */
#include "sfr62P.h"
#include "lcd.h"
#include "FlashLEDs.h"
#include "main.h"
#include "Interrupts.h"
#include "timerADC.h"

/**********************************************************************************
Global variables
***********************************************************************************/
/* Global initialised variable*/
char ucStr[] = " STATIC \0";
/* Constant Data for replacement */					
const char ucReplace[] = "TESTTEST\0";
/* Global changed by pressing switches */			
unsigned volatile char gucKeyPressed = 0x00;
/* Initial value of the counter */	
unsigned volatile char count = 0xFF;			

/**********************************************************************************
User Program Code
***********************************************************************************/

/**********************************************************************************
Function Name: 	Main
Description:	Main function
Parameters: 	none
Return value: 	none
***********************************************************************************/
void main(void)				
{
/* Reset the LCD module */
	InitialiseDisplay();

/* Display Renesas Splash Screen */
	DisplayString(LCD_LINE1,"New");
	DisplayString(LCD_LINE2,NICKNAME);

/* Flash the user LEDs for some time or until a key is pressed. */
//	FlashLEDs();

/* Flash the user LEDs at a rate set by the user potentiomenter (ADC) using
   interrupts. */
//	TimerADC();

/* Demonstration of initialised variables. Use this function with the debugger. */
	Statics_Test();
	
	pd0 = 0x0F;
	p0 = 0x03;

	while(1){
		if (p0_4 == 1){
			DisplayString(LCD_LINE1,"_H");
		} else if (p0_4 == 0){
			DisplayString(LCD_LINE1,"L_");
		} else {
			DisplayString(LCD_LINE1,"ee");
		}
	}

/* End of the user program. This function must not exit. */
	for(;;);
}         
/**********************************************************************************
End of function main
***********************************************************************************/   

/**********************************************************************************
Function Name: 	Statics_Test
Description:	Displays an initialised string, then modifies it, a character
				at a time, displaying it at each stage.
				Finally NICKNAME is displayed.
Parameters: 	none
Return value: 	none
***********************************************************************************/
void Statics_Test(void)
{
	unsigned short uiCount;
	unsigned long ulLcd_Delay;

	DisplayString(LCD_LINE2,ucStr);	

/* At this point please right click on the 'ucSTR' variable and select 'Instant Watch'
A dialog will be displayed showing the current value of the variable.
Select 'Add' in the dialog and a new 'Watch Window' will open.
Step through the following code to see that the initialised data is being overwritten
with the different data. */

	for (uiCount=0; uiCount<8; uiCount++)
	{
		ucStr[uiCount] = ucReplace[uiCount];
		DisplayString(LCD_LINE2,ucStr);	

		for (ulLcd_Delay=0; ulLcd_Delay<400000L; ulLcd_Delay++)
		{
			/* delay */
		}	
	}	

	ucStr[uiCount] = '\0';

/* Reset the LCD display */
	DisplayString(LCD_LINE2,NICKNAME);	
}
/**********************************************************************************
End of function Statics_Test
***********************************************************************************/

