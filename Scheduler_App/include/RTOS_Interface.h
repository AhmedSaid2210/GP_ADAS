/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR : AHMED KHLAED ANWAR
MICRO  : STM32F401CCU6
DRIVER : RTOS MODULE
FILE   : INTERFACE FILE
Version: 1.0
********************************************************************************************************
********************************************************************************************************
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_



/*Function name:RTOS_u8CreateTask
 * Description: Creates task with a certain periodicity and priority
 * I/P arguments:
 * 				handler: pointer to the task handler ,
 * 				periodicity: express the periodic time of the task in ticks
 * 				priority: express the priority of the task
 * 				Copy_u8Fdelay:Express the first time a task is executed
 *				return: Local_Error_State
 */
u8 RTOS_u8CreateTask(void(*handler)(void),u32 Copy_u8Periodicity ,u8 Copy_u8Priority,u8 Copy_u8Fdelay);

/*Function name:Scheduler
 * Description: Called in order to handle the tasks if they met their timings
 * I/P arguments:
 * 				void
 *				return:void
 */
void Scheduler(void);

/*Function name:RTOS_u8DeleteTask
 * Description: Delete the task from the array of tasks(structures) so they turn from ready to dormant
 * I/P arguments:
 * 				Copy_u8Priority: Expresses the task index in the array of structures.
 *				return:Local_Delete_State
 */
u8 RTOS_u8DeleteTask(u8 Copy_u8Priority);

/*Function name:RTOS_u8SuspendTask
 * Description: Converts the state of a task from running to suspended
 * I/P arguments:
 * 				Copy_u8Priority: Expresses the task index in the array of structures.
 *				return:Local_Error_State
 */
u8 RTOS_u8SuspendTask(u8 Copy_u8Priority);

/*Function name:RTOS_u8ResumeTask
 * Description: Converts the state of a task from suspended to running
 * I/P arguments:
 * 				Copy_u8Priority: Expresses the task index in the array of structures.
 *				return:Local_Error_State
 */
u8 RTOS_u8ResumeTask(u8 Copy_u8Priority);

/*Function name:Start_OS
 * Description: Initialise operating system
 * I/P arguments:
 * 				void
 *				return:void
 */
void Start_OS(void);
#endif /* RTOS_RTOS_INTERFACE_H_ */
