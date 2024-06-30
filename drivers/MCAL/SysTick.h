/*
 * SysTick.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
/******************************** Section :Includes start *****************************/

#include "inc/hw_ints.h"
#include "Std_Types.h"
#include "inc/hw_types.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "inc/hw_nvic.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/
/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/


/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for SysTick  .
 *
 * @param Int_pin The variable initialize by user contain config of SysTick interrupt.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_SysTick_Int_handler(uint32_t ui32Ms, void (*fun)(void));

/*********************************Section: Functions Declarations end *****************/





#endif /* SYSTICK_H_ */
