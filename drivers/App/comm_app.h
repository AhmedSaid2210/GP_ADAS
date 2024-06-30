/*
 *  motor_config.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef COMM_APP_H_
#define COMM_APP_H_


/******************************** Section :Includes start *****************************/
#include "SPI_Config.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/


/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/


/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/

/**
 * @brief This function for PWM  .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_Communication_Inti(void);
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_Communication_Send_Receive(uint32_t SendData , uint32_t *ReceiveData);
/*********************************Section: Functions Declarations end *****************/




#endif /* COMM_APP_H_ */
