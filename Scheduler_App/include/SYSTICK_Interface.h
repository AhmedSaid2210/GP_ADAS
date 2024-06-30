/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : AHMED KHLAED ANWAR
MICRO  : STM32F401CCU6
LAYER  : MCAL
DRIVER : SYSTICK DRIVER
FILE   : INTERFACE FILE
Version: 1.0
********************************************************************************************************
********************************************************************************************************
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_

/*Function name:SYSTICK_voidInit
 * Description: Initialise system timer interrupt and clock source
 * I/P arguments:
 * 				void
 *				return:Local_Error_State
 */
u8 SYSTICK_voidInit(void);

/*Function name:SYSTICK_voidSetPreloadValue
 * Description: Set the preload value
 * I/P arguments:
 * 				Copy_u32PreloadValue
 *				return:Local_Error_State
 */
void SYSTICK_voidSetPreloadValue(u32 Copy_u32PreloadValue);

/*Function name:SYSTICK_u32GetElapsedTime
 * Description: Get elapsed time
 * I/P arguments:
 * 				void
 *				return:Elapsed time in ticks
 */
u32 SYSTICK_u32GetElapsedTime(void);

/*Function name:SYSTICK_u32GetRemainingTime
 * Description: Get remaining time in ticks
 * I/P arguments:
 * 				void
 *				return:Remaining time in ticks
 */
u32 SYSTICK_u32GetRemainingTime(void);

/*Function name:SYSTICK_u8ReadFlag
 * Description: Returns 1 if timer counted to 0 since last time this was read.
 * I/P arguments:
 * 				void
 *				return: counter flag state
 */
u8  SYSTICK_u8ReadFlag(void);

/*Function name:SYSTICK_voidMicroSecondsDelay
 * Description: Enters the delay value in microseconds.
 * I/P arguments:
 * 				Copy_u32MicroDelayValue
 *				return:void
 */
void SYSTICK_voidMicroSecondsDelay(u32 Copy_u32MicroDelayValue);

/*Function name:SYSTICK_voidMilliSecondsDelay
 * Description: Enters the delay value in milliseconds.
 * I/P arguments:
 * 				Copy_u32MilliDelayValue
 *				return:void
 */

void SYSTICK_voidMilliSecondsDelay(u32 Copy_u32MilliDelayValue);

/*Function name:SYSTICK_voidSecondsDelay
 * Description: Enters the delay value in seconds.
 * I/P arguments:
 * 				Copy_u32SecondsDelayValue
 *				return:void
 */
void SYSTICK_voidSecondsDelay(u32 Copy_u32SecondsDelayValue);

/*Function name:SYSTICK_voidSetCallBack
 * Description: Function that sets a callback function to be executed when systick occ
 * I/P arguments:
 * 				void(*ptr)(void)
 *				return:void
 */
void SYSTICK_voidSetCallBack(void(*ptr)(void));

/*Function name:Systick_Handler
 * Description: Systick configurable service routine
 * I/P arguments:
 * 				void
 *				return:void
 */
void SysTick_Handler(void);


void SYSTICK_voidSetIntervalPeriodic(u32 A_u32Ticks,void(*CallbackFunction)(void));

#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
