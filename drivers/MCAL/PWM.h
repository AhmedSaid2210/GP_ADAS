/*
 * PWM.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef PWM_H_
#define PWM_H_




/******************************** Section :Includes start *****************************/
#include "GPIO.h"
#include "driverlib/pwm.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/

/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
typedef struct
{
    uint32_t   PORT                 ;   // port address

    uint32_t   PIN                  ;   // port pin

    uint32_t   SYSCTL_PERIPH_PWM    ;   // SYSCTL_PERIPH_PWM

    uint32_t   PWM_SYSCLK_DIV       ;   // PWM_SYSCLK_DIV

    uint32_t   PWM_BASE             ;   // PWM_BASE

    uint32_t   PWM_GEN              ;   // PWM_GEN

    uint32_t   PWM_GEN_MODE         ;   // PWM_GEN_MODE

    uint32_t   MnPWMn               ;   // MnPWMn

    uint32_t   PWM_OUT_n            ;   // PWM_OUT_n

    uint32_t   PWM_OUT_n_BIT        ;   // PWM_OUT_n_BIT

    uint32_t   period               ;   // period


}PWM_t;

/******************************** Section: Data Type Declarations end *****************/


/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function for PWM intitialization .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType MCAL_PWM_Inti(PWM_t *PWM);
/**
 * @brief This function set PulseWidth for pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_PWM_PulseWidthSet(PWM_t *PWM,uint32_t dutyCycle);
/**
 * @brief This function start pwm  .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType MCAL_PWM_Start(PWM_t *PWM);

/**
 * @brief This function stop pwm  .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_PWM_Stop(PWM_t *PWM);


/*********************************Section: Functions Declarations end *****************/




#endif /* PWM_H_ */
