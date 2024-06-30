/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : AHMED KHLAED ANWAR
MICRO  : STM32F401CCU6
DRIVER : RTOS MODULE
FILE   : PROGRAM FILE
Version: 1.0
********************************************************************************************************
********************************************************************************************************
 */

/**********************************           Includes               *********************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "RTOS_Config.h"
#include "RTOS_Interface.h"
#include "RTOS_Private.h"
#include "SYSTICK_Interface.h"

/**********************************       Global Declarations        *********************************/

Task SystemTasks[MAX_NUMBER_TASKS]={0};                      /*20 Tasks container*/
u8 Timing[MAX_NUMBER_TASKS];
Task Empty ={0};                                             /*Every member in the structure equals to zero*/


/**********************************     Functions Implementation     *********************************/

/*Function name:RTOS_u8CreateTask
 * Description: Creates task with a certain periodicity and priority
 * I/P arguments:
 * 				handler: pointer to the task handler ,
 * 				periodicity: express the periodic time of the task in ticks
 * 				priority: express the priority of the task
 *				return: Local_Error_State
 */
u8 RTOS_u8CreateTask(void(*handler)(void),u32 Copy_u8Periodicity,u8 Copy_u8Priority ,u8 Copy_u8Fdelay)
{
	u8 Local_Error_State=Task_Not_Created;
	if(Copy_u8Priority<MAX_NUMBER_TASKS)                                 /*verify priority within limit*/
	{
		if(SystemTasks[Copy_u8Priority].TaskHandler==NULL)               /*verify the address is not reserved for another task*/
		{
			SystemTasks[Copy_u8Priority].TaskHandler=handler           ;
			SystemTasks[Copy_u8Priority].Periodicity=Copy_u8Periodicity;
			Timing     [Copy_u8Priority]            =Copy_u8Fdelay     ;
			SystemTasks[Copy_u8Priority].Tstate     =Task_Running      ;
		}
		else
		{
			Local_Error_State=Reserved_Address;
		}
	}
	else
	{
		Local_Error_State=Task_Created;
	}
	return Local_Error_State;
}

/*Function name:Scheduler
 * Description: Called in order to handle the tasks if they met their timings
 * I/P arguments:
 * 				void
 *				return:void
 */
void Scheduler(void)                                   /*CallBack function of systick*/
{
	u8 Local_Counter=0;
	for(Local_Counter=0;Local_Counter<MAX_NUMBER_TASKS;Local_Counter++)
	{
		if(SystemTasks[Local_Counter].TaskHandler!=NULL)
		{
			if(SystemTasks[Local_Counter].Tstate==Task_Running)
			{
			 if(Timing[Local_Counter]==On_Schedule)
			 {
				SystemTasks[Local_Counter].TaskHandler();
				Timing[Local_Counter]=SystemTasks[Local_Counter].Periodicity;
			 }
			else
				{
					Timing[Local_Counter]--;
				}
		    }

	    }

    }
}


/*Function name:RTOS_u8DeleteTask
 * Description: Delete the task from the array of tasks(structures) so they turn from ready to dormant
 * I/P arguments:
 * 				Copy_u8Priority: Expresses the task index in the array of structures.
 *				return:Local_Delete_State
 */
u8 RTOS_u8DeleteTask(u8 Copy_u8Priority)
{
	u8 Local_Delete_State=Task_Not_Deleted;
	if(SystemTasks[Copy_u8Priority].TaskHandler!=NULL)
	{
		SystemTasks[Copy_u8Priority]=Empty;
		Local_Delete_State=Task_Deleted;
	}
	return Local_Delete_State;
}

/*Function name:RTOS_u8SuspendTask
 * Description: Converts the state of a task from running to suspended
 * I/P arguments:
 * 				Copy_u8Priority: Expresses the task index in the array of structures.
 *				return:Local_Error_State
 */
u8 RTOS_u8SuspendTask(u8 Copy_u8Priority)
{
	u8 Local_Error_State=STD_TYPES_OK;
	if(SystemTasks[Copy_u8Priority].TaskHandler!=NULL)
	{
		SystemTasks[Copy_u8Priority].Tstate=Task_Suspended;
	}
	else
	{
		Local_Error_State=STD_TYPES_NOK;
	}
return Local_Error_State;
}

/*Function name:RTOS_u8ResumeTask
 * Description: Converts the state of a task from suspended to running
 * I/P arguments:
 * 				Copy_u8Priority: Expresses the task index in the array of structures.
 *				return:Local_Error_State
 */
u8 RTOS_u8ResumeTask(u8 Copy_u8Priority)
{
	u8 Local_Error_State=STD_TYPES_OK;
	if(SystemTasks[Copy_u8Priority].TaskHandler!=NULL)
	{
		SystemTasks[Copy_u8Priority].Tstate=Task_Running;
	}
	else
	{
		Local_Error_State=STD_TYPES_NOK;
	}
	return Local_Error_State;
}

/*Function name:Start_OS
 * Description: Initialise operating system
 * I/P arguments:
 * 				void
 *				return:void
 */
void Start_OS(void)
{
	SYSTICK_voidSetIntervalPeriodic(TICKTIME,Scheduler);
}
