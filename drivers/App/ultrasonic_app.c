
#include "ultrasonic_app.h"



Std_ReturnType App_Ultrasonic_Actions(State_t * mode , uint32_t dist )
{
	Std_ReturnType ret = E_OK;
	
	
   if(dist > 200 && NULL == mode)
   {
      ret = E_NOT_OK;
   }
   else
   {
		 //HAL_Ultra_Dist(&ultra1,dist);
		 
		 if( dist < LowDistance)
			{
				*mode = Idle_State;
			}
			else if((dist <= HighDistance) && (dist >= LowDistance))
			{
				*mode = MovingLowSpeed_State;
			}
			else
			{
        *mode = MovingHighSpeed_State;
			}

   }
   return ret;
}
