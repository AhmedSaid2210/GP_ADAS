
#include "sleep.h"


void ISRfun(void);


Std_ReturnType MCAL_SleepMode(uint32_t ui32Ms)
{
	Std_ReturnType ret = E_OK;
  
	uint32_t priod = ui32Ms /1000 ;
	
	for(uint32_t i = 0 ; i < priod ;i++)
	{
		
		MCAL_SysTick_Int_handler(1000,ISRfun);
    
	  SysCtlSleep();
	}


  return ret;
}

Std_ReturnType MCAL_DeepSleepMode(uint32_t ui32Ms)
{
	Std_ReturnType ret = E_OK;
  
	uint32_t priod = ui32Ms /1000 ;
	
	for(uint32_t i = 0 ; i < priod ;i++)
	{
		
		MCAL_SysTick_Int_handler(1000,ISRfun);

	  SysCtlDeepSleep();
	}


  return ret;
}

/************ ISR *********************/

void ISRfun(void)
{
	
}
