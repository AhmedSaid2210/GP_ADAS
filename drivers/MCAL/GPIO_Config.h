/*
 * GPIO_config.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_





/******************************** Section :Includes start *****************************/
#include "GPIO.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/
/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/

/******************************** Section: Data Type Declarations end *****************/

extern const pin_t pin_red   ;
extern const pin_t pin_blue  ;
extern const pin_t pin_green ;
extern const pin_t trig_pin  ;
extern const pin_t echo_pin  ;

extern const pin_t PA6;
extern const pin_t PA7;
extern const pin_t PA2;
extern const pin_t PA3;
extern const pin_t PA4;
extern const pin_t PA5;

extern const pin_t PB0 ;
extern const pin_t PB1 ;
extern const pin_t PB4 ;
extern const pin_t PB5 ;
extern const pin_t PB6 ;
extern const pin_t PB7 ;

extern const pin_t PC4 ;
extern const pin_t PC5 ;
extern const pin_t PC6 ;
extern const pin_t PC7 ;

extern const pin_t PD0 ;
extern const pin_t PD1 ;
extern const pin_t PD2 ;
extern const pin_t PD3 ;
extern const pin_t PD6 ;
extern const pin_t PD7 ;

extern const pin_t PE0;
extern const pin_t PE1 ;
extern const pin_t PE2 ;
extern const pin_t PE3 ;
extern const pin_t PE4;
extern const pin_t PE5;

extern const pin_t PF0 ;
extern const pin_t PF1 ;
extern const pin_t PF2 ;
extern const pin_t PF3 ;
extern const pin_t PF4 ;
// *******************************  interrupt section **********************************

extern const Int_pin_t int_portf_4;



/*********************************Section: Functions Declarations start ***************/




/*********************************Section: Functions Declarations end *****************/




#endif /* GPIO_CONFIG_H_ */
