/* This example code Measures the distance using HC-SR04 Ultrasonic range sensor*/
/* It displays the measured distance value on computer using UART communication moduel of TM4C123 */
/* Timer0A is used to measure distance by measuring pulse duration of Echo output signal */
/* Timer1A is used to make percise microsecond delay function */

/*header files for TM4C123 device and sprintf library */
#include "TM4C123GH6PM.h"
#include <stdio.h>
#include <stdint.h>

#include "GPIO_Config.h"
#include "RCC_Config.h"
#include "Timer_Config.h"
#include "driverlib/uart.h"
#include "delay.h"
#include "string.h"
#include "ultrasonic_Config.h"
#include "lcd.h"				
 //void SystemInit(void){}
	
void fun();
volatile uint16_t counter = 0;
void initUART(void) ;
void printstring(char *str);
char mesg[20];
char receive = 0;
char key = 0;


int main(void)
{
	
	MCAL_RCC_SysCtlClockExternal(&RCC_config16);
	
	MCAL_GPIO_Pin_Init(&PF1);
	
	MCAL_Timer_Inti(&wtimer4A);
	MCAL_Timer_Int_handler(&wtimer4A,fun);
	MCAL_Timer_Start(&wtimer4A);
	while(1)
	{
		
	
  }
}

void fun()
{
	MCAL_Timer_IntClear(&wtimer4A);
	MCAL_GPIO_Pin_Write(&PF1,TOGGLE);
}


