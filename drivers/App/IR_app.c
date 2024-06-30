
#include "IR_app.h"



Std_ReturnType APP_IR_Actions(uint32_t RightValue, uint32_t LeftValue)
{
 Std_ReturnType ret = E_OK;
	
         if( RightValue > 1 &&LeftValue > 1)
         {
             ret = E_NOT_OK;
         }
         else
         {
            if((RightValue == WHITE) && (LeftValue == WHITE))
						{
							/* Move Forward */
							HAL_DC_MOTOR_MOVE_FORWARD(&motor_config);

						}
						else if((LeftValue == BLACK) && (RightValue == WHITE))
						{

						/* Turn Right */
						HAL_DC_MOTOE_MOVE_FORWARD_RIGHT(&motor_config);

						}
						else if((RightValue == BLACK) && (LeftValue == WHITE))
						{

							/* Turn Left */
							HAL_DC_MOTOE_MOVE_FORWARD_LEFT(&motor_config);

						}
						else if((RightValue == BLACK) && (LeftValue == BLACK))
						{
							HAL_DC_MOTORS_OFF(&motor_config);
						}
         }
				 
				 
         return ret;
	

}


