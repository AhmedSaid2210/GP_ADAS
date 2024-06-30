/*
 * Timer.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef TIMER_H_
#define TIMER_H_


/******************************** Section :Includes start *****************************/
#include "GPIO.h"
#include "inc/hw_timer.h"
#include "driverlib/timer.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/



//*****************************************************************************
//
// The following are defines for the base address of the inturrpt
//
//************************************************************************************


#define INT_TIMER0A     35          // 16/32-Bit Timer 0A
#define INT_TIMER0B     36          // 16/32-Bit Timer 0B
#define INT_TIMER1A     37          // 16/32-Bit Timer 1A
#define INT_TIMER1B     38          // 16/32-Bit Timer 1B
#define INT_TIMER2A     39          // 16/32-Bit Timer 2A
#define INT_TIMER2B     40          // 16/32-Bit Timer 2B
#define INT_TIMER3A     51          // 16/32-Bit Timer 3A
#define INT_TIMER3B     52          // Timer 3B
#define INT_TIMER4A     86          // 16/32-Bit Timer 4A
#define INT_TIMER4B     87          // 16/32-Bit Timer 4B
#define INT_TIMER5A     108         // 16/32-Bit Timer 5A
#define INT_TIMER5B     109         // 16/32-Bit Timer 5B

#define INT_WTIMER0A    110         // 32/64-Bit Timer 0A
#define INT_WTIMER0B    111         // 32/64-Bit Timer 0B
#define INT_WTIMER1A    112         // 32/64-Bit Timer 1A
#define INT_WTIMER1B    113         // 32/64-Bit Timer 1B
#define INT_WTIMER2A    114         // 32/64-Bit Timer 2A
#define INT_WTIMER2B    115         // 32/64-Bit Timer 2B
#define INT_WTIMER3A    116         // 32/64-Bit Timer 3A
#define INT_WTIMER3B    117         // 32/64-Bit Timer 3B
#define INT_WTIMER4A    118         // 32/64-Bit Timer 4A
#define INT_WTIMER4B    119         // 32/64-Bit Timer 4B
#define INT_WTIMER5A    120         // 32/64-Bit Timer 5A
#define INT_WTIMER5B    121         // 32/64-Bit Timer 5B


/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
typedef struct
{
    uint32_t   PORT                  ;   // port address
    uint32_t   PIN                   ;   // port pin
    uint32_t   SYSCTL_PERIPH_TIMER   ;   // interrupt port address
    uint8_t    PRI                   ;   // priority
    uint32_t   TIMER_BASE            ;   // timer from 0 to 5
    uint32_t   TIMER_CFG             ;   // TIMER_CFG config
    uint32_t   TIMER_CLOCK           ;   // clock source
    uint32_t   TIMER_A_B_BOTH        ;   // timer A or B or BOTH
    uint32_t   TIMER_INT_STATUS      ;   // interrupt source
    uint32_t   TnCCPn                ;   // pin number
    uint32_t   INT_TIMER             ;   // interrupt timer
    uint32_t   TIMER_PRESCALLER      ;   // PRESCALLER value
    uint32_t   TIMER_LOAD            ;   // LOAD value
    uint32_t   TIMER_MATCH           ;   // MATCH value

}timer_t;

/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for Timer initialization  .
 *
 * @param timer The variable initialize by user contain config of timer .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType MCAL_Timer_Inti(timer_t *timer);

/**
 * @brief This function for Timer initialization .
 *
 * @param timer The variable initialize by user contain config of timer.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_Timer_Inti_CAP(timer_t *timer);
/**
 * @brief This function for Timer PRESCALLER .
 *
 * @param timer The variable initialize by user contain config of timer.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_Timer_SET_PRESCALLER(timer_t *timer);
/**
 * @brief This function for Timer MATCH  .
 *
 * @param timer The variable initialize by user contain config of timer.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType MCAL_Timer_SET_MATCH(timer_t *timer);

/**
 * @brief This function for Timer EVENT .
 *
 * @param timer The variable initialize by user contain config of timer.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_Timer_SET_EVENT(timer_t *timer , uint32_t event);
/**
 * @brief This function for Timer value .
 *
 * @param timer The variable initialize by user contain config of timer .
 *
 * @return timer value
 */
uint32_t MCAL_Timer_GET_VALUE(timer_t *timer);
/**
 * @brief This function for Timer load .
 *
 * @param timer The variable initialize by user contain config of timer.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_Timer_SET_LOAD(timer_t *timer);
/**
 * @brief This function for Timer Start .
 *
 * @param timer The variable initialize by user contain config of SysTick interrupt.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_Timer_Start(timer_t *timer);

/**
 * @brief This function for Stop Timer  .
 *
 * @param timer The variable initialize by user contain config of Timer .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_Timer_Stop(timer_t *timer);
/**
 * @brief This function for Timer interrupt Clear  .
 *
 * @param timer The variable initialize by user contain config of Timer .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_Timer_IntClear(timer_t *timer);
/**
 * @brief This function for Timer interrupt handler
 *
 * @param timer The variable initialize by user contain config of Timer interrupt.
 * @param fun The function initialize by user contain the code to execute when interrupt of timer occur .
 
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_Timer_Int_handler(timer_t *timer,void (*fun)(void));

/*********************************Section: Functions Declarations end *****************/





#endif /* TIMER_H_ */
