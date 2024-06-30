/* This example code Measures the distance using HC-SR04 Ultrasonic range sensor*/
/* It displays the measured distance value on computer using UART communication moduel of TM4C123 */
/* Timer0A is used to measure distance by measuring pulse duration of Echo output signal */
/* Timer1A is used to make percise microsecond delay function */

/*header files for TM4C123 device and sprintf library */
#include "TM4C123GH6PM.h"

#include <stdio.h>
#include "GPIO_Config.h"
#include "RCC_Config.h"
#include "Timer_Config.h"
#include "driverlib/uart.h"
#include "delay.h"
#include "string.h"
#include "ultrasonic_Config.h"

#include "lcd.h"				
//void SystemInit(){}
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
	
	//MCAL_GPIO_Pin_Init(&PA2);
	//MCAL_GPIO_Pin_Init(&PA3);
	//MCAL_GPIO_Pin_Init(&PA4);
	//MCAL_GPIO_Pin_Init(&PA5);
	MCAL_GPIO_Pin_Init(&PA6);
	MCAL_GPIO_Pin_Init(&PA7);
	
	MCAL_GPIO_Pin_Init(&PB0);
	MCAL_GPIO_Pin_Init(&PB1);
	MCAL_GPIO_Pin_Init(&PB4);
	MCAL_GPIO_Pin_Init(&PB5);
	MCAL_GPIO_Pin_Init(&PB6);
	MCAL_GPIO_Pin_Init(&PB7);
	
	MCAL_GPIO_Pin_Init(&PC4);
	MCAL_GPIO_Pin_Init(&PC5);
	MCAL_GPIO_Pin_Init(&PC6);
	MCAL_GPIO_Pin_Init(&PC7);
	
	MCAL_GPIO_Pin_Init(&PD0);
	MCAL_GPIO_Pin_Init(&PD1);
	MCAL_GPIO_Pin_Init(&PD2);
	MCAL_GPIO_Pin_Init(&PD3);
	MCAL_GPIO_Pin_Init(&PD6);
	MCAL_GPIO_Pin_Init(&PD7);

	MCAL_GPIO_Pin_Init(&PE0);
	MCAL_GPIO_Pin_Init(&PE1);
	MCAL_GPIO_Pin_Init(&PE2);
	MCAL_GPIO_Pin_Init(&PE3);
	MCAL_GPIO_Pin_Init(&PE4);
	MCAL_GPIO_Pin_Init(&PE5);

	MCAL_GPIO_Pin_Init(&PF0);
	MCAL_GPIO_Pin_Init(&PF1);
	MCAL_GPIO_Pin_Init(&PF2);
	MCAL_GPIO_Pin_Init(&PF3);
  MCAL_GPIO_Pin_Init(&PF4);





	while(1)
	{
		
		
			MCAL_GPIO_Pin_Write(&PD0,HIGH);
			MCAL_GPIO_Pin_Write(&PD1,HIGH);
		  MCAL_GPIO_Pin_Write(&PD2,HIGH);
		  MCAL_GPIO_Pin_Write(&PD3,HIGH);
		  MCAL_GPIO_Pin_Write(&PD6,HIGH);
		  MCAL_GPIO_Pin_Write(&PD7,HIGH);
		
		MCAL_GPIO_Pin_Write(&PA6,HIGH);
		MCAL_GPIO_Pin_Write(&PA7,HIGH);
		
	
	 
		
			MCAL_GPIO_Pin_Write(&PB0,HIGH);
			MCAL_GPIO_Pin_Write(&PB1,HIGH);
		  MCAL_GPIO_Pin_Write(&PB4,HIGH);
		  MCAL_GPIO_Pin_Write(&PB5,HIGH);
		  MCAL_GPIO_Pin_Write(&PB6,HIGH);
		  MCAL_GPIO_Pin_Write(&PB7,HIGH);
		
		  //MCAL_GPIO_Pin_Write(&PC4,HIGH);
		  MCAL_GPIO_Pin_Write(&PC5,HIGH);
		 // MCAL_GPIO_Pin_Write(&PC6,HIGH);
		  MCAL_GPIO_Pin_Write(&PC7,HIGH);
		
			MCAL_GPIO_Pin_Write(&PA6,HIGH);
			MCAL_GPIO_Pin_Write(&PA7,HIGH);
		
		  MCAL_GPIO_Pin_Write(&PE0,HIGH);
		  MCAL_GPIO_Pin_Write(&PE1,HIGH);
		  MCAL_GPIO_Pin_Write(&PE2,HIGH);
		  MCAL_GPIO_Pin_Write(&PE3,HIGH);
			MCAL_GPIO_Pin_Write(&PE4,HIGH);
			MCAL_GPIO_Pin_Write(&PE5,HIGH);
			
			
			MCAL_GPIO_Pin_Write(&PF0,HIGH);
			MCAL_GPIO_Pin_Write(&PF1,HIGH);
			MCAL_GPIO_Pin_Write(&PF2,HIGH);
			MCAL_GPIO_Pin_Write(&PF3,HIGH);
			MCAL_GPIO_Pin_Write(&PF4,HIGH);
 
		
  }
}
