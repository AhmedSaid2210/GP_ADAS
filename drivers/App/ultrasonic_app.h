/*
 *  motor_config.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef ULTRASONIC_APP_H_
#define ULTRASONIC_APP_H_


/******************************** Section :Includes start *****************************/
#include "Std_Types.h"
#include "ultrasonic_Config.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/
#define HighDistance		  60
#define LowDistance		    20

/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/


/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/


/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType App_Ultrasonic_Actions(State_t * mode , uint32_t dist );

/*********************************Section: Functions Declarations end *****************/




#endif /* ULTRASONIC_APP_H_ */
