/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : AHMED KHLAED ANWAR
MICRO  : STM32F401CCU6
LAYER  : MCAL
DRIVER : SYSTICK DRIVER
FILE   : PROGRAM FILE
Version: 1.0
********************************************************************************************************
********************************************************************************************************
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Interface.h"
#include "SYSTICK_Private.h"


static void (*STK_CallBack)(void)=NULL;            /*Global pointer to allow the callback function call*/
u8 G_u8SingleFlag=0;

/*Function name:SYSTICK_voidInit
 * Description: Initialise system timer interrupt and clock source
 * I/P arguments:
 * 				void
 *				return:Local_Error_State
 */
u8 c(void)
{
	u8 Local_Error_State=STD_TYPES_OK;
	#if STK_CLK_MODE==AHB
		SET_BIT(STK->STK_CTRL,CLKSOURCE);
	#elif STK_CLK_MODE==AHB_DIV_8
		CLEAR_BIT(STK->STK_CTRL,CLKSOURCE);
    #else
    	#error "Wrong system timer clock source"
		Local_Error_State=STD_TYPES_NOK;
	#endif
	#if STK_INT_MODE==TICKINT_ENABLED
	    SET_BIT(STK->STK_CTRL,TICKINT);
	#elif STK_INT_MODE==TICKINT_DISABLED
	    CLEAR_BIT(STK->STK_CTRL,TICKINT);
	#else
    	#error "Wrong system timer interrupt mode"
		Local_Error_State=STD_TYPES_NOK;
	#endif
	return Local_Error_State;
}

/*Function name:SYSTICK_voidSetPreloadValue
 * Description: Set the preload value
 * I/P arguments:
 * 				Copy_u32PreloadValue
 *				return:Local_Error_State
 */
void SYSTICK_voidSetPreloadValue(u32 Copy_u32PreloadValue)
{
	STK->STK_LOAD=Copy_u32PreloadValue;   /*Specifies the start value to load */
	STK->STK_VAL=0;                       /*Write of any value clears the field to 0*/
	SET_BIT(STK->STK_CTRL,ENABLE);        /*Enabling of SYSTICK*/
}

/*Function name:SYSTICK_u32GetElapsedTime
 * Description: Get elapsed time in ticks
 * I/P arguments:
 * 				void
 *				return:Elapsed time in ticks
 */
u32 SYSTICK_u32GetElapsedTime(void)
{
	return (STK->STK_LOAD-STK->STK_VAL);
}

/*Function name:SYSTICK_u32GetRemainingTime
 * Description: Get remaining time in ticks
 * I/P arguments:
 * 				void
 *				return:Remaining time in ticks
 */
u32 SYSTICK_u32GetRemainingTime(void)
{
	return (STK->STK_VAL);
}

/*Function name:SYSTICK_u8ReadFlag
 * Description: Returns 1 if timer counted to 0 since last time this was read.
 * I/P arguments:
 * 				void
 *				return: counter flag state
 */
u8  SYSTICK_u8ReadFlag(void)
{
	return GET_BIT(STK->STK_CTRL,COUNTFLAG);
}

/*Function name:SYSTICK_voidMicroSecondsDelay
 * Description: Enters the delay value in microseconds.
 * I/P arguments:
 * 				Copy_u32MicroDelayValue
 *				return:void
 */
void SYSTICK_voidMicroSecondsDelay(u32 Copy_u32MicroDelayValue)
{
	CLEAR_BIT(STK->STK_CTRL,TICKINT);                          /*Clear interrupt during delay*/
	STK->STK_LOAD=Copy_u32MicroDelayValue*MICRO_SCALE;         /*Specifies the start value to load */
	STK->STK_VAL=0;                                            /*Write of any value clears the field to 0*/
	SET_BIT(STK->STK_CTRL,ENABLE);                             /*Enabling of SYSTICK*/

}

/*Function name:SYSTICK_voidMilliSecondsDelay
 * Description: Enters the delay value in milliseconds.
 * I/P arguments:
 * 				Copy_u32MilliDelayValue
 *				return:void
 */
void SYSTICK_voidMilliSecondsDelay(u32 Copy_u32MilliDelayValue)
{
	CLEAR_BIT(STK->STK_CTRL,TICKINT);                          /*Clear interrupt during delay*/
	STK->STK_LOAD=Copy_u32MilliDelayValue*MILLI_SCALE;         /*Specifies the start value to load */
	STK->STK_VAL=0;                                            /*Write of any value clears the field to 0*/
	SET_BIT(STK->STK_CTRL,ENABLE);                             /*Enabling of SYSTICK*/

}

/*Function name:SYSTICK_voidSecondsDelay
 * Description: Enters the delay value in seconds.
 * I/P arguments:
 * 				Copy_u32SecondsDelayValue
 *				return:void
 */
void SYSTICK_voidSecondsDelay(u32 Copy_u32SecondsDelayValue)
{
	CLEAR_BIT(STK->STK_CTRL,TICKINT);                            /*Clear interrupt during delay*/
	STK->STK_LOAD=Copy_u32SecondsDelayValue*SECONDS_SCALE;     /*Specifies the start value to load */
	STK->STK_VAL=0;                                              /*Write of any value clears the field to 0*/
	SET_BIT(STK->STK_CTRL,ENABLE);                               /*Enabling of SYSTICK*/
}

/*Function name:SYSTICK_voidSetCallBack
 * Description: Function that sets a callback function to be executed when systick occ
 * I/P arguments:
 * 				void(*ptr)(void)
 *				return:void
 */
void SYSTICK_voidSetCallBack(void(*ptr)(void))
{
	STK_CallBack=ptr;
}

/*Function name:Systick_Handler
 * Description: Systick configurable service routine
 * I/P arguments:
 * 				void
 *				return:void
 */
void SysTick_Handler(void)
{
	if(STK_CallBack!=NULL)
	{
		STK_CallBack();
	}
}

void SYSTICK_voidSetIntervalPeriodic(u32 A_u32Ticks,void(*CallbackFunction)(void))
{
	/* 0- set Callback function */
	STK_CallBack = CallbackFunction;
	/* 1- Load timer with Value */
	STK->STK_LOAD = A_u32Ticks*MILLI_SCALE-1;
	/* 2- reset timer value */
	STK->STK_VAL = 0;
	/*3- Start the timer */
	SET_BIT(STK->STK_CTRL, ENABLE);
}




