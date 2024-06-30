
#include "TM4C123GH6PM.h"
#include <stdio.h>
#include "GPIO_Config.h"
#include "RCC_Config.h"
#include "RCC_test.h"

/*16MHZ, first case when clk value = 16MHZ, led red will turn on*/
void RCC_testcase1(void)
{
	MCAL_RCC_SysCtlClockExternal(&RCC_config16);
	
		MCAL_GPIO_Pin_Init(&PF1);
    MCAL_GPIO_Pin_Init(&PF3);
		uint32_t clock;
	clock =SysCtlClockGet();
	
	while(1)
	{
		
			if(SysCtlClockGet()==16000000)
		    MCAL_GPIO_Pin_Write(&PF1,HIGH);
			else 		    MCAL_GPIO_Pin_Write(&PF3,HIGH);

				
	
}
	

}
/*66MHZ, first case when clk value = 66MHZ, led green will turn on*/

void RCC_testcase2(void)
{
	MCAL_RCC_SysCtlClockExternal(&RCC_config66);
	
		MCAL_GPIO_Pin_Init(&PF1);
    MCAL_GPIO_Pin_Init(&PF3);
		uint32_t clock;
	clock =SysCtlClockGet();
	
	while(1)
	{
		
			if(SysCtlClockGet()>=66000000)
		    MCAL_GPIO_Pin_Write(&PF3,HIGH);
			else 		    MCAL_GPIO_Pin_Write(&PF1,HIGH);

				
	
}
}
void RCC_testcase3(void)
{
	MCAL_RCC_SysCtlClockExternal(&RCC_config50);
	
		MCAL_GPIO_Pin_Init(&PF1);
	  MCAL_GPIO_Pin_Init(&PF2);
    MCAL_GPIO_Pin_Init(&PF3);
		uint32_t clock;
	clock =SysCtlClockGet();
	
	while(1)
	{
		
			if(SysCtlClockGet()==50000000)
		    MCAL_GPIO_Pin_Write(&PF2,HIGH);
			else 		    MCAL_GPIO_Pin_Write(&PF1,HIGH);	
	
}
}
void RCC_testcase4(void)
{
	MCAL_RCC_SysCtlClockInternal(&RCC_configInt16);
	
		MCAL_GPIO_Pin_Init(&PF1);
	  MCAL_GPIO_Pin_Init(&PE1);
    MCAL_GPIO_Pin_Init(&PF3);
		uint32_t clock;
	clock =SysCtlClockGet();
	
	while(1)
	{
		
			if(SysCtlClockGet()==16000000)
		    MCAL_GPIO_Pin_Write(&PE1,HIGH);
			else 		      MCAL_GPIO_Pin_Write(&PE0,LOW);

				
	
}
}
