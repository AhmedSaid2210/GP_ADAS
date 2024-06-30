/*
 * SPI.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_





/******************************** Section :Includes start *****************************/
#include "SPI_Config.h"
#include "UART_Config.h"

/******************************** Section :Includes end *******************************/




/******************************** Section: Data Type Declarations end *****************/
#define SPI


typedef struct Message_Frame{
    uint8_t start;
    uint8_t instruction;
    uint8_t Data_length;
    uint8_t start_data;
    uint8_t Data;
    uint8_t Checksum;
    uint8_t stop;
}message_t ;

/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for PWM  .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType HAL_Comm_Inti(void);
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_Comm_SendFrame(uint8_t * SendData );
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_Comm_ReceiveFrame(uint8_t * ReceiveData );
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
uint8_t HAL_Comm_CheckSum_Generator(uint8_t Data );
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType HAL_Comm_CheckFrame( uint8_t * ReceiveData );

/*********************************Section: Functions Declarations end *****************/


#endif /* COMMUNICATION_H_ */
