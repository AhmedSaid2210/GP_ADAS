/*
 * Timer.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#include "motor.h"

uint32_t speed = 0;

Std_ReturnType HAL_DC_MOTOR_INIT(motor_t *motor)
{
    Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
            MCAL_GPIO_Pin_Init(motor->motor1_pin1);
					  MCAL_GPIO_Pin_Init(motor->motor1_pin2);
					  MCAL_PWM_Inti(motor->motor1_enable);
					 
					  MCAL_GPIO_Pin_Init(motor->motor2_pin1);
					  MCAL_GPIO_Pin_Init(motor->motor2_pin2);
					  MCAL_PWM_Inti(motor->motor2_enable);
					 
					  MCAL_PWM_Start(motor->motor1_enable);
					  MCAL_PWM_Start(motor->motor2_enable);
					  
         }
         return ret;
}

Std_ReturnType HAL_DC_MOTOR_ControlSpeed(motor_t *motor,uint32_t dutyCycle)
{
	  Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					
							  MCAL_PWM_PulseWidthSet(motor->motor1_enable,dutyCycle);
							
					 
								MCAL_PWM_PulseWidthSet(motor->motor2_enable,dutyCycle);
					 
							
					 	
         }
         return ret;
}
Std_ReturnType HAL_DC_MOTOR_ControlSpeedRight(motor_t *motor,uint32_t dutyCycle)
{
	  Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
		

								 MCAL_PWM_PulseWidthSet(motor->motor2_enable,dutyCycle);

					
				 }
         
         return ret;
}
Std_ReturnType HAL_DC_MOTOR_ControlSpeedLift(motor_t *motor,uint32_t dutyCycle)
{
	  Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					
							 
							   MCAL_PWM_PulseWidthSet(motor->motor1_enable,dutyCycle);

					 
						 	
         }
         return ret;
}
Std_ReturnType HAL_DC_MOTOR_MOVE_FORWARD(motor_t *motor)
{
    Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 MCAL_GPIO_Pin_Write(motor->motor1_pin1,HIGH);
					 MCAL_GPIO_Pin_Write(motor->motor1_pin2,LOW);
					
					 
					 MCAL_GPIO_Pin_Write(motor->motor2_pin1,HIGH);
					 MCAL_GPIO_Pin_Write(motor->motor2_pin2,LOW);
									
         }
         return ret;
}

Std_ReturnType HAL_DC_MOTOR_MOVE_BACKWARD(motor_t *motor)
{
    Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 MCAL_GPIO_Pin_Write(motor->motor1_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor1_pin2,HIGH);
				
					 
					 MCAL_GPIO_Pin_Write(motor->motor2_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor2_pin2,HIGH);
					
								
         }
         return ret;
}
Std_ReturnType HAL_DC_MOTOR_MOVE_FORWARD_RIGHT(motor_t *motor)
{
    Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 MCAL_GPIO_Pin_Write(motor->motor1_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor1_pin2,HIGH);
					
					 
					 MCAL_GPIO_Pin_Write(motor->motor2_pin1,HIGH);
					 MCAL_GPIO_Pin_Write(motor->motor2_pin2,LOW);
					
					 
         }
         return ret;
}
Std_ReturnType HAL_DC_MOTOR_MOVE_FORWARD_LEFT(motor_t *motor)
{
    Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 MCAL_GPIO_Pin_Write(motor->motor1_pin1,HIGH);
					 MCAL_GPIO_Pin_Write(motor->motor1_pin2,LOW);
					 
					 MCAL_GPIO_Pin_Write(motor->motor2_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor2_pin2,HIGH);
					
								
         }
         return ret;
}

Std_ReturnType HAL_DC_MOTOR_MOVE_BACKWARD_RIGHT(motor_t *motor)
{
    Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 
					 MCAL_GPIO_Pin_Write(motor->motor1_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor1_pin2,LOW);
					
					 
					 MCAL_GPIO_Pin_Write(motor->motor2_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor2_pin2,HIGH);
	
         }
         return ret;
}
Std_ReturnType HAL_DC_MOTOR_MOVE_BACKWARD_LEFT(motor_t *motor)
{
    Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 MCAL_GPIO_Pin_Write(motor->motor1_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor1_pin2,HIGH);
					 
					 
					 MCAL_GPIO_Pin_Write(motor->motor2_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor2_pin2,LOW);
					 
					 
         }
         return ret;
}

Std_ReturnType HAL_DC_MOTORS_OFF(motor_t *motor)
{
    Std_ReturnType ret = E_OK;
         if(NULL == motor)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 speed = 0;
					 MCAL_GPIO_Pin_Write(motor->motor1_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor1_pin2,LOW);
					 
					 
					 MCAL_GPIO_Pin_Write(motor->motor2_pin1,LOW);
					 MCAL_GPIO_Pin_Write(motor->motor2_pin2,LOW);
					
         }
         return ret;
}
