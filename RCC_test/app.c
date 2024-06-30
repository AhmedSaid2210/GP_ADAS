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
#include "RCC_test.h" 
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
	RCC_testcase4(); 

}

