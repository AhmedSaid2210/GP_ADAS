/*
 *  motor_config.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef APPS_EINTERFACE_H_
#define APPS_EINTERFACE_H_


/******************************** Section :Includes start *****************************/
#include "RCC_Config.h"
#include "GPIO_Config.h"
#include "delay.h"

#include "IR_app.h"
#include "ultrasonic_app.h"
#include "communication.h"

#include <FreeRTOS.h>
#include <task.h>
/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/


/** Speed Macros **/
#define STOP 0
#define SPEED_25  400
#define SPEED_50  800
#define SPEED_65  1000
#define SPEED_75  1200
#define SPEED_85  1400
#define SPEED_100 1600

#define HIGHSPEED  SPEED_65
#define LOWSPEED   SPEED_50

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

void App_Init(void);
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
void App_Start(void);

State_t IdleMode(void);
State_t MovingHighSpeed_Mode(void);
State_t MovingLowSpeed_Mode(void);
/*********************************Section: Functions Declarations end *****************/




#endif /* APPS_EINTERFACE_H_ */
