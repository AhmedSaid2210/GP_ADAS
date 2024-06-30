
#include "TM4C123GH6PM.h"
#include <stdio.h>
#include <stdint.h>
#include "GPIO_Config.h"
#include "RCC_Config.h"
#include "Timer_Config.h"
#include "delay.h"
#include "motor_Config.h"
#include "ultrasonic_Config.h"
#include "driverlib/emac.h"

#define STOP 0
#define SPEED_25  400
#define SPEED_50  800
#define SPEED_65  1040
#define SPEED_75  1200
#define SPEED_85  1360
#define SPEED_100 1600

int main(void)
{

	uint8_t key1 = 0;
	uint8_t key2 = 0;
	MCAL_RCC_SysCtlClockExternal(&RCC_config16);
	
	HAL_DC_MOTOR_INIT(&motor_config);
	HAL_Ultra_Inti(&ultra1);
	int distance = 0;
	
  while (1)
	{
		HAL_Ultra_Dist(&ultra1,&distance);
		MCAL_DelayMs(100);
		
		HAL_DC_MOTOR_MOVE_FORWARD(&motor_config);
		
		if(distance >= 80)
		{
			if(key1 ==0){
			HAL_DC_MOTOR_ControlSpeed(&motor_config,SPEED_75);
			key1 = 1 ; key2 = 0 ;
			}
		}
		else if(distance < 80 && distance >=45)
		{
			if(key2 ==0){
				
			 HAL_DC_MOTOR_ControlSpeed(&motor_config,SPEED_75);
				
			 HAL_DC_MOTOR_ControlSpeed(&motor_config,SPEED_50);
				
			 key2 = 1 ; key1 = 0 ;
			}
			
			
		}
		else if(distance < 45) 
		{
			key1 = 0 ; key2 = 0 ;
			//HAL_DC_MOTOR_ControlSpeed(&motor_config,STOP);
			HAL_DC_MOTORS_OFF(&motor_config);
			MCAL_DelayMs(500);
			HAL_DC_MOTOR_ControlSpeedLift(&motor_config,SPEED_75);
			HAL_DC_MOTOR_MOVE_BACKWARD(&motor_config);
			MCAL_DelayMs(500);
			HAL_DC_MOTORS_OFF(&motor_config);
			MCAL_DelayMs(500);
			HAL_DC_MOTOR_MOVE_BACKWARD_LEFT(&motor_config);
			MCAL_DelayMs(500);
			HAL_DC_MOTORS_OFF(&motor_config);
			MCAL_DelayMs(500);
			HAL_DC_MOTOE_MOVE_FORWARD_RIGHT(&motor_config);
			MCAL_DelayMs(500);
			HAL_DC_MOTORS_OFF(&motor_config);
			MCAL_DelayMs(500);
		}
		
	}
	
}
