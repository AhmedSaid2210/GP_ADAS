/*
 * delay.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef DELAY_H_
#define DELAY_H_



/******************************** Section :Includes start *****************************/
#include "Std_Types.h"
#include "driverlib/sysctl.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/
/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/

/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/

/**
 * @brief This function for Delay Ms .
 *
 * @param ui32Ms The variable initialize by user contain time for delay.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_DelayMs(uint32_t ui32Ms);

/**
 * @brief This function for Delay Us .
 *
 * @param ui32Us The variable initialize by user contain time for delay.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_DelayUs(uint32_t ui32Us);



/*********************************Section: Functions Declarations end *****************/




#endif /* DELAY_H_ */
