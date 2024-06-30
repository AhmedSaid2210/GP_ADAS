/*
 * delay.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */


#include "delay.h"


Std_ReturnType MCAL_DelayMs(uint32_t ui32Ms)
{
    Std_ReturnType ret = E_OK;
       if( 0 == ui32Ms)
       {
           ret = E_NOT_OK;
       }
       else
       {
				 	// 1 clock cycle = 1 / SysCtlClockGet() second
					// 1 SysCtlDelay = 3 clock cycle = 3 / SysCtlClockGet() second
					// 1 second = SysCtlClockGet() / 3
					// 0.001 second = 1 ms = SysCtlClockGet() / (3 * 1000)
				 
				  uint32_t ui32Delay = (SysCtlClockGet() / 3000) * ui32Ms;
				 
						SysCtlDelay(ui32Delay);
           
       }
       return ret;

}


Std_ReturnType MCAL_DelayUs(uint32_t ui32Us)
{
    Std_ReturnType ret = E_OK;
       if(NULL == ui32Us)
       {
           ret = E_NOT_OK;
       }
       else
       {
				   SysCtlDelay(ui32Us * (SysCtlClockGet() / (3000000)));
       }
       return ret;

}

