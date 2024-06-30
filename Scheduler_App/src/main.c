/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR     :AHMED KHLAED ANWAR
MICRO      :STM32F401CCU6
FILE       :MAIN FILE
DESCRIPTION:APPLICAYION TO TOGGLE 8 LEDS WITH DIFFERENT DELAYS USING SCHEDULER AND SYSTICK TIMER.
Version    :1.0
********************************************************************************************************
********************************************************************************************************
 */

/****************************************      Includes      ******************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "RTOS_Interface.h"


/****************************************      Defines      *******************************************/

#define LED0  0
#define LED1  1
#define LED2  2
#define LED3  3
#define LED4  4
#define LED5  5
#define LED6  6
#define LED7  7





/************************************   Application Implementation   **********************************/

/*Function name:LED0_TASK
 * Description: This task is executed periodically with a 100 milliseconds interval.
 * I/P arguments:
 * 				void
 *				return: void
 */
void LED0_TASK(void)
{
	GPIO_u8ChangePinOutMode(GPIO_u8PortA,LED0,GPIO_u8_OP_MODE_TGL);
}

/*Function name:LED1_TASK
 * Description: This task is executed periodically with a 150 milliseconds interval.
 * I/P arguments:
 * 				void
 *				return: void
 */
void LED1_TASK(void)
{
	GPIO_u8ChangePinOutMode(GPIO_u8PortA,LED1,GPIO_u8_OP_MODE_TGL);

}

/*Function name:LED2_TASK
 * Description: This task is executed periodically with a 200 milliseconds interval.
 * I/P arguments:
 * 				void
 *				return: void
 */
void LED2_TASK(void)
{
	GPIO_u8ChangePinOutMode(GPIO_u8PortA,LED2,GPIO_u8_OP_MODE_TGL);

}

/*Function name:LED3_TASK
 * Description: This task is executed periodically with a 240 milliseconds interval.
 * I/P arguments:
 * 				void
 *				return: void
 */
void LED3_TASK(void)
{
	GPIO_u8ChangePinOutMode(GPIO_u8PortA,LED3,GPIO_u8_OP_MODE_TGL);

}

/*Function name:LED4_TASK
 * Description: This task is executed periodically with a 250 milliseconds interval.
 * I/P arguments:
 * 				void
 *				return: void
 */
void LED4_TASK(void)
{
	GPIO_u8ChangePinOutMode(GPIO_u8PortA,LED4,GPIO_u8_OP_MODE_TGL);

}

/*Function name:LED5_TASK
 * Description: This task is executed periodically with a 320 milliseconds interval.
 * I/P arguments:
 * 				void
 *				return: void
 */
void LED5_TASK(void)
{
	GPIO_u8ChangePinOutMode(GPIO_u8PortA,LED5,GPIO_u8_OP_MODE_TGL);

}

/*Function name:LED6_TASK
 * Description: This task is executed periodically with a 460 milliseconds interval.
 * I/P arguments:
 * 				void
 *				return: void
 */
void LED6_TASK(void)
{
	GPIO_u8ChangePinOutMode(GPIO_u8PortA,LED6,GPIO_u8_OP_MODE_TGL);

}

/*Function name:LED7_TASK
 * Description: This task is executed periodically with a 540 milliseconds interval.
 * I/P arguments:
 * 				void
 *				return: void
 */
void LED7_TASK(void)
{
	GPIO_u8ChangePinOutMode(GPIO_u8PortA,LED7,GPIO_u8_OP_MODE_TGL);

}

int main(void)
{
	RCC_u8InitSysClk();
	RCC_u8EnablePeripheralClk(RCC_u8_AHB1_BUS,RCC_u8_AHB1ENR_GPIOA);
	 for (int i = 0; i < 8; ++i)
	 {
		 GPIO_u8SetPinMode(GPIO_u8PortA,i,GPIO_u8_PinModeOutput);
		 GPIO_u8SetPinOutputType(GPIO_u8PortA,i,GPIO_u8_OP_PP);
	 }


	 /*Create tasks and initialise OS*/

	 RTOS_u8CreateTask(LED0_TASK,100,0,0);
	 RTOS_u8CreateTask(LED1_TASK,150,1,0);
	 RTOS_u8CreateTask(LED2_TASK,200,2,0);
	 RTOS_u8CreateTask(LED3_TASK,240,3,0);
	 RTOS_u8CreateTask(LED4_TASK,250,4,0);
	 RTOS_u8CreateTask(LED5_TASK,320,5,0);
	 RTOS_u8CreateTask(LED6_TASK,460,6,0);
	 RTOS_u8CreateTask(LED7_TASK,540,7,0);

	 Start_OS();
	  while(1)
	  {

	  }
return 0;

}

