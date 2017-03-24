#include <stdio.h>
#include "LPC17xx.H"                         /* LPC17xx definitions           */
#include "Serial.h"
#include "LED1.h"

uint8_t AlertSysTick = 0;
uint8_t clock_1s=0;
uint8_t led_status=0;
//uint8_t ticks = 0;
/*----------------------------------------------------------------------------
  Systick Interrupt Handler
  SysTick interrupt happens every 10 ms
 *----------------------------------------------------------------------------*/
void SysTick_Handler (void) {
  static uint32_t ticks = 0;

	ticks++;
	
	clock_1s = 1;
	return;
}

void SysTick_Init(uint32_t ticks) {
		// Refer Slide 13 & 14 of ece362_lpc1768.ppt
		SysTick->LOAD = ticks & 0xFFFFFF -1;									 //1. set reload register 
		NVIC_SetPriority(SysTick_IRQn, 1);											//2. set Priority for Systick Interrupt
		SysTick -> VAL = 	0;																//3. Load the SysTick Counter Value 
  	SysTick->CTRL = 0x07;																		// 4. Enable SysTick IRQ and SysTick Timer 
	return;
}
/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {
  
  LED1_Init();                                /* LED Initialization            */
  SER_Init();                                /* UART Initialization           */
	SystemCoreClockUpdate();
	SysTick_Init(SystemCoreClock / 100);

	// For Part A & B of lab program system tick with interrupt enabled and 10 ms period. 
	
	// Part A
	clock_1s = 1;
	while (1) {                                        
    if(clock_1s) 
		  {
				clock_1s = 0;
				if (led_status == 0)
				{
					LED1_On();
					led_status = 1;
				}
				else if (led_status == 1)
				{
					LED1_Off();
					led_status = 0;
				}
			}
		}
	}
