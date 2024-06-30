#include "motor_app.h"



Std_ReturnType APP_DC_MOTOR_INIT(void)
{
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOR_INIT(&motor_config);
  return ret;
}


Std_ReturnType APP_DC_MOTOR_ControlSpeed(uint32_t dutyCycle)
{
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOR_ControlSpeed(&motor_config,dutyCycle);
  return ret;
}

Std_ReturnType APP_DC_MOTOR_ControlSpeedRight(uint32_t dutyCycle)
{
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOR_ControlSpeedRight(&motor_config,dutyCycle);
  return ret;
}

Std_ReturnType APP_DC_MOTOR_ControlSpeedLift(uint32_t dutyCycle)
{
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOR_ControlSpeedLift(&motor_config,dutyCycle);
  return ret;
}

Std_ReturnType APP_DC_MOTOR_MOVE_FORWARD(void)
{
	
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOR_MOVE_FORWARD(&motor_config);
  return ret;

}

Std_ReturnType APP_DC_MOTOR_MOVE_BACKWARD(void)
{
	
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOR_MOVE_BACKWARD(&motor_config);
  return ret;

}	

Std_ReturnType APP_DC_MOTOE_MOVE_FORWARD_RIGHT(void)
{
	
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOE_MOVE_FORWARD_RIGHT(&motor_config);
  return ret;

}	
Std_ReturnType APP_DC_MOTOE_MOVE_FORWARD_LEFT(void)
{
	
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOE_MOVE_FORWARD_LEFT(&motor_config);
  return ret;

}	

Std_ReturnType APP_DC_MOTOR_MOVE_BACKWARD_RIGHT(void)
{
	
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOR_MOVE_BACKWARD_RIGHT(&motor_config);
  return ret;

}

Std_ReturnType APP_DC_MOTOR_MOVE_BACKWARD_LEFT(void)
{
	
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTOR_MOVE_BACKWARD_LEFT(&motor_config);
  return ret;

}

Std_ReturnType APP_DC_MOTORS_OFF(void)
{
	
	Std_ReturnType ret = E_OK;
	HAL_DC_MOTORS_OFF(&motor_config);
  return ret;

}
