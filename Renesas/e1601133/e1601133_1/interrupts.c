/***********************************************************************************
FILE NAME  		Interrupts.c

DESCRIPTION		Function to Configure the interrupt controller and used interrupts.

Copyright   : 2005 Renesas Technology Europe Ltd.
Copyright   : 2005 Renesas Technology Corporation.
All Rights Reserved

Notes:
This file includes a compiler directive #pragma INTERRUPT functionname

This directive instructs the compiler to treat the following function as an interrupt.
The compiler will save all registers used in the function and replace the normal RTS
instruction with an RTE instruction at the end of the function.
The sect30.inc file must be modified to point the appropriate vector at this function.
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
/* sfr62P.h provides a structure to access all of the device registers. */
#include "sfr62P.h"
/* rskM16C62Pdef.h provides common defines for widely used items. */
#include "rskM16C62Pdef.h"
#include "Interrupts.h"
#include "FlashLEDS.h"

/**********************************************************************************
Global variables
***********************************************************************************/
extern volatile char gucKeyPressed;
static unsigned short usCounter = LED_INTERVAL;
/**********************************************************************************
User Program Code
***********************************************************************************/

/***********************************************************************************
Function Name: 	ConfigureInterrupts
Description:	Configure interrupt enables and settings
Parameters: none
Return value: none
***********************************************************************************/
void ConfigureInterrupts(void)
{	
	/* SW1 is connected to IRQ 0 priority 1 */
	int0ic = 0x01;
	/* SW2 is connected to IRQ 1 priority 2 */
	int1ic = 0x02;

	/* SW3 is connected to IRQ 3 priority 3 */
	int2ic = 0x03;

	/* Timer A0 priority 4 */
	ta0ic = 0x04;

	/* Required to set this to 0 before interrupt enable */
	ifsr2a = 0x00;

	/* Enable interrupts by setting i flag */
	asm("fset i");	
}
/***********************************************************************************
End of function ConfigurePortPins
***********************************************************************************/

/**********************************************************************************
ISR Name: 		TimerA0Handler
Description:	Decrements a counter. If the counter is zero, toggle the LEDs and 
				reload the counter.
Parameters: 	none
Return value: 	none
***********************************************************************************/
void TimerA0Handler(void)
{
	/* If ADC conversion is complete */
	if (adst == 0)
	{
		/* Use the ADC reading as timer upper limit */
		ta0 = ad0 << 8; 

		/* Re-start the A/D */
		adst = 1;
	}

	/* Toggle the LEDs */
	if (--usCounter == 0x00)
	{   
		ToggleLEDs();
		usCounter = LED_INTERVAL;
	}
	
	/* Clear interrupt flag */
	/* Interrupt flags are cleared automatically */
}
/**********************************************************************************
End of ISR TimerA0Handler
***********************************************************************************/


/**********************************************************************************
 Switch driven ISRs
***********************************************************************************/

/**********************************************************************************
ISR Name: 		INT_INT0
Description:	SW1 is connected to the INT0 interrupt pin
Parameters: 	none
Return value: 	If SW1 is pressed global 'gucKeyPressed' is set to 1.
***********************************************************************************/
void INT_INT0(void)
{
	/* Add delay to debounce switch */
	unsigned long ulDelay = 0x3F;
	while (ulDelay--);

	/* Set a flag to say the switch has been pressed */
	gucKeyPressed = '1';

	/* Clear interrupt flag */
	/* Interrupt flags are cleared automatically */
}
/**********************************************************************************
End of ISR INT_INT0
***********************************************************************************/

/**********************************************************************************
ISR Name: 		INT_INT1
Description:	SW2 is connected to the INT1 interrupt pin
Parameters: 	none
Return value: 	If SW2 is pressed global 'gucKeyPressed' is set to 2.
***********************************************************************************/
void INT_INT1(void)
{
	/* Add delay to debounce switch */
	unsigned long ulDelay = 0x3F;
	while (ulDelay--);

	/* Set a flag to say the switch has been pressed */
	gucKeyPressed = '2';

	/* Clear interrupt flag */
	/* Interrupt flags are cleared automatically */
}
/**********************************************************************************
End of ISR INT_INT1
***********************************************************************************/

/**********************************************************************************
ISR Name: 		INT_INT2
Description:	SW3 is connected to the INT2 interrupt pin
Parameters: 	none
Return value: 	If SW3 is pressed global 'gucKeyPressed' is set to 3.
***********************************************************************************/
void INT_INT2(void)
{
	/* Add delay to debounce switch */
	unsigned long ulDelay = 0x3F;
	while (ulDelay--);

	/* Set a flag to say the switch has been pressed */
	gucKeyPressed = '3';

	/* Clear interrupt flag */
	/* Interrupt flags are cleared automatically */
}
/**********************************************************************************
End of ISR INT_INT2
***********************************************************************************/

