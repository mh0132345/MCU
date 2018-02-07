/***********************************************************************************
FILE NAME  		resetprg.c
DESCRIPTION		Reset Initialisation Functions
			The users program will start in this file.

Copyright   : 2005 Renesas Technology Europe Ltd.
Copyright   : 2005 Renesas Technology Corporation.
All Rights Reserved

***********************************************************************************/

/***********************************************************************************
Revision History
DD.MM.YYYY OSO-UID Description
07.07.2005 RTE-MAB First Release
***********************************************************************************/


/***********************************************************************************
System Includes
***********************************************************************************/

/***********************************************************************************
User Includes
***********************************************************************************/
/* sfr62P.h provides a structure to access all of the device registers. */
#include "sfr62P.h"
#include "hwsetup.h"
#include "main.h"

/**********************************************************************************
Global variables
***********************************************************************************/

/***********************************************************************************
User Program Code
***********************************************************************************/

/**********************************************************************************
Function Name: 	Initialise
Description:	Initialise the micon then call main
Parameters: 	none
Return value: 	none
***********************************************************************************/
void Initialise(void)
{ 
	/* Initialise all the required peripheral modules */
	HardwareSetup();

	/* main function including users code */
	main();

	/* This function must never exit */
	for(;;);
}
/**********************************************************************************
End of function Initialise
***********************************************************************************/   
