/*
 * SPI_Config.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#include "SPI.h"


/**
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

 * **********  SYSCTL_PERIPH_SSIn ***********
  SYSCTL_PERIPH_SSI0        // SSI 0
  SYSCTL_PERIPH_SSI1        // SSI 1
  SYSCTL_PERIPH_SSI2        // SSI 2
  SYSCTL_PERIPH_SSI3        // SSI 3

 * **********  SSIn_BASE ***********
 SSI0_BASE                 // SSI0
 SSI1_BASE                 // SSI1
 SSI2_BASE                 // SSI2
 SSI3_BASE                 // SSI3
 *
 *
*****************************************************************************
//
// Values that can be passed to SSIConfigSetExpClk.
//
*****************************************************************************
 *
 * * **********  SSI_MODE ***********
 *
 SSI_MODE_MASTER           // SSI master
 SSI_MODE_SLAVE            // SSI slave
 SSI_MODE_SLAVE_OD         // SSI slave with output disabled

  * * **********  SSI_FRF_MOTO_MODE ***********

 SSI_FRF_MOTO_MODE_0       // Moto fmt, polarity 0, phase 0   read then write
 SSI_FRF_MOTO_MODE_1       // Moto fmt, polarity 0, phase 1		write then read
 SSI_FRF_MOTO_MODE_2       // Moto fmt, polarity 1, phase 0
 SSI_FRF_MOTO_MODE_3       // Moto fmt, polarity 1, phase 1


* **********  SSI0 ***********

GPIO_PA2_SSI0CLK
GPIO_PA3_SSI0FSS
GPIO_PA4_SSI0RX
GPIO_PA5_SSI0TX

* **********  SSI1 ***********
*
GPIO_PD0_SSI1CLK
GPIO_PD1_SSI1FSS
GPIO_PD2_SSI1RX
GPIO_PD3_SSI1TX

GPIO_PF0_SSI1RX
GPIO_PF1_SSI1TX
GPIO_PF2_SSI1CLK
GPIO_PF3_SSI1FSS


* **********  SSI2 ***********

GPIO_PB4_SSI2CLK
GPIO_PB5_SSI2FSS
GPIO_PB6_SSI2RX
GPIO_PB7_SSI2TX

* **********  SSI3 ***********
GPIO_PD0_SSI3CLK
GPIO_PD1_SSI3FSS
GPIO_PD3_SSI3TX
GPIO_PD2_SSI3RX



 *
 *
 * typedef struct
{
    uint32_t   PORT                  ;   // port address

    uint32_t   PINS                  ;   // port pins

    uint32_t   SYSCTL_PERIPH_SSIn    ;   // SYSCTL_PERIPH_SSI

    uint32_t   SSIn_BASE             ;   // SSIn_BASE

    uint32_t   SSI_MODE              ;   // SSI_MODE

    uint32_t   SSI_FRF_MOTO_MODE     ;   // SSI_FRF_MOTO_MODE

    uint32_t   SSInCLK               ;   // clock

    uint32_t   SSInFSS               ;   // ship select

    uint32_t   SSInRX                ;   // receive

    uint32_t   SSInTX                ;   // transmitte

    uint32_t   BitRate               ;   // max 2MHz

    uint32_t   DataWidth             ;   // 8 ,16 ,32 bits


}SSI_t;
 */

SSI_t SPI_config = {
                 PORT_A,
                 PIN_2|PIN_3|PIN_4|PIN_5,
                 SYSCTL_PERIPH_SSI0,
                 SSI0_BASE,
                 SSI_MODE_SLAVE,
                 SSI_FRF_MOTO_MODE_1,
                 GPIO_PA2_SSI0CLK,
                 GPIO_PA3_SSI0FSS,
                 GPIO_PA4_SSI0RX,
                 GPIO_PA5_SSI0TX,
                 9600,
                 8
};
SSI_t SPI_config1 = {
                 PORT_F,
                 PIN_2|PIN_3|PIN_0|PIN_1,
                 SYSCTL_PERIPH_SSI1,
                 SSI1_BASE,
                 SSI_MODE_SLAVE,
                 SSI_FRF_MOTO_MODE_1,
                 GPIO_PF2_SSI1CLK,
                 GPIO_PF3_SSI1FSS,
                 GPIO_PF0_SSI1RX,
                 GPIO_PF1_SSI1TX,
                 9600,
                 8
};
SSI_t SPI_config2 = {
                 PORT_B,
                 PIN_4|PIN_5|PIN_6|PIN_7,
                 SYSCTL_PERIPH_SSI2,
                 SSI2_BASE,
                 SSI_MODE_SLAVE,
                 SSI_FRF_MOTO_MODE_0,
                 GPIO_PB4_SSI2CLK,
                 GPIO_PB5_SSI2FSS,
                 GPIO_PB6_SSI2RX,
                 GPIO_PB7_SSI2TX,
                 9600,
                 8
};
SSI_t SPI_config3 = {
                 PORT_D,
                 PIN_0|PIN_1|PIN_2|PIN_3,
                 SYSCTL_PERIPH_SSI3,
                 SSI3_BASE,
                 SSI_MODE_SLAVE,
                 SSI_FRF_MOTO_MODE_0,
                 GPIO_PD0_SSI3CLK,
                 GPIO_PD1_SSI3FSS,
                 GPIO_PD2_SSI3RX,
                 GPIO_PD3_SSI3TX,
                 9600,
                 8
};

