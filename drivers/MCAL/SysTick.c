/*
 * SysTick.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#include "SysTick.h"



Std_ReturnType MCAL_SysTick_Int_handler(uint32_t ui32Ms, void (*fun)(void))
{
       Std_ReturnType ret = E_OK;
       if(NULL == fun)
       {
           ret = E_NOT_OK;
       }
       else
       {
           IntMasterDisable();

           SysTickDisable();
				 
				   double Period = ( (double)ui32Ms /1000 ) * 16000000;
				 
           SysTickPeriodSet(Period);  // 1s  f = 1/16MHz   = 16 000 000 tick

           HWREG(NVIC_ST_CURRENT) = 0;

           IntRegister(FAULT_SYSTICK , fun );

           IntPrioritySet(FAULT_SYSTICK, 0x00);

           SysTickIntEnable();

           SysTickEnable();

           IntEnable(FAULT_SYSTICK);

           IntMasterEnable();
       }
       return ret;
}
