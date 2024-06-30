
#include "apps_interface.h"

void MainTask(void *pvParameters);
void UltraTask(void *pvParameters);
void IRTask(void *pvParameters);
void CommunicationTask(void *pvParameters);



uint32_t  Global_RightValue     ;

uint32_t  Global_LeftValue      ;

uint32_t  Global_Distance        ;

State_t Current_State  = Idle_State;



void App_Init(void)
{
	MCAL_RCC_SysCtlClockExternal(&RCC_config16);
	
	HAL_DC_MOTOR_INIT(&motor_config);
	HAL_Ultra_Inti(&ultra1);
	HAL_IR_Inti(&IR_config);
	
	xTaskCreate(MainTask,(const portCHAR *)"MainTask",  configMINIMAL_STACK_SIZE,NULL,1,NULL);
	
	xTaskCreate(UltraTask,(const portCHAR *)"UltrasonicTask",  configMINIMAL_STACK_SIZE,NULL,1,NULL);
	
	xTaskCreate(IRTask,(const portCHAR *)"IRTask",  configMINIMAL_STACK_SIZE,NULL,1,NULL);
	
	xTaskCreate(CommunicationTask,(const portCHAR *)"CommunicationTask",  configMINIMAL_STACK_SIZE,NULL,1,NULL);
}



void App_Start(void)
{
	vTaskStartScheduler();
}



void MainTask(void *pvParameters)
{
	(void)pvParameters;
	for(;;)
	{
		
	 switch(Current_State)
   {
       case Idle_State           : Current_State = IdleMode();              break;

       case MovingHighSpeed_State: Current_State = MovingHighSpeed_Mode();  break;

       case MovingLowSpeed_State : Current_State = MovingLowSpeed_Mode();   break;
		 
   }
	 vTaskDelay(100 / portTICK_PERIOD_MS);
	 
	}
}


void UltraTask(void *pvParameters)
{
  (void)pvParameters;
	for(;;)
	{
		/**  Check Ultrasoinc Sensors **/
	 HAL_Ultra_Dist(&ultra1,&Global_Distance);
		
	 vTaskDelay(20 / portTICK_PERIOD_MS);
	 
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
	 vTaskDelay(20 / portTICK_PERIOD_MS);
	 
	}
}
void CommunicationTask(void *pvParameters)
{
	(void)pvParameters;
	for(;;)
	{

		
	 vTaskDelay(100 / portTICK_PERIOD_MS);
	 
	}
}



/** Idle Speed Mode **/
State_t IdleMode(void)
{

	HAL_DC_MOTOR_ControlSpeed(&motor_config , STOP);
	
	App_Ultrasonic_Actions(&Current_State,Global_Distance);

	APP_IR_Read_RightIR(Global_RightValue,Global_LeftValue);

	return Current_State;
}




/** High Speed Mode **/
State_t MovingHighSpeed_Mode(void)
{

	/* Control on the speed (Current Speed)*/
	HAL_DC_MOTOR_ControlSpeed(&motor_config , HIGHSPEED);

	App_Ultrasonic_Actions(&Current_State,Global_Distance);

	APP_IR_Read_RightIR(Global_RightValue,Global_LeftValue);

	return Current_State;
}



/** Low Speed Mode **/
State_t MovingLowSpeed_Mode(void)
{

	
	/* Control on the speed (Current Speed)*/
	HAL_DC_MOTOR_ControlSpeed(&motor_config,HIGHSPEED);

	
	/* Control on the speed (Current Speed)*/
	HAL_DC_MOTOR_ControlSpeed(&motor_config,LOWSPEED);
	

	App_Ultrasonic_Actions(&Current_State,Global_Distance);

	APP_IR_Read_RightIR(Global_RightValue,Global_LeftValue);


	return Current_State;
}







