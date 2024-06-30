/*
 * PWM.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */


#include "PWM.h"

/**
 * @brief This function for PWM  .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */

Std_ReturnType MCAL_PWM_Inti(PWM_t *PWM)
{
Std_ReturnType ret = E_OK;


        if(NULL == PWM)
        {
            ret = E_NOT_OK;
        }
        else
        {
            uint32_t  port_enable = 0;
                     switch(PWM->PORT)
                     {
                     case PORT_A:
                         port_enable = SYSCTL_PERIPH_GPIOA ;
                         break;
                     case PORT_B:
                         port_enable = SYSCTL_PERIPH_GPIOB ;
                         break;
                     case PORT_C:
                         port_enable = SYSCTL_PERIPH_GPIOC ;
                         break;
                     case PORT_D:
                         port_enable = SYSCTL_PERIPH_GPIOD ;
                         break;
                     case PORT_E:
                         port_enable = SYSCTL_PERIPH_GPIOE ;
                         break;
                     case PORT_F :
                         port_enable = SYSCTL_PERIPH_GPIOF ;
                         break;
                     default :
                         break;
                     }
            //SysCtlGPIOAHBEnable(port_enable);

            SysCtlPeripheralEnable(port_enable);
					if((PWM->PORT == PORT_F && PWM->PIN == PIN_0) || (PWM->PORT == PORT_D && PWM->PIN == PIN_7))
					{
						GPIOUnlockPin(PWM->PORT,PWM->PIN);
						
					}

            while(!SysCtlPeripheralReady(port_enable)) {  /* Nothing */}

            GPIOPinTypePWM(PWM->PORT, PWM->PIN);

            SysCtlPWMClockSet(PWM->PWM_SYSCLK_DIV);

            SysCtlPeripheralEnable(PWM->SYSCTL_PERIPH_PWM);

            while(!SysCtlPeripheralReady(PWM->SYSCTL_PERIPH_PWM)){}

            GPIOPinConfigure(PWM->MnPWMn);

            PWMGenConfigure(PWM->PWM_BASE,PWM->PWM_GEN,PWM->PWM_GEN_MODE );


            PWMGenPeriodSet(PWM->PWM_BASE,PWM->PWM_GEN, PWM->period);


            PWMGenEnable(PWM->PWM_BASE,PWM->PWM_GEN);

        }
        return ret;
}

/**
 * @brief This function start pwm  .
 *
 * @param PWM_t  The variable initialize by user contain config of PWM.
 * @param dutyCycle  The variable initialize by user contain dutyCycle of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_PWM_PulseWidthSet(PWM_t *PWM,uint32_t dutyCycle)
{
    Std_ReturnType ret = E_OK;
         if(NULL == PWM)
         {
             ret = E_NOT_OK;
         }
         else
         {
             PWMPulseWidthSet(PWM->PWM_BASE, PWM->PWM_OUT_n, dutyCycle);
         }
         return ret;
}

Std_ReturnType MCAL_PWM_Start(PWM_t *PWM)
{
    Std_ReturnType ret = E_OK;
         if(NULL == PWM)
         {
             ret = E_NOT_OK;
         }
         else
         {
            PWMOutputState(PWM->PWM_BASE, PWM->PWM_OUT_n_BIT ,true);
         }
         return ret;
}

/**
 * @brief This function stop pwm  .
 *
 * @param PWM_t The variable initialize by user contain config of PWM.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_PWM_Stop(PWM_t *PWM)
{
    Std_ReturnType ret = E_OK;
         if(NULL == PWM)
         {
             ret = E_NOT_OK;
         }
         else
         {
             PWMOutputState(PWM->PWM_BASE, PWM->PWM_OUT_n_BIT,false);

         }
         return ret;
}
