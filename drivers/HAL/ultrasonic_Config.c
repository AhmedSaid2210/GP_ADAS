
/*
 * Timer_Config.c
 *
 *  Created on: ???/???/????
 *      Author: Ahmed Said
 */

#include "ultrasonic.h"
/*
typedef struct
{
    pin_t trig_pin;
	  pin_t echo_pin;
		timer_t timer;

}ultra_t;
*/

ultra_t ultra1 =
{
	&PA6,
	&PB4,
	&timer1A
};
ultra_t ultra2 =
{
	&PA6,
	&PB5,
	&timer1B
};