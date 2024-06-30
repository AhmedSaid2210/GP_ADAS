/*
 * Timer_Config.c
 *
 *  Created on: ???/???/????
 *      Author: Ahmed Said
 */

#include "Timer.h"

/**
 *

 *****************************************************************************
//
// Values of port
//
*****************************************************************************
 PORT_A         // GPIO Port A (high speed)
 PORT_B         // GPIO Port B (high speed)
 PORT_C         // GPIO Port C (high speed)
 PORT_D         // GPIO Port D (high speed)
 PORT_E         // GPIO Port E (high speed)
 PORT_F         // GPIO Port F (high speed)

 *****************************************************************************
//
// Values of pin
//
*****************************************************************************
 PIN_0                 // GPIO pin 0
 PIN_1                  // GPIO pin 1
 PIN_2                  // GPIO pin 2
 PIN_3                  // GPIO pin 3
 PIN_4                  // GPIO pin 4
 PIN_5                  // GPIO pin 5
 PIN_6                  // GPIO pin 6
 PIN_7                  // GPIO pin 7


*****************************************************************************
//
// Values that can be passed to SysCtlPeripheralEnable
//
*****************************************************************************
 SYSCTL_PERIPH_TIMER0      // Timer 0
 SYSCTL_PERIPH_TIMER1      // Timer 1
 SYSCTL_PERIPH_TIMER2      // Timer 2
 SYSCTL_PERIPH_TIMER3      // Timer 3


 SYSCTL_PERIPH_WTIMER2     // Wide Timer 2
 SYSCTL_PERIPH_WTIMER3     // Wide Timer 3
 SYSCTL_PERIPH_WTIMER4     // Wide Timer 4
 SYSCTL_PERIPH_WTIMER5     // Wide Timer 5


//
// The following are defines for the base address of the memories and
// peripherals.
//

   TIMER0_BASE               // Timer0
   TIMER1_BASE               // Timer1
   TIMER2_BASE               // Timer2
   TIMER3_BASE               // Timer3

 
   WTIMER2_BASE              // Wide Timer2
   WTIMER3_BASE              // Wide Timer3
   WTIMER4_BASE              // Wide Timer4
   WTIMER5_BASE              // Wide Timer5



*****************************************************************************
//
// Values that can be passed to TimerConfigure as the ui32Config parameter.
//
*****************************************************************************
 TIMER_CFG_ONE_SHOT         // Full-width one-shot timer
 TIMER_CFG_ONE_SHOT_UP      // Full-width one-shot up-count timer

 TIMER_CFG_PERIODIC         // Full-width periodic timer
 TIMER_CFG_PERIODIC_UP      // Full-width periodic up-counttimer

 TIMER_CFG_RTC              // Full-width RTC timer
 TIMER_CFG_SPLIT_PAIR       // Two half-width timers

 TIMER_CFG_A_ONE_SHOT       // Timer A one-shot timer
 TIMER_CFG_A_ONE_SHOT_UP    // Timer A one-shot up-count timer
 TIMER_CFG_A_PERIODIC       // Timer A periodic timer
 TIMER_CFG_A_PERIODIC_UP    // Timer A periodic up-count timer
 TIMER_CFG_A_CAP_COUNT      // Timer A event counter
 TIMER_CFG_A_CAP_COUNT_UP   // Timer A event up-counter
 TIMER_CFG_A_CAP_TIME       // Timer A event timer
 TIMER_CFG_A_CAP_TIME_UP    // Timer A event up-count timer
 TIMER_CFG_A_PWM            // Timer A PWM output

 TIMER_CFG_B_ONE_SHOT       // Timer B one-shot timer
 TIMER_CFG_B_ONE_SHOT_UP    // Timer B one-shot up-count timer
 TIMER_CFG_B_PERIODIC       // Timer B periodic timer
 TIMER_CFG_B_PERIODIC_UP    // Timer B periodic up-count timer
 TIMER_CFG_B_CAP_COUNT      // Timer B event counter
 TIMER_CFG_B_CAP_COUNT_UP   // Timer B event up-counter
 TIMER_CFG_B_CAP_TIME       // Timer B event timer
 TIMER_CFG_B_CAP_TIME_UP    // Timer B event up-count timer
 TIMER_CFG_B_PWM            // Timer B PWM output

*****************************************************************************
//
// Values that can be passed to TimerClockSourceSet() or returned from
// TimerClockSourceGet().
//
*****************************************************************************
 TIMER_CLOCK_SYSTEM
 TIMER_CLOCK_PIOSC

*****************************************************************************
//
// Values that can be passed to most of the timer APIs as the ui32Timer
// parameter.
*****************************************************************************

 TIMER_A                   // Timer A
 TIMER_B                   // Timer B
 TIMER_BOTH                // Timer Both

*****************************************************************************

// Values that can be passed to TimerControlEvent as the ui32Event parameter.
//
*****************************************************************************
 TIMER_EVENT_POS_EDGE      // Count positive edges
 TIMER_EVENT_NEG_EDGE      // Count negative edges
 TIMER_EVENT_BOTH_EDGES    // Count both edges

*****************************************************************************
//
// Values that can be passed to TimerIntEnable, TimerIntDisable, and
// TimerIntClear as the ui32IntFlags parameter, and returned from
// TimerIntStatus.
//
*****************************************************************************
 TIMER_TIMB_MATCH          // TimerB match interrupt
 TIMER_CAPB_EVENT          // CaptureB event interrupt
 TIMER_CAPB_MATCH          // CaptureB match interrupt
 TIMER_TIMB_TIMEOUT        // TimerB time out interrupt

 TIMER_RTC_MATCH           // RTC interrupt mask

 TIMER_TIMA_MATCH          // TimerA match interrupt
 TIMER_CAPA_EVENT          // CaptureA event interrupt
 TIMER_CAPA_MATCH          // CaptureA match interrupt
 TIMER_TIMA_TIMEOUT        // TimerA time out interrupt

*****************************************************************************

 Values that can be passed to IntRegister , IntPrioritySet , IntEnable and  IntDisable

*****************************************************************************

 INT_TIMER0A
 INT_TIMER0B
 
 INT_TIMER1A
 INT_TIMER1B
 
 INT_TIMER2A
 INT_TIMER2B
 
 INT_TIMER3A
 INT_TIMER3B



 INT_WTIMER2A
 INT_WTIMER2B
 
 INT_WTIMER3A
 INT_WTIMER3B
 
 INT_WTIMER4A
 INT_WTIMER4B
 
 INT_WTIMER5A
 INT_WTIMER5B
*****************************************************************************

 pins of timers

*****************************************************************************

************ timer0 *********
timerA     toccp0      PF0 , PB6            GPIO_PF0_T0CCP0   ,   GPIO_PB6_T0CCP0
timerB     toccp1      PF1 , PB7            GPIO_PF1_T0CCP1   ,   GPIO_PB7_T0CCP1

************ timer1 *********
timerA     t1ccp0      PF2 , PB4            GPIO_PF2_T1CCP0   ,GPIO_PB4_T1CCP0
timerB     t1ccp1      PF3 , PB5            GPIO_PF3_T1CCP1   ,GPIO_PB5_T1CCP1

************ timer2 *********
timerA     t2ccp0      PF4 , PB0            GPIO_PF4_T2CCP0   ,  GPIO_PB0_T2CCP0
timerB     t2ccp1      PB1                  GPIO_PB1_T2CCP1






************ wtimer2 *********
timerA     wt2ccp0      PD0            GPIO_PD0_WT2CCP0
timerB     wt2ccp1      PD1            GPIO_PD1_WT2CCP1

************ wtimer3 *********
timerA     wt3ccp0      PD2            GPIO_PD2_WT3CCP0
timerB     wt3ccp1      PD3            GPIO_PD3_WT3CCP1

************ wtimer4 *********
timerA     wt4ccp0      PD4            GPIO_PD4_WT4CCP0
timerB     wt4ccp1      PD5            GPIO_PD5_WT4CCP1





**********  priority  ***********

 0x00     high  priority
 0x20
 0x40
 0x60
 0x80
 0xA0
 0xC0
 0xE0     low priority



typedef struct
{
    uint32_t   PORT                  ;   // port address
    uint32_t   PIN                   ;   // port pin
    uint32_t   SYSCTL_PERIPH_TIMER   ;   // interrupt port address
    uint8_t    PRI                   ;   // priority
    uint32_t   TIMER_BASE            ;   // timer from 0 to 5
    uint32_t   TIMER_CFG             ;   // TIMER_CFG config
    uint32_t   TIMER_CLOCK           ;   // clock source
    uint32_t   TIMER_A_B_BOTH        ;   // timer A or B or BOTH
    uint32_t   TIMER_INT_STATUS      ;   // interrupt source
    uint32_t   TnCCPn                ;   // pin number
    uint32_t   INT_TIMER             ;   // interrupt timer
    uint32_t   TIMER_PRESCALLER      ;   // PRESCALLER value
    uint32_t   TIMER_LOAD            ;   // LOAD value
    uint32_t   TIMER_MATCH           ;   // MATCH value

}timer_t;

 */

timer_t timer0A = {
                  PORT_B,
                  PIN_6,
                  SYSCTL_PERIPH_TIMER0,
                  0x20,
                  TIMER0_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_A,
                  TIMER_TIMA_TIMEOUT,
                  GPIO_PB6_T0CCP0,
                  INT_TIMER0A,
                  250,
                  64000,
                  5000
};

timer_t timer0B = {
                  PORT_B,
                  PIN_7,
                  SYSCTL_PERIPH_TIMER0,
                  0x20,
                  TIMER0_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_B,
                  TIMER_TIMB_TIMEOUT,
                  GPIO_PB7_T0CCP1,
                  INT_TIMER0B,
                  250,
                  64000,
                  5000
};
timer_t timer1A = {
                  PORT_B,
                  PIN_4,
                  SYSCTL_PERIPH_TIMER1,
                  0x20,
                  TIMER1_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_A,
                  TIMER_CAPA_EVENT,
                  GPIO_PB4_T1CCP0,
                  INT_TIMER1A,
                  250,
                  0xFFFFFFFF,
                  5000
};
timer_t timer1B = {
                  PORT_B,
                  PIN_5,
                  SYSCTL_PERIPH_TIMER1,
                  0x20,
                  TIMER1_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_B,
                  TIMER_CAPB_EVENT,
                  GPIO_PB5_T1CCP1,
                  INT_TIMER1B,
                  250,
                  0xFFFFFFFF,
                  5000
};
timer_t timer2A = {
                  PORT_B,
                  PIN_0,
                  SYSCTL_PERIPH_TIMER2,
                  0x20,
                  TIMER2_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_A,
                  TIMER_TIMA_TIMEOUT,
                  GPIO_PB0_T2CCP0,
                  INT_TIMER2A,
                  250,
                  64000,
                  5000
};
timer_t timer2B = {
                  PORT_B,
                  PIN_1,
                  SYSCTL_PERIPH_TIMER2,
                  0x20,
                  TIMER2_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_B,
                  TIMER_TIMB_TIMEOUT,
                  GPIO_PB1_T2CCP1,
                  INT_TIMER2B,
                  250,
                  64000,
                  5000
};

timer_t wtimer2A = {
                  PORT_D,
                  PIN_0,
                  SYSCTL_PERIPH_WTIMER2,
                  0x20,
                  WTIMER2_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_A,
                  TIMER_TIMA_TIMEOUT,
                  GPIO_PD0_WT2CCP0,
                  INT_WTIMER2A,
                  250,
                  64000,
                  5000
};
timer_t wtimer2B  = {
                  PORT_D,
                  PIN_1,
                  SYSCTL_PERIPH_WTIMER2,
                  0x20,
                  WTIMER2_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_B,
                  TIMER_TIMB_TIMEOUT,
                  GPIO_PD1_WT2CCP1,
                  INT_WTIMER2B,
                  250,
                  64000,
                  5000
};
timer_t wtimer3A  = {
                  PORT_D,
                  PIN_2,
                  SYSCTL_PERIPH_WTIMER3,
                  0x20,
                  WTIMER3_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_A,
                  TIMER_TIMA_TIMEOUT,
                  GPIO_PD2_WT3CCP0,
                  INT_WTIMER3A,
                  250,
                  64000,
                  5000
};
timer_t wtimer3B = {
                  PORT_D,
                  PIN_3,
                  SYSCTL_PERIPH_WTIMER3,
                  0x20,
                  WTIMER3_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_B,
                  TIMER_TIMB_TIMEOUT,
                  GPIO_PD3_WT3CCP1,
                  INT_WTIMER3B,
                  250,
                  64000,
                  5000
};
timer_t wtimer4A  = {
                  PORT_D,
                  PIN_4,
                  SYSCTL_PERIPH_WTIMER4,
                  0x20,
                  WTIMER4_BASE,
                  TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC,
                  TIMER_CLOCK_SYSTEM,
                  TIMER_A,
                  TIMER_TIMA_TIMEOUT,
                  GPIO_PD4_WT4CCP0,
                  INT_WTIMER4A,
                  250,
                  64000*5,
                  5000
};

