#ifndef INTERRUPTS_H
#define INTERRUPTS_H
/***********************************************************************************

FILE NAME  	:	Interrupts.h

DESCRIPTION	:	Configure the interrupt controller and used interrupts.

Copyright   : 2005 Renesas Technology Europe Ltd.
Copyright   : 2005 Renesas Technology Corporation.
All Rights Reserved
***********************************************************************************/

/***********************************************************************************
Revision History
DD.MM.YYYY OSO-UID Description
07.07.2005 RTE-MAB First Release
***********************************************************************************/
#define LED_INTERVAL 100

void ConfigureInterrupts(void);

#pragma INTERRUPT TimerA0Handler
void TimerA0Handler(void);

#pragma INTERRUPT INT_INT0
void INT_INT0(void);

#pragma INTERRUPT INT_INT1
void INT_INT1(void);

#pragma INTERRUPT INT_INT2
void INT_INT2(void);

#endif