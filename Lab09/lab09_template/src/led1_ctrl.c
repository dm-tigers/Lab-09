#include "LPC17xx.H"                         /* LPC17xx definitions           */
#include "LED1.h"

/* Follow similar steps to Lab 8 A/B to complete below functions 
   But use LPC_GPIO type defined in LPC17xx instead of using header file defined GPIO type*/
	 
/*----------------------------------------------------------------------------
  initialize LED Pins
 *----------------------------------------------------------------------------*/
void LED1_Init (void) {
 LPC_GPIO1 -> FIODIR = 1 << 28;
}

/*----------------------------------------------------------------------------
  Function that turns on requested LED 1
 *----------------------------------------------------------------------------*/
void LED1_On () {
	LPC_GPIO1 -> FIOSET = 1 << 28;
	
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
void LED1_Off () {

	LPC_GPIO1 -> FIOCLR = 1 << 28;
}



