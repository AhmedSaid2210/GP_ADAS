#include "TM4C123GH6PM.h"
#include <stdio.h>
#include "GPIO_Config.h"
#include "RCC_Config.h"
#include "delay.h"
#include "SysTick.h"
#include "string.h"
#include "Watchdog.h"
#include "sleep.h"

#include "IR_Config.h"
#include "motor_Config.h"
#include "ultrasonic_Config.h"
#include "communication.h"

#include <FreeRTOS.h>
#include <task.h>
void fun();

#define WHITE 1
#define BLACK 0


#define STOP 0
#define SPEED_25  400
#define SPEED_30  480
#define SPEED_35  560
#define SPEED_40  640
#define SPEED_45  720
#define SPEED_50  800
#define SPEED_55  880
#define SPEED_60  960
#define SPEED_65  1040
#define SPEED_70  1120
#define SPEED_75  1200
#define SPEED_80  1280
#define SPEED_85  1360
#define SPEED_100 1600
void vApplicationSleep(TickType_t xExpectedIdleTime)
{
    // Ensure the SysTick reload value does not underflow the counter
    if (xExpectedIdleTime > 0)
    {
        // Stop the SysTick momentarily
        SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

        // Configure SysTick to generate an interrupt after xExpectedIdleTime ticks
        SysTick->LOAD = (xExpectedIdleTime * (configCPU_CLOCK_HZ / configTICK_RATE_HZ)) - 1;
        SysTick->VAL = 0;
        SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;

        // Enter low power mode
        SysCtlSleep();

        // Restart the SysTick
        SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
        SysTick->LOAD = (configCPU_CLOCK_HZ / configTICK_RATE_HZ) - 1;
        SysTick->VAL = 0;
        SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
    }
}

void vApplicationIdleHook(void)
{
    // Call the sleep function when the system is idle
    vApplicationSleep(1000);  // Use an appropriate expected idle time
}

void MainTask(void *pvParameters);

void UltraTask(void *pvParameters);

void IRTask(void *pvParameters);

void sendTask(void *pvParameters);

uint32_t Global_Distance = 0;
uint32_t Global_RightValue = 0;
uint32_t Global_LeftValue = 0 ;

uint8_t  key = 0;

message_t rr ;
message_t d  ;

int main(void)
{
	
	MCAL_RCC_SysCtlClockExternal(&RCC_config16);
	//MCAL_GPIO_Pin_Init(&PF1);
	
	HAL_IR_Inti(&IR_config);
	HAL_DC_MOTOR_INIT(&motor_config);
	HAL_Ultra_Inti(&ultra1);
	HAL_Comm_Inti();
	MCAL_Watchdog_Inti();
	uint8_t key1 = 0;
	uint8_t key2 = 0;
	uint8_t key3 = 0;
	
	uint32_t distance = 0;
	
	uint8_t right = 0  , left = 0;
	
	xTaskCreate(sendTask,(const portCHAR *)"sendTask",  configMINIMAL_STACK_SIZE,NULL,1,NULL);
	
	xTaskCreate(UltraTask,(const portCHAR *)"UltrasonicTask",  configMINIMAL_STACK_SIZE,NULL,1,NULL);
	
	xTaskCreate(IRTask,(const portCHAR *)"IRTask",  configMINIMAL_STACK_SIZE,NULL,1,NULL);
	
	xTaskCreate(MainTask,(const portCHAR *)"MainTask",  configMINIMAL_STACK_SIZE,NULL,1,NULL);	
	
	
	
	vTaskStartScheduler();

}
void fun()
{
	
}
void UltraTask(void *pvParameters)
{
  (void)pvParameters;
	for(;;)
	{
		/**  Check Ultrasoinc Sensors **/
	 HAL_Ultra_Dist(&ultra1,&Global_Distance);
		
	 vTaskDelay(10 / portTICK_PERIOD_MS);
	 
	}
}
void IRTask(void *pvParameters)
{
  (void)pvParameters;
	for(;;)
	{
		
		/**  Check IR Sensors **/
	 HAL_IR_Read_RightIR(&IR_config,&Global_RightValue);
	 HAL_IR_Read_LeftIR(&IR_config,&Global_LeftValue);
	 vTaskDelay(6 / portTICK_PERIOD_MS);
	 
	}
}

void sendTask(void *pvParameters)
{
	(void)pvParameters;
	for(;;)
	{
	    HAL_Comm_SendFrame(&d);
		
	  	HAL_Comm_ReceiveFrame(&rr);
	
	    vTaskDelay(5 / portTICK_PERIOD_MS);
	
	}
}

void MainTask(void *pvParameters)
{
	(void)pvParameters;
	for(;;)
	{
if(rr.Data == 1){
			MCAL_GPIO_Pin_Write(&PF1, HIGH);
		
		if(Global_Distance  <=  30 )
		{
		 HAL_DC_MOTORS_OFF(&motor_config);
		}	
		else if(Global_LeftValue == WHITE && Global_RightValue == WHITE)
		{
			HAL_DC_MOTOR_MOVE_FORWARD(&motor_config);
		 if(key == 0){
			 key = 1;
			 HAL_DC_MOTOR_ControlSpeed(&motor_config,SPEED_80);
			 MCAL_DelayMs(50);
		 }
			 
				
			
			  HAL_DC_MOTOR_ControlSpeed(&motor_config,SPEED_60);
			//	MCAL_DelayMs(100);
			//	HAL_DC_MOTOR_ControlSpeed(&motor_config,SPEED_50);
			//  MCAL_DelayMs(100);
			
		}	
		else if (Global_LeftValue == BLACK && Global_RightValue == WHITE)
		{
		    
			while(Global_LeftValue == BLACK){
					//HAL_DC_MOTOR_MOVE_FORWARD_LEFT(&motor_config);
				HAL_DC_MOTOR_ControlSpeed(&motor_config,SPEED_85);
				HAL_DC_MOTORS_OFF(&motor_config);
				MCAL_DelayMs(100);
				HAL_DC_MOTOR_MOVE_FORWARD_RIGHT(&motor_config);
				MCAL_DelayMs(70);
			
				HAL_IR_Read_LeftIR(&IR_config,&Global_LeftValue);
			}
		}
		else if (Global_LeftValue == WHITE && Global_RightValue == BLACK)
		{
		
		 while(Global_RightValue == BLACK){
					//HAL_DC_MOTOR_MOVE_FORWARD_RIGHT(&motor_config);
			  HAL_DC_MOTOR_ControlSpeed(&motor_config,SPEED_85);
			 	HAL_DC_MOTORS_OFF(&motor_config);
				MCAL_DelayMs(100);
				HAL_DC_MOTOR_MOVE_FORWARD_LEFT(&motor_config);
		   	MCAL_DelayMs(70);
			
				HAL_IR_Read_RightIR(&IR_config,&Global_RightValue);
		 }
		}
		
	
}else {HAL_DC_MOTORS_OFF(&motor_config); MCAL_GPIO_Pin_Write(&PF1, LOW);}

	 vTaskDelay(7 / portTICK_PERIOD_MS);
	 
		
	}
}