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
#include "delay.h"
#include "SysTick.h"
#include "string.h"
#include "Watchdog.h"
#include "sleep.h"

#include "driverlib/hibernate.h"

void fun();

uint32_t ui32Status;
uint32_t pui32NVData[64];



int main(void)
{
	
	MCAL_RCC_SysCtlClockExternal(&RCC_config16);
	MCAL_GPIO_Pin_Init(&PF1);
	
	MCAL_Watchdog_Inti();
	
	
	while(1)
	{
	
	
	MCAL_GPIO_Pin_Write(&PF1,HIGH);
	MCAL_DelayMs(5000);
	MCAL_GPIO_Pin_Write(&PF1,LOW);
	MCAL_SleepMode(5000);
	//MCAL_SysTick_Int_handler(5000,fun);
	//MCAL_Watchdog_ReloadSet(1000);
	//SysCtlSleep();
	}

}
void fun()
{
	
}
