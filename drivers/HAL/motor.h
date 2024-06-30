/*
 * motor.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef MOTOR_H_
#define MOTOR_H_


/******************************** Section :Includes start *****************************/
#include "GPIO_Config.h"
#include "delay.h"
#include "PWM_Config.h"
#include "delay.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/


/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
typedef struct
{
   const pin_t *motor1_pin1;
	 const pin_t *motor1_pin2;
				 PWM_t *motor1_enable;
	
	 const pin_t *motor2_pin1;
	 const pin_t *motor2_pin2;
			   PWM_t *motor2_enable;
	
}motor_t;

/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType HAL_DC_MOTOR_INIT(motor_t *motor);
/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_ControlSpeed(motor_t *motor,uint32_t dutyCycle);
/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_ControlSpeedRight(motor_t *motor,uint32_t dutyCycle);
/**
 * @brief This function for ultrasonic  .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_ControlSpeedLift(motor_t *motor,uint32_t dutyCycle);

/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_MOVE_FORWARD(motor_t *motor);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_MOVE_BACKWARD(motor_t *motor);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_MOVE_FORWARD_RIGHT(motor_t *motor);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_MOVE_FORWARD_LEFT(motor_t *motor);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_MOVE_BACKWARD_RIGHT(motor_t *motor);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTOR_MOVE_BACKWARD_LEFT(motor_t *motor);
/**
 * @brief This function for ultrasonic .
 *
 * @param ultra The variable initialize by user contain config of ultrasonic .
 * @param dist The variable initialize by user and return distance in it  .

 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_DC_MOTORS_OFF(motor_t *motor);

/*********************************Section: Functions Declarations end *****************/




#endif /* MOTOR_H_ */
