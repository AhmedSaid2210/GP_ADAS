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
#include "PWM_Config.h"
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
/*	
	MCAL_PWM_Inti(&PA6_M1PWM2);
	MCAL_PWM_Inti(&PA7_M1PWM3);
	
	MCAL_PWM_Inti(&PB4_M0PWM2);
	MCAL_PWM_Inti(&PB5_M0PWM3);
	MCAL_PWM_Inti(&PB6_M0PWM0); not
	MCAL_PWM_Inti(&PB7_M0PWM1);
	
	MCAL_PWM_Inti(&PD0_M0PWM6); not
	MCAL_PWM_Inti(&PD0_M1PWM0); not
	MCAL_PWM_Inti(&PD1_M0PWM7);
	MCAL_PWM_Inti(&PD1_M1PWM1);
	
	MCAL_PWM_Inti(&PE4_M0PWM4);
	MCAL_PWM_Inti(&PE4_M1PWM2);
	MCAL_PWM_Inti(&PE5_M0PWM5);
	MCAL_PWM_Inti(&PE5_M1PWM3);
	
	MCAL_PWM_Inti(&PF0_M1PWM4);
	MCAL_PWM_Inti(&PF1_M1PWM5);
	MCAL_PWM_Inti(&PF2_M1PWM6);
	MCAL_PWM_Inti(&PF3_M1PWM7);
	*/
	MCAL_PWM_Inti(&PF3_M1PWM7);
	MCAL_PWM_Start(&PF3_M1PWM7);
	while(1)
	{
		int speed = 0;
		
		while(speed <1600)
		{
			speed +=20;
			MCAL_PWM_PulseWidthSet(&PF3_M1PWM7,speed);
			MCAL_DelayMs(50);
		}
		while(speed >20)
		{
			speed -=20;
			MCAL_PWM_PulseWidthSet(&PF3_M1PWM7,speed);
			MCAL_DelayMs(50);
		}
			
	}
	
}



