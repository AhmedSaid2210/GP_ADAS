/*
 * GPIO.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef GPIO_H_
#define GPIO_H_



/******************************** Section :Includes start *****************************/

#include "Std_Types.h"
#include "Std_Macros.h"
#include "pin_map.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"



 

/******************************** Section :Includes end *******************************/

/******************************** Section: Macro Declarations start *******************/

//**********  Ports ***********
#define PORT_A   GPIO_PORTA_BASE       // GPIO Port A (high speed)
#define PORT_B   GPIO_PORTB_BASE       // GPIO Port B (high speed)
#define PORT_C   GPIO_PORTC_BASE       // GPIO Port C (high speed)
#define PORT_D   GPIO_PORTD_BASE       // GPIO Port D (high speed)
#define PORT_E   GPIO_PORTE_BASE       // GPIO Port E (high speed)
#define PORT_F   GPIO_PORTF_BASE       // GPIO Port F (high speed)

//**********  Pins  ***********
#define PIN_0   GPIO_PIN_0               // GPIO pin 0
#define PIN_1   GPIO_PIN_1               // GPIO pin 1
#define PIN_2   GPIO_PIN_2               // GPIO pin 2
#define PIN_3   GPIO_PIN_3               // GPIO pin 3
#define PIN_4   GPIO_PIN_4               // GPIO pin 4
#define PIN_5   GPIO_PIN_5               // GPIO pin 5
#define PIN_6   GPIO_PIN_6               // GPIO pin 6
#define PIN_7   GPIO_PIN_7               // GPIO pin 7


//**********  direction  ***********

#define PIN_IN     GPIO_DIR_MODE_IN          // Pin is a GPIO input
#define PIN_OUT    GPIO_DIR_MODE_OUT         // Pin is a GPIO output


//**********  Current  ***********
#define CURRENT_2MA     GPIO_STRENGTH_2MA         // 2mA drive strength
#define CURRENT_4MA     GPIO_STRENGTH_4MA         // 4mA drive strength
#define CURRENT_6MA     GPIO_STRENGTH_6MA         // 6mA drive strength
#define CURRENT_8MA     GPIO_STRENGTH_8MA         // 8mA drive strength

//**********  pad type  ***********

#define PIN_STD      GPIO_PIN_TYPE_STD         // Push-pull
#define PIN_PU       GPIO_PIN_TYPE_STD_WPU     // Push-pull with weak pull-up
#define PIN_PD       GPIO_PIN_TYPE_STD_WPD     // Push-pull with weak pull-down



//**********  Output Pin  ***********

#define LOW      0x00    // Turn pin off
#define HIGH     0x01    // Turn pin on
#define TOGGLE   0x02    // Invert the pin



/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/


/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
typedef struct
{
    uint32_t   port    ;   //port address
    uint32_t   pin     ;   //port pin
    uint32_t   dir     ;   //pin  direction
    uint32_t   current ;   //pin  maximum current
    uint32_t   type    ;   //pad  type
}pin_t;


typedef enum
{
    PIN_LOW = 0,
    PIN_HIGH

}pin_status_t;

typedef struct
{
    uint32_t   port            ;   // port address
    uint32_t   pin             ;   // port pin
    uint32_t   Int_port        ;   // interrupt port address
    uint8_t    pri             ;   // priority
    uint32_t   Int_type        ;   // interrupt type

}Int_pin_t;

/******************************** Section: Data Type Declarations end *****************/




/*********************************Section: Functions Declarations start ***************/

/**
 * @brief  This function used to initialize pin .
 *
 * @param  the variable from type pin_t initialize by user contain config of pin .
 *
 * @return E_OK if success function or E_NOT_OK if error function .
 */

Std_ReturnType MCAL_GPIO_Pin_Init(const pin_t *pin);

/**
 * @brief  This function writes the specified value to the pin .
 *
 * @param  the variable from type pin_t initialize by user contain config of pin .
 * @param  the variable from type uint8_t initialize by user contain logic of pin .
 *
 * @return E_OK if success function or E_NOT_OK if error function .
 */

Std_ReturnType MCAL_GPIO_Pin_Write(const pin_t *pin , uint8_t logic);

/**
 * @brief  This function reads the value of the pin .
 *
 * @param  the variable from type pin_t initialize by user contain config of pin .
 * @param  the variable from type pin_status write in it status of pin  .
 *
 * @return E_OK if success function or E_NOT_OK if error function .
 */

uint8_t MCAL_GPIO_Pin_Read(const pin_t *pin );

/**
 * @brief This function for interrupt  .
 *
 * @param Int_pin The variable initialize by user contain config of interrupt.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_GPIO_Int_Config(const Int_pin_t *Int_pin , void (*fun)(void));

/*********************************Section: Functions Declarations end *****************/






#endif /* GPIO_H_ */
