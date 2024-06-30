/*
 * ultrasonic.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


/******************************** Section :Includes start *****************************/

#include "RCC_Config.h"
#include "GPIO_Config.h"
#include "Timer_Config.h"
#include "delay.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/



//*****************************************************************************
//
// The following are defines for the base address of the inturrpt
//
//************************************************************************************




/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
typedef struct
{
    pin_t *trig_pin;
	  pin_t *echo_pin;
		timer_t *timer;

}ultra_t;

/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType HAL_Ultra_Inti(ultra_t *ultra);

/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_Ultra_Dist(ultra_t *ultra ,uint32_t *dist );

/*********************************Section: Functions Declarations end *****************/




#endif /* ULTRASONIC_H_ */
