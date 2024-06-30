/*
 * RCC.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */



#include "RCC.h"

Std_ReturnType MCAL_RCC_SysCtlClockInternal(const RCC_INT_t * RCC)
{
    Std_ReturnType ret = E_OK;
    if(NULL == RCC)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SysCtlClockSet(RCC->SYSCTL_OSC | RCC->SYSCTL_USE | RCC->SYSCTL_SYSDIV);
    }
    return ret;
}

Std_ReturnType MCAL_RCC_SysCtlClockExternal(const RCC_t * RCC)
{
    Std_ReturnType ret = E_OK;
    if(NULL == RCC)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SysCtlClockSet(RCC->SYSCTL_OSC | RCC->SYSCTL_XTAL | RCC->SYSCTL_USE | RCC->SYSCTL_SYSDIV);
    }
    return ret;
}

