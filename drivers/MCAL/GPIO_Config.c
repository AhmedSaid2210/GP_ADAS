/*
 * GPIO_config.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#include "GPIO.h"
/**
 * **********  Ports ***********
 PORT_A         // GPIO Port A (high speed)
 PORT_B         // GPIO Port B (high speed)
 PORT_C         // GPIO Port C (high speed)
 PORT_D         // GPIO Port D (high speed)
 PORT_E         // GPIO Port E (high speed)
 PORT_F         // GPIO Port F (high speed)

**********  Pins  ***********
 PIN_0                 // GPIO pin 0
 PIN_1                 // GPIO pin 1
 PIN_2                 // GPIO pin 2
 PIN_3                 // GPIO pin 3
 PIN_4                 // GPIO pin 4
 PIN_5                 // GPIO pin 5
 PIN_6                 // GPIO pin 6
 PIN_7                 // GPIO pin 7


**********  direction  ***********

 PIN_IN               // Pin is a GPIO input
 PIN_OUT              // Pin is a GPIO output


**********  Current  ***********
 CURRENT_2MA              // 2mA drive strength
 CURRENT_4MA              // 4mA drive strength
 CURRENT_6MA              // 6mA drive strength
 CURRENT_8MA              // 8mA drive strength

**********  pad type  ***********

 PIN_STD           // Push-pull
 PIN_PU            // Push-pull with weak pull-up
 PIN_PD            // Push-pull with weak pull-down



**********  Output Pin  ***********

 LOW      0x00    // Turn pin off
 HIGH     0x01    // Turn pin on
 TOGGLE   0x02    // Invert the pin

typedef struct
{
    uint8_t   port    ;   //port address
    uint8_t   pin     ;   //port pin
    uint8_t   dir     ;   //pin  direction
    uint32_t  current ;   //pin  maximum current
    uint32_t  type    ;   //pad  type
}pin_t;


typedef enum
{
    PIN_LOW = 0,
    PIN_HIGH

}pin_status_t;

 */
const pin_t pin_red ={
                   PORT_F,
                   PIN_1,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t pin_blue ={
                   PORT_F,
                   PIN_2,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t pin_green ={
                   PORT_F,
                   PIN_3,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t trig_pin ={
                   PORT_F,
                   PIN_2,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t echo_pin ={
                   PORT_F,
                   PIN_3,
                   PIN_IN,
                   CURRENT_2MA,
                   PIN_PD
};


const pin_t PA2 ={
                   PORT_A,
                   PIN_2,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PA3 ={
                   PORT_A,
                   PIN_3,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PA4 ={
                   PORT_A,
                   PIN_4,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PA5 ={
                   PORT_A,
                   PIN_5,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PA6 ={
                   PORT_A,
                   PIN_6,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PA7 ={
                   PORT_A,
                   PIN_7,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};


const pin_t PB0 ={
                   PORT_B,
                   PIN_0,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PB1 ={
                   PORT_B,
                   PIN_1,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PB4 ={
                   PORT_B,
                   PIN_4,
                   PIN_IN,
                   CURRENT_2MA,
                   PIN_PD
};
const pin_t PB5 ={
                   PORT_B,
                   PIN_5,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PB6 ={
                   PORT_B,
                   PIN_6,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PB7 ={
                   PORT_B,
                   PIN_7,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PC4 ={
                   PORT_C,
                   PIN_4,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PC5 ={
                   PORT_C,
                   PIN_5,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PC6 ={
                   PORT_C,
                   PIN_6,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PC7 ={
                   PORT_C,
                   PIN_7,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};

const pin_t PD0 ={
                   PORT_D,
                   PIN_0,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PD1 ={
                   PORT_D,
                   PIN_1,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PD2 ={
                   PORT_D,
                   PIN_2,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PD3 ={
                   PORT_D,
                   PIN_3,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};


const pin_t PD6 ={
                   PORT_D,
                   PIN_6,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};

const pin_t PD7 ={
                   PORT_D,
                   PIN_7,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PE0 ={
                   PORT_E,
                   PIN_0,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PE1 ={
                   PORT_E,
                   PIN_1,
                   PIN_IN,
                   CURRENT_2MA,
                   PIN_PD
};
const pin_t PE2 ={
                   PORT_E,
                   PIN_2,
                   PIN_IN,
                   CURRENT_2MA,
                   PIN_PD
};
const pin_t PE3 ={
                   PORT_E,
                   PIN_3,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PE4 ={
                   PORT_E,
                   PIN_4,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PE5 ={
                   PORT_E,
                   PIN_5,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};

const pin_t PF0 ={
                   PORT_F,
                   PIN_0,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PF1 ={
                   PORT_F,
                   PIN_1,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PF2 ={
                   PORT_F,
                   PIN_2,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_PD
};
const pin_t PF3 ={
                   PORT_F,
                   PIN_3,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};
const pin_t PF4 ={
                   PORT_F,
                   PIN_4,
                   PIN_OUT,
                   CURRENT_2MA,
                   PIN_STD
};

/**
 *
 * ********************************************  interrupt section *************************************************
 *
 *
 * **********  Ports ***********
 PORT_A         // GPIO Port A (high speed)
 PORT_B         // GPIO Port B (high speed)
 PORT_C         // GPIO Port C (high speed)
 PORT_D         // GPIO Port D (high speed)
 PORT_E         // GPIO Port E (high speed)
 PORT_F         // GPIO Port F (high speed)

**********  Pins  ***********
 PIN_0                 // GPIO pin 0
 PIN_1                 // GPIO pin 1
 PIN_2                 // GPIO pin 2
 PIN_3                 // GPIO pin 3
 PIN_4                 // GPIO pin 4
 PIN_5                 // GPIO pin 5
 PIN_6                 // GPIO pin 6
 PIN_7                 // GPIO pin 7

 **********  interrupt Ports  ***********
 INT_GPIOA
 INT_GPIOB
 INT_GPIOC
 INT_GPIOD
 INT_GPIOE
 INT_GPIOF

**********  priority  ***********

 0x00     high  priority
 0x20
 0x40
 0x60
 0x80
 0xA0
 0xC0
 0xE0     low priority

 **********  interrupt type  ***********

 GPIO_FALLING_EDGE         // Interrupt on falling edge
 GPIO_RISING_EDGE          // Interrupt on rising edge
 GPIO_BOTH_EDGES           // Interrupt on both edges
 GPIO_LOW_LEVEL            // Interrupt on low level
 GPIO_HIGH_LEVEL           // Interrupt on high level
 GPIO_DISCRETE_INT         // Interrupt for individual pins

 typedef struct
{
    uint32_t   port            ;   // port address
    uint32_t   pin             ;   // port pin
    uint32_t   Int_port        ;   // interrupt port address
    uint32_t   pri             ;   // priority
    uint32_t   Int_type        ;   // interrupt type


}Int_pin_t;
*/




