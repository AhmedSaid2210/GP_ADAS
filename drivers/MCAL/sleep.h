/*
 * SysTick.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef SPEEP_H_
#define SPEEP_H_
/******************************** Section :Includes start *****************************/

#include "Std_Types.h"
#include "driverlib/sysctl.h"
#include "delay.h"
#include "SysTick.h"

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
Std_ReturnType MCAL_SleepMode(uint32_t ui32Ms);
/**
 * @brief This function for SysTick  .
 *
 * @param Int_pin The variable initialize by user contain config of SysTick interrupt.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_DeepSleepMode(uint32_t ui32Ms);


/*********************************Section: Functions Declarations end *****************/





#endif /* SPEEP_H_ */
