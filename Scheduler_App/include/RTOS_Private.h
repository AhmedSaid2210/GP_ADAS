/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : AHMED KHLAED ANWAR
MICRO  : STM32F401CCU6
DRIVER : RTOS MODULE
FILE   : PRIVATE FILE
Version: 1.0
********************************************************************************************************
********************************************************************************************************
 */

#ifndef RTOS_RTOS_PRIVATE_H_
#define RTOS_RTOS_PRIVATE_H_

typedef enum
{
	Task_Suspended=0,
	Task_Running
}Task_State;


typedef struct
{
	void(*TaskHandler)(void);
	u8 Periodicity;                         /*Express how often a task is run by the scheduler*/
	u8 First_delay;                         /*Express the first time to execute a certain task*/
	Task_State Tstate;                      /*Whether the task is suspended or running*/
}Task;


typedef enum
{
	Task_Not_Created=0,
	Task_Created,
	Reserved_Address
};

typedef enum
{
	On_Schedule=0,
	Off_Schedule
};

typedef enum
{
	Task_Not_Deleted=0,
	Task_Deleted
};


#endif /* RTOS_RTOS_PRIVATE_H_ */
