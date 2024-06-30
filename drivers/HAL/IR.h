/*
 * ultrasonic.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef IR_H_
#define IR_H_


/******************************** Section :Includes start *****************************/

#include "RCC_Config.h"
#include "GPIO_Config.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/


/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/


typedef struct
{
    pin_t *LeftIR;
	  pin_t *RightIR;
}IR_t;


/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType HAL_IR_Inti(IR_t *ir);

/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_IR_Read_RightIR(IR_t *ir ,uint8_t *val );
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_IR_Read_LeftIR(IR_t *ir ,uint8_t *val );
/*********************************Section: Functions Declarations end *****************/




#endif /* IR_H_ */
