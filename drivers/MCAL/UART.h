/*
 * UART.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef UART_H_
#define UART_H_





/******************************** Section :Includes start *****************************/
#include "GPIO.h"
#include "driverlib/uart.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/

/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
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



/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for PWM  .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType MCAL_UART_Inti(UART_t *uart);
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_UART_SendData(UART_t *uart , uint8_t  SendData );
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_UART_ReceiveData(UART_t *uart , uint8_t * ReceiveData );

/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_UART_SendArry(UART_t *uart , uint8_t *SendData, uint8_t len  );

/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_UART_ReceiveArry(UART_t *uart , uint8_t * ReceiveData ,uint8_t len );

/*********************************Section: Functions Declarations end *****************/


#endif /* UART_H_ */
