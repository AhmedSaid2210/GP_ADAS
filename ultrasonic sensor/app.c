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
	
	uint32_t a = 0, b = 0 ,h = 0 ,distance = 0;
	uint32_t receive = 0;
	
	MCAL_GPIO_Pin_Init(&PE0);
	MCAL_GPIO_Pin_Init(&PE1);
	MCAL_GPIO_Pin_Init(&PE2);
	MCAL_GPIO_Pin_Init(&PE3);
	MCAL_GPIO_Pin_Init(&PE4);
	MCAL_GPIO_Pin_Init(&PE5);
	
  HAL_Ultra_Inti(&ultra1);
	
	while(1)
	{
		
		key = '1';
		
		if(key == '1'){
			
		HAL_Ultra_Dist(&ultra1,&distance);
		distance = distance / 2;
		
		switch(distance)
		{
			case 6:
				MCAL_GPIO_Pin_Write(&PE0,HIGH);
				MCAL_GPIO_Pin_Write(&PE1,LOW);
				MCAL_GPIO_Pin_Write(&PE2,LOW);
				MCAL_GPIO_Pin_Write(&PE3,LOW);
				MCAL_GPIO_Pin_Write(&PE4,LOW);
				MCAL_GPIO_Pin_Write(&PE5,LOW);
			break;
			case 5:
				MCAL_GPIO_Pin_Write(&PE0,HIGH);
				MCAL_GPIO_Pin_Write(&PE1,HIGH);
				MCAL_GPIO_Pin_Write(&PE2,LOW);
				MCAL_GPIO_Pin_Write(&PE3,LOW);
				MCAL_GPIO_Pin_Write(&PE4,LOW);
				MCAL_GPIO_Pin_Write(&PE5,LOW);
			break;
			case 4:
				MCAL_GPIO_Pin_Write(&PE0,HIGH);
				MCAL_GPIO_Pin_Write(&PE1,HIGH);
				MCAL_GPIO_Pin_Write(&PE2,HIGH);
				MCAL_GPIO_Pin_Write(&PE3,LOW);
				MCAL_GPIO_Pin_Write(&PE4,LOW);
				MCAL_GPIO_Pin_Write(&PE5,LOW);
			break;
			case 3:
				MCAL_GPIO_Pin_Write(&PE0,HIGH);
				MCAL_GPIO_Pin_Write(&PE1,HIGH);
				MCAL_GPIO_Pin_Write(&PE2,HIGH);
				MCAL_GPIO_Pin_Write(&PE3,HIGH);
				MCAL_GPIO_Pin_Write(&PE4,LOW);
				MCAL_GPIO_Pin_Write(&PE5,LOW);
			break;
			case 2:
				MCAL_GPIO_Pin_Write(&PE0,HIGH);
				MCAL_GPIO_Pin_Write(&PE1,HIGH);
				MCAL_GPIO_Pin_Write(&PE2,HIGH);
				MCAL_GPIO_Pin_Write(&PE3,HIGH);
				MCAL_GPIO_Pin_Write(&PE4,HIGH);
				MCAL_GPIO_Pin_Write(&PE5,LOW);
			break;
			case 1:
				MCAL_GPIO_Pin_Write(&PE0,HIGH);
				MCAL_GPIO_Pin_Write(&PE1,HIGH);
				MCAL_GPIO_Pin_Write(&PE2,HIGH);
				MCAL_GPIO_Pin_Write(&PE3,HIGH);
				MCAL_GPIO_Pin_Write(&PE4,HIGH);
				MCAL_GPIO_Pin_Write(&PE5,HIGH);
			break;
			default:
				MCAL_GPIO_Pin_Write(&PE0,LOW);
				MCAL_GPIO_Pin_Write(&PE1,LOW);
				MCAL_GPIO_Pin_Write(&PE2,LOW);
				MCAL_GPIO_Pin_Write(&PE3,LOW);
				MCAL_GPIO_Pin_Write(&PE4,LOW);
				MCAL_GPIO_Pin_Write(&PE5,LOW);
				
		}
	  

	}
	else{
		
		MCAL_GPIO_Pin_Write(&PF1,LOW);
		
		MCAL_GPIO_Pin_Write(&PE0,LOW);
		MCAL_GPIO_Pin_Write(&PE1,LOW);
		MCAL_GPIO_Pin_Write(&PE2,LOW);
		MCAL_GPIO_Pin_Write(&PE3,LOW);
		MCAL_GPIO_Pin_Write(&PE4,LOW);
		MCAL_GPIO_Pin_Write(&PE5,LOW);
		
		
	
	}
	MCAL_DelayMs(100);	
}
}

void fun()
{
	MCAL_Timer_IntClear(&timer1A);
	
}
void initUART(void) 
	{
		SysCtlGPIOAHBEnable(SYSCTL_PERIPH_GPIOA);
		
		// Enable the GPIOA peripheral that is used for the UART pins
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
		
		while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)){}
			
			
    // Enable the UART0 peripheral
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	// Wait for the UART0 module to be ready.
		while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0)){}


    // Configure the GPIO pin types for UART
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(PORT_A, GPIO_PIN_0 | GPIO_PIN_1);

    // Initialize the UART for 115200 baud rate, 8-bit data, no parity, and one stop bit
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    // Enable the UART
    UARTEnable(UART0_BASE);
}

void printstring(char *str)
{
	  uint32_t len = strlen(str);
    for (uint32_t i = 0; i < len; i++) 
			 {
         UARTCharPut(UART0_BASE, str[i]);
       }
}
