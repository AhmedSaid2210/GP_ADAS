/*
 * motor_config.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */



/******************************** Section :Includes start *****************************/
#include "motor.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/


/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
motor_t motor_config =
{
	&PC4,
	&PC5,        //motor 1
	&PF2_M1PWM6,
	
	&PC6,
	&PC7,        //motor 2
	&PF3_M1PWM7,
	
};


/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/


/*********************************Section: Functions Declarations end *****************/




