/*
 * UART_Config.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#include "UART.h"



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
 SYSCTL_PERIPH_UART0       // UART 0
 SYSCTL_PERIPH_UART1       // UART 1
 SYSCTL_PERIPH_UART2       // UART 2
 SYSCTL_PERIPH_UART3       // UART 3
 SYSCTL_PERIPH_UART4       // UART 4
 SYSCTL_PERIPH_UART5       // UART 5
 SYSCTL_PERIPH_UART6       // UART 6
 SYSCTL_PERIPH_UART7 			 // UART 7

 * **********  SSIn_BASE ***********
 UART0_BASE                // UART0
 UART1_BASE                // UART1
 UART2_BASE                // UART2
 UART3_BASE                // UART3
 UART4_BASE                // UART4
 UART5_BASE                // UART5
 UART6_BASE                // UART6
 UART7_BASE                // UART7
 *
 *
*****************************************************************************
//
// Values that can be passed to UARTConfigSetExpClk as the ui32Config parameter
// and returned by UARTConfigGetExpClk in the pui32Config parameter.
// Additionally, the UART_CONFIG_PAR_* subset can be passed to
// UARTParityModeSet as the ui32Parity parameter, and are returned by
// UARTParityModeGet.
//
//*****************************************************************************
 UART_CONFIG_WLEN_MASK     // Mask for extracting word length
 UART_CONFIG_WLEN_8        // 8 bit data
 UART_CONFIG_WLEN_7        // 7 bit data
 UART_CONFIG_WLEN_6        // 6 bit data
 UART_CONFIG_WLEN_5        // 5 bit data
 UART_CONFIG_STOP_MASK     // Mask for extracting stop bits
 UART_CONFIG_STOP_ONE      // One stop bit
 UART_CONFIG_STOP_TWO      // Two stop bits
 UART_CONFIG_PAR_MASK      // Mask for extracting parity
 UART_CONFIG_PAR_NONE      // No parity
 UART_CONFIG_PAR_EVEN      // Even parity
 UART_CONFIG_PAR_ODD       // Odd parity
 UART_CONFIG_PAR_ONE       // Parity bit is one
 UART_CONFIG_PAR_ZERO      // Parity bit is zero

* **********  UART7 ***********
 GPIO_PE0_U7RX           

 GPIO_PE1_U7TX           


 *
 *
 typedef struct
{
    uint32_t   PORT                   ;   // port address
  
    uint32_t   PINS                   ;   // port pins

    uint32_t   SYSCTL_PERIPH_UARTn    ;   // SYSCTL_PERIPH_SSI

    uint32_t   UARTn_BASE             ;   // SSIn_BASE

    uint32_t   GPIO_Pin_UnRX          ;   // SSI_MODE

    uint32_t   GPIO_Pin_UnTX          ;   // SSI_FRF_MOTO_MODE

    uint32_t   UART_CONFIGS           ;   // clock

    uint32_t   baudRate                ;   // max 2MHz

}UART_t;
 */

UART_t UART_Config = {
                 PORT_E,
                 PIN_0|PIN_1,
                 SYSCTL_PERIPH_UART7,
                 UART7_BASE,
                 GPIO_PE0_U7RX,
                 GPIO_PE1_U7TX,
                 (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE),
                 9600
                 
};
