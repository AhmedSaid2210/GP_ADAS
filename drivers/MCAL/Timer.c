/*
 * Timer.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#include "Timer.h"

Std_ReturnType MCAL_Timer_Inti(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             IntMasterDisable();

             SysCtlPeripheralEnable(timer->SYSCTL_PERIPH_TIMER);

             while(!SysCtlPeripheralReady(timer->SYSCTL_PERIPH_TIMER)){}

             TimerClockSourceSet(timer->TIMER_BASE, timer->TIMER_CLOCK);

             TimerConfigure(timer->TIMER_BASE, (timer->TIMER_CFG));

             TimerLoadSet(timer->TIMER_BASE, timer->TIMER_A_B_BOTH, timer->TIMER_LOAD);

             TimerPrescaleSet(timer->TIMER_BASE, timer->TIMER_A_B_BOTH, timer->TIMER_PRESCALLER);

             IntPrioritySet(timer->INT_TIMER, timer->PRI);

             TimerIntClear(timer->TIMER_BASE, timer->TIMER_INT_STATUS);

             TimerIntEnable(timer->TIMER_BASE, timer->TIMER_INT_STATUS);

             IntEnable(timer->INT_TIMER);

             IntMasterEnable();
         }
         return ret;
}

Std_ReturnType MCAL_Timer_Inti_CAP(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             IntMasterDisable();

             uint32_t  port_enable = 0;

                        switch(timer->PORT)
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

						 while(!SysCtlPeripheralReady(port_enable)) {  /* Nothing */}
						 
             GPIOPinTypeTimer(timer->PORT, timer->PIN);

             SysCtlPeripheralEnable(timer->SYSCTL_PERIPH_TIMER);

             while(!SysCtlPeripheralReady(timer->SYSCTL_PERIPH_TIMER)){}

             GPIOPinConfigure(timer->TnCCPn);

             TimerConfigure(timer->TIMER_BASE, (timer->TIMER_CFG));

             TimerClockSourceSet(timer->TIMER_BASE, timer->TIMER_CLOCK);

             TimerLoadSet(timer->TIMER_BASE, timer->TIMER_A_B_BOTH, timer->TIMER_LOAD);


            // IntRegister(timer->INT_TIMER , fun );

             IntPrioritySet(timer->INT_TIMER, timer->PRI);

             TimerIntClear(timer->TIMER_BASE, timer->TIMER_INT_STATUS);

             TimerIntEnable(timer->TIMER_BASE, timer->TIMER_INT_STATUS);

             IntEnable(timer->INT_TIMER);


             //TimerEnable(timer->TIMER_BASE, timer->TIMER_A_B_BOTH);

             IntMasterEnable();
         }
         return ret;
}
Std_ReturnType MCAL_Timer_SET_PRESCALLER(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             TimerPrescaleSet(timer->TIMER_BASE, timer->TIMER_A_B_BOTH, timer->TIMER_PRESCALLER);
         }
         return ret;
}
Std_ReturnType MCAL_Timer_SET_MATCH(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             TimerMatchSet(timer->TIMER_BASE, timer->TIMER_A_B_BOTH, timer->TIMER_MATCH);
         }
         return ret;
}
Std_ReturnType MCAL_Timer_SET_EVENT(timer_t *timer , uint32_t event)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             TimerControlEvent(timer->TIMER_BASE, timer->TIMER_A_B_BOTH, event);
         }
         return ret;
}
Std_ReturnType MCAL_Timer_SET_LOAD(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             TimerLoadSet(timer->TIMER_BASE, timer->TIMER_A_B_BOTH, timer->TIMER_LOAD);
         }
         return ret;
}
uint32_t MCAL_Timer_GET_VALUE(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             return TimerValueGet(timer->TIMER_BASE, timer->TIMER_A_B_BOTH);
         }
         return ret;
}
Std_ReturnType MCAL_Timer_Start(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             TimerEnable(timer->TIMER_BASE, timer->TIMER_A_B_BOTH);

         }
         return ret;
}
Std_ReturnType MCAL_Timer_Stop(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             TimerDisable(timer->TIMER_BASE, timer->TIMER_A_B_BOTH);

         }
         return ret;
}
Std_ReturnType MCAL_Timer_IntClear(timer_t *timer)
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             TimerIntClear(timer->TIMER_BASE ,timer->TIMER_INT_STATUS);

         }
         return ret;
}

Std_ReturnType MCAL_Timer_Int_handler(timer_t *timer,void (*fun)(void))
{
    Std_ReturnType ret = E_OK;
         if(NULL == timer)
         {
             ret = E_NOT_OK;
         }
         else
         {
             IntRegister(timer->INT_TIMER , fun );

         }
         return ret;
}
