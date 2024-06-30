/*
 *  motor_config.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef MOTOR_APP_H_
#define MOTOR_APP_H_


/******************************** Section :Includes start *****************************/
#include "motor_Config.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/


/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/


/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/

/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType APP_DC_MOTOR_INIT(void);

/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOR_ControlSpeed(uint32_t dutyCycle);
/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOR_ControlSpeedRight(uint32_t dutyCycle);
/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOR_ControlSpeedLift(uint32_t dutyCycle);

/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOR_MOVE_FORWARD(void);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOR_MOVE_BACKWARD(void);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOE_MOVE_FORWARD_RIGHT(void);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOE_MOVE_FORWARD_LEFT(void);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOR_MOVE_BACKWARD_RIGHT(void);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTOR_MOVE_BACKWARD_LEFT(void);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType APP_DC_MOTORS_OFF(void);
/*********************************Section: Functions Declarations end *****************/




#endif /* MOTOR_APP_H_ */
