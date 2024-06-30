/*
 * Timer.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#include "ultrasonic.h"

Std_ReturnType HAL_Ultra_Inti(ultra_t *ultra)
{
    Std_ReturnType ret = E_OK;
         if(NULL == ultra)
         {
             ret = E_NOT_OK;
         }
         else
         {
            MCAL_GPIO_Pin_Init(ultra->trig_pin);
					 
					  MCAL_Timer_Inti_CAP(ultra->timer);
					 	MCAL_Timer_SET_PRESCALLER(ultra->timer);
						//MCAL_Timer_Int_handler(&ultra->timer,fun);
						MCAL_Timer_SET_EVENT(ultra->timer,TIMER_EVENT_BOTH_EDGES);

         }
         return ret;
}
Std_ReturnType HAL_Ultra_Dist(ultra_t *ultra ,uint32_t *dist )
{
    Std_ReturnType ret = E_OK;
         if(NULL == ultra)
         {
             ret = E_NOT_OK;
         }
         else
         {
					  uint32_t a,b;
            MCAL_Timer_SET_LOAD(ultra->timer); // 0xFFFFFFFF
						//trig pin
						MCAL_GPIO_Pin_Write(ultra->trig_pin,HIGH);
						MCAL_DelayUs(10);
						MCAL_GPIO_Pin_Write(ultra->trig_pin,LOW);
		
						MCAL_Timer_Start(ultra->timer);
			
						//echo pin
						while(!(MCAL_GPIO_Pin_Read(ultra->echo_pin)));
					  MCAL_Timer_IntClear(ultra->timer);
						a = MCAL_Timer_GET_VALUE(ultra->timer);

						while((MCAL_GPIO_Pin_Read(ultra->echo_pin)));
					  MCAL_Timer_IntClear(ultra->timer);
						b = MCAL_Timer_GET_VALUE(ultra->timer);
		
						MCAL_Timer_Stop(ultra->timer);
			
						*dist = a - b;
				
						*dist = (((*dist) * 34600) / (2 * (SysCtlClockGet()/ultra->timer->TIMER_PRESCALLER)));
								
         }
         return ret;
}

