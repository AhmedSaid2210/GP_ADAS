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
#include "UART_Config.h"
#include "communication.h"
#include "delay.h"
			

void fun();
volatile uint16_t counter = 0;
void initUART(void) ;
void printstring(char *str);
char mesg[20];


int main(void)
{
	
	MCAL_RCC_SysCtlClockExternal(&RCC_config16);

	

	MCAL_GPIO_Pin_Init(&PF1);
	MCAL_GPIO_Pin_Init(&PF2);

	MCAL_UART_Inti(&UART_Config);
	//initUART();
	
	char key[6] = "ahmed";
	char  receive[6];
	
	message_t d;
	d.start = 'a';
	d.instruction='b';
	d.Data_length = 'c';
	d.start_data = 'd';
	d.Data = 'e';
	d.Checksum = 'f';
	d.stop = 'g';
	message_t r ;

	while(1)
	{
		
	  HAL_Comm_ReceiveFrame(&r);
		
		HAL_Comm_SendFrame(&d);
		
		if(r.Data == '1')
		{
			MCAL_GPIO_Pin_Write(&PF2,HIGH);
			MCAL_GPIO_Pin_Write(&PF1,LOW);
		}
		else
		{
			MCAL_GPIO_Pin_Write(&PF1,HIGH);
			MCAL_GPIO_Pin_Write(&PF2,LOW);
			
		}
		
	}
}
