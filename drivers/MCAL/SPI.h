/*
 * SPI.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef SPI_H_
#define SPI_H_





/******************************** Section :Includes start *****************************/
#include "GPIO.h"
#include "driverlib/ssi.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/

/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
 typedef struct
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



/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for PWM  .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType MCAL_SSI_Inti(SSI_t *SSI);
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_SSI_SendData(SSI_t *SSI , uint8_t  SendData );
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_SSI_ReceiveData(SSI_t *SSI , uint32_t * ReceiveData );

/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_SSI_SendReceiveSynch(SSI_t *SSI ,uint8_t  SendData , uint32_t * ReceiveData );

/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_SSI_SendArray(SSI_t *SSI , uint8_t * SendData ,uint8_t len);
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_SSI_ReceiveArray(SSI_t *SSI , uint8_t * ReceiveData , uint8_t len );
/*********************************Section: Functions Declarations end *****************/

#endif /* SPI_H_ */
