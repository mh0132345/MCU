#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
/***********************************************************************************

FILE NAME  	:	main.h

DESCRIPTION	:	Main header file

Copyright   : 2005 Renesas Technology Europe Ltd.
Copyright   : 2005 Renesas Technology Corporation.
All Rights Reserved
***********************************************************************************/

/***********************************************************************************
Revision History
DD.MM.YYYY OSO-UID Description
07.07.2005 RTE-MAB First Release
***********************************************************************************/
/* must be 8 characters long to fill display exactly*/
#define NICKNAME "M16C62P "

/***********************************************************************************
Function Prototypes
***********************************************************************************/

void main(void);   
void RTC_Test(void);
void Statics_Test(void);
void RTC_Init(void);
void LED_COUNT(void);

#endif /* MAIN_H_INCLUDED */
