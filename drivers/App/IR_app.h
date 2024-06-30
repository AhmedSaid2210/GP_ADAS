/*
 * ultrasonic.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef IR_APP_H_
#define IR_APP_H_


/******************************** Section :Includes start *****************************/
#include "Std_Types.h"
#include "IR_Config.h"
#include "motor_Config.h"
#include "delay.h"
/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/
/** IR Macros **/
#define WHITE				      0
#define BLACK			      	1
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
Std_ReturnType APP_IR_Actions(uint32_t RightValue, uint32_t LeftValue);



/*********************************Section: Functions Declarations end *****************/




#endif /* IR_APP_H_ */
