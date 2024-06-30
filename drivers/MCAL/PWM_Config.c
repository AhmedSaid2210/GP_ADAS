/*
 * PWM_Config.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#include "PWM.h"
/**
 *
 *
 *
*****************************************************************************
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
 *
*****************************************************************************
//
// Values of SYSCTL_PERIPH_PWM
//
*****************************************************************************
 *   SYSCTL_PERIPH_PWM0      0xf0004000  // PWM 0
     SYSCTL_PERIPH_PWM1      0xf0004001  // PWM 1
 *
  *****************************************************************************
//
// Values of PWM_SYSCLK_DIV
//
*****************************************************************************
      PWM_SYSCLK_DIV_1          // PWM clock is system clock
      PWM_SYSCLK_DIV_2          // PWM clock is system clock /2
      PWM_SYSCLK_DIV_4          // PWM clock is system clock /4
      PWM_SYSCLK_DIV_8          // PWM clock is system clock /8
      PWM_SYSCLK_DIV_16         // PWM clock is system clock /16
      PWM_SYSCLK_DIV_32         // PWM clock is system clock /32
      PWM_SYSCLK_DIV_64         // PWM clock is system clock /64
 *
  *****************************************************************************
//
// Values of PWM_BASE
//
*****************************************************************************
     PWM0_BASE                 // Pulse Width Modulator (PWM)
     PWM1_BASE                 // Pulse Width Modulator (PWM)
 *
 *
*****************************************************************************
//
// Values of PWM_GEN
//
*****************************************************************************
     PWM_GEN_0                 // Offset address of Gen0  for pwm0 and pwm1
     PWM_GEN_1                 // Offset address of Gen1  for pwm2 and pwm3
     PWM_GEN_2                 // Offset address of Gen2  for pwm4 and pwm5
     PWM_GEN_3                 // Offset address of Gen3  for pwm6 and pwm7
*****************************************************************************
//
// Values of PWM_GEN_MODE
//
*****************************************************************************
     PWM_GEN_MODE_DOWN         // Down count mode
     PWM_GEN_MODE_UP_DOWN      // Up/Down count mode
     PWM_GEN_MODE_SYNC         // Synchronous updates
     PWM_GEN_MODE_NO_SYNC      // Immediate updates
     PWM_GEN_MODE_DBG_RUN      // Continue running in debug mode
     PWM_GEN_MODE_DBG_STOP     // Stop running in debug mode

*****************************************************************************
//
// Values of MnPWMn
//
*****************************************************************************
     GPIO_PA6_M1PWM2
     GPIO_PA7_M1PWM3


     GPIO_PB4_M0PWM2
     GPIO_PB5_M0PWM3
     GPIO_PB6_M0PWM0
     GPIO_PB7_M0PWM1


     GPIO_PD0_M0PWM6
     GPIO_PD0_M1PWM0
     GPIO_PD1_M0PWM7
     GPIO_PD1_M1PWM1

     GPIO_PE4_M0PWM4
     GPIO_PE4_M1PWM2
     GPIO_PE5_M0PWM5
     GPIO_PE5_M1PWM3

     GPIO_PF0_M1PWM4
     GPIO_PF1_M1PWM5
     GPIO_PF2_M1PWM6
     GPIO_PF3_M1PWM7
*****************************************************************************
//
// Values of PWM_OUT_n
//
*****************************************************************************
     PWM_OUT_0                 // Encoded offset address of PWM0
     PWM_OUT_1                 // Encoded offset address of PWM1
     PWM_OUT_2                 // Encoded offset address of PWM2
     PWM_OUT_3                 // Encoded offset address of PWM3
     PWM_OUT_4                 // Encoded offset address of PWM4
     PWM_OUT_5                 // Encoded offset address of PWM5
     PWM_OUT_6                 // Encoded offset address of PWM6
     PWM_OUT_7                 // Encoded offset address of PWM7

*****************************************************************************
//
// Values of PWM_OUT_n_BIT
//
*****************************************************************************
     PWM_OUT_0_BIT             // Bit-wise ID for PWM0
     PWM_OUT_1_BIT             // Bit-wise ID for PWM1
     PWM_OUT_2_BIT             // Bit-wise ID for PWM2
     PWM_OUT_3_BIT             // Bit-wise ID for PWM3
     PWM_OUT_4_BIT             // Bit-wise ID for PWM4
     PWM_OUT_5_BIT             // Bit-wise ID for PWM5
     PWM_OUT_6_BIT             // Bit-wise ID for PWM6
     PWM_OUT_7_BIT             // Bit-wise ID for PWM7
 *
typedef struct
{
    uint32_t   PORT                 ;   // port address

    uint32_t   PIN                  ;   // port pin

    uint32_t   SYSCTL_PERIPH_PWM    ;   // SYSCTL_PERIPH_PWM

    uint32_t   PWM_SYSCLK_DIV       ;   // PWM_SYSCLK_DIV

    uint32_t   PWM_BASE             ;   // PWM_BASE

    uint32_t   PWM_GEN              ;   // PWM_GEN

    uint32_t   PWM_GEN_MODE         ;   // PWM_GEN_MODE

    uint32_t   MnPWMn               ;   // MnPWMn

    uint32_t   PWM_OUT_n            ;   // PWM_OUT_n

    uint32_t   PWM_OUT_n_BIT        ;   // PWM_OUT_n_BIT

    uint32_t   period               ;   //number of ticks =  pwm system clock HZ/ required clock HZ


}PWM_t;

*/

PWM_t pwm_out = {
                 PORT_F,
                 PIN_1,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_2,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PF1_M1PWM5,
                 PWM_OUT_5,
                 PWM_OUT_5_BIT,
                 4000            //16MHZ / 10KHZ = 1600
};

PWM_t PA6_M1PWM2 = {
                 PORT_A,
                 PIN_6,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_1,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PA6_M1PWM2,
                 PWM_OUT_2,
                 PWM_OUT_2_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PA7_M1PWM3 = {
                 PORT_A,
                 PIN_7,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_1,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PA7_M1PWM3,
                 PWM_OUT_3,
                 PWM_OUT_3_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};

PWM_t PB4_M0PWM2 = {
                 PORT_B,
                 PIN_4,
                 SYSCTL_PERIPH_PWM0,
                 PWM_SYSCLK_DIV_1,
                 PWM0_BASE,
                 PWM_GEN_1,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PB4_M0PWM2,
                 PWM_OUT_2,
                 PWM_OUT_2_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};

PWM_t PB5_M0PWM3 = {
                 PORT_B,
                 PIN_5,
                 SYSCTL_PERIPH_PWM0,
                 PWM_SYSCLK_DIV_1,
                 PWM0_BASE,
                 PWM_GEN_1,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PB5_M0PWM3,
                 PWM_OUT_3,
                 PWM_OUT_3_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PB6_M0PWM0 = {
                 PORT_B,
                 PIN_6,
                 SYSCTL_PERIPH_PWM0,
                 PWM_SYSCLK_DIV_1,
                 PWM0_BASE,
                 PWM_GEN_0,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PB6_M0PWM0,
                 PWM_OUT_0,
                 PWM_OUT_0_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PB7_M0PWM1 = {
                 PORT_B,
                 PIN_7,
                 SYSCTL_PERIPH_PWM0,
                 PWM_SYSCLK_DIV_1,
                 PWM0_BASE,
                 PWM_GEN_0,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PB7_M0PWM1,
                 PWM_OUT_1,
                 PWM_OUT_1_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PD0_M0PWM6 = {
                 PORT_D,
                 PIN_0,
                 SYSCTL_PERIPH_PWM0,
                 PWM_SYSCLK_DIV_1,
                 PWM0_BASE,
                 PWM_GEN_3,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PD0_M0PWM6,
                 PWM_OUT_6,
                 PWM_OUT_6_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PD0_M1PWM0 = {
                 PORT_D,
                 PIN_0,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_0,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PD0_M1PWM0,
                 PWM_OUT_0,
                 PWM_OUT_0_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PD1_M0PWM7 = {
                 PORT_D,
                 PIN_1,
                 SYSCTL_PERIPH_PWM0,
                 PWM_SYSCLK_DIV_1,
                 PWM0_BASE,
                 PWM_GEN_3,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PD1_M0PWM7,
                 PWM_OUT_7,
                 PWM_OUT_7_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PD1_M1PWM1 = {
                 PORT_D,
                 PIN_1,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_0,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PD1_M1PWM1,
                 PWM_OUT_1,
                 PWM_OUT_1_BIT,
                 1600            //16MHZ / 10KHZ = 1600
}; 
PWM_t PE4_M0PWM4 = {
                 PORT_E,
                 PIN_4,
                 SYSCTL_PERIPH_PWM0,
                 PWM_SYSCLK_DIV_1,
                 PWM0_BASE,
                 PWM_GEN_2,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PE4_M0PWM4,
                 PWM_OUT_4,
                 PWM_OUT_4_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PE4_M1PWM2 = {
                 PORT_E,
                 PIN_4,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_1,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PE4_M1PWM2,
                 PWM_OUT_2,
                 PWM_OUT_2_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PE5_M0PWM5 = {
                 PORT_E,
                 PIN_5,
                 SYSCTL_PERIPH_PWM0,
                 PWM_SYSCLK_DIV_1,
                 PWM0_BASE,
                 PWM_GEN_2,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PE5_M0PWM5,
                 PWM_OUT_5,
                 PWM_OUT_5_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PE5_M1PWM3 = {
                 PORT_E,
                 PIN_5,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_1,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PE5_M1PWM3,
                 PWM_OUT_3,
                 PWM_OUT_3_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PF0_M1PWM4 = {
                 PORT_F,
                 PIN_0,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_2,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PF0_M1PWM4,
                 PWM_OUT_4,
                 PWM_OUT_4_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PF1_M1PWM5 = {
                 PORT_F,
                 PIN_1,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_2,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PF1_M1PWM5,
                 PWM_OUT_5,
                 PWM_OUT_5_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PF2_M1PWM6 = {
                 PORT_F,
                 PIN_2,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_3,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PF2_M1PWM6,
                 PWM_OUT_6,
                 PWM_OUT_6_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
PWM_t PF3_M1PWM7 = {
                 PORT_F,
                 PIN_3,
                 SYSCTL_PERIPH_PWM1,
                 PWM_SYSCLK_DIV_1,
                 PWM1_BASE,
                 PWM_GEN_3,
                 PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC ,
                 GPIO_PF3_M1PWM7,
                 PWM_OUT_7,
                 PWM_OUT_7_BIT,
                 1600            //16MHZ / 10KHZ = 1600
};
