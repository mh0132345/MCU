/***********************************************************************************
FILE NAME  		FlashLEDs.c
DESCRIPTION     	Function to Flash the user LEDs for a period of time.
			Function will exit if a key is pressed
            
Copyright   : 2005 Renesas Technology Europe Ltd.
Copyright   : 2005 Renesas Technology Corporation.
All Rights Reserved
***********************************************************************************/

/***********************************************************************************
Revision History
DD.MM.YYYY OSO-UID Description
23.11.2005 RTE-DDE First Release
***********************************************************************************/

/**********************************************************************************
System Includes
***********************************************************************************/

/**********************************************************************************
User Includes
***********************************************************************************/
/* sfr62p.h provides a structure to access all of the device registers. */
#include "sfr62p.h"
/* rskM16C62Pdef.h provides common defines for widely used items. */
#include "rskM16C62Pdef.h"
#include "FlashLEDs.h"

/**********************************************************************************
Global variables
***********************************************************************************/
extern volatile char gucKeyPressed;

/**********************************************************************************
User Program Code
***********************************************************************************/

/**********************************************************************************
Function Name: 	FlashLEDs
Description:	Flashes the user LEDs on the board
Parameters: 	none
Return value: 	none
***********************************************************************************/
void FlashLEDs(void)
{   
    unsigned long ulLed_Delay;
    unsigned long ulLEDcount;
    
	for(ulLEDcount=0; ulLEDcount<200; ulLEDcount++)
	{   
		if( gucKeyPressed > 0x00) break;
 		for(ulLed_Delay=0; ulLed_Delay<400000; ulLed_Delay++);
	 
	    ToggleLEDs();
	}
}                                            
/**********************************************************************************
End of function FlashLEDs
***********************************************************************************/

/**********************************************************************************
Function Name: 	ToggleLEDs
Description:	Toggles the state of the user LEDs on the board.
                This function is used in interrupt routines. No static variables.
Parameters: 	none
Return value: 	none
***********************************************************************************/
void ToggleLEDs()
{
	/* XOR the value of the LED port pins with the mask to invert bits */
    LED_PORT_DR ^= LED_BIT;     		
}
/**********************************************************************************
End of function ToggleLEDs
***********************************************************************************/

