/*********************************************************************************************************
 * ********************************************************************************************************
AUTHOR  : AHMED KHALED ANWAR
MICRO   : STM32F401CCU6
LAYER   : MCAL
DRIVER  : SYSTICK DRIVER
File    : PRIVATE FILE
Version :1.0
********************************************************************************************************
*********************************************************/

#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

typedef struct
{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;
}STK_t;

#define STK_BASE_ADDRESS      (0xE000E010)
#define STK        ((volatile STK_t*)STK_BASE_ADDRESS)



#define AHB_DIV_8     0
#define AHB           1

#define TICKINT_DISABLED     0
#define TICKINT_ENABLED      1

#define COUNTER_DISABLED     0
#define COUNTER_ENABLED      1


/*STK_CTRL bits*/
#define ENABLE      0
#define TICKINT     1
#define CLKSOURCE   2
#define COUNTFLAG   16


#define MICRO_SCALE   16
#define MILLI_SCALE   16000
#define SECONDS_SCALE 16000000

#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
