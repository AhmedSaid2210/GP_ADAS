/*
 * RCC_Config.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */





#include "RCC.h"

/******** (1) The oscillator is chosen with one of the following value ********/

/**
 *
 *  SYSCTL_OSC_MAIN         0x00000000  // Osc source is main osc
 *  SYSCTL_OSC_INT          0x00000010  // Osc source is internal. osc 16 MHz
 *  SYSCTL_OSC_INT4         0x00000020  // Osc source is internal. osc /4
 *  SYSCTL_OSC_INT30        0x00000030  // Osc source is internal. 30 KHz
 *  SYSCTL_OSC_EXT32        0x80000038  // Osc source is external. 32 KHz
 *
 *
 */

/******** (2) The external crystal frequency (SYSCTL_OSC_MAIN) is chosen with one of the following value ********/

/**
 *
 *
 *  SYSCTL_XTAL_4MHZ        0x00000180  // External crystal is 4MHz
 *  SYSCTL_XTAL_4_09MHZ     0x000001C0  // External crystal is 4.096MHz
 *  SYSCTL_XTAL_4_91MHZ     0x00000200  // External crystal is 4.9152MHz
 *  SYSCTL_XTAL_5MHZ        0x00000240  // External crystal is 5MHz
 *  SYSCTL_XTAL_5_12MHZ     0x00000280  // External crystal is 5.12MHz
 *  SYSCTL_XTAL_6MHZ        0x000002C0  // External crystal is 6MHz
 *  SYSCTL_XTAL_6_14MHZ     0x00000300  // External crystal is 6.144MHz
 *  SYSCTL_XTAL_7_37MHZ     0x00000340  // External crystal is 7.3728MHz
 *  SYSCTL_XTAL_8MHZ        0x00000380  // External crystal is 8MHz
 *  SYSCTL_XTAL_8_19MHZ     0x000003C0  // External crystal is 8.192MHz
 *  SYSCTL_XTAL_10MHZ       0x00000400  // External crystal is 10 MHz
 *  SYSCTL_XTAL_12MHZ       0x00000440  // External crystal is 12 MHz
 *  SYSCTL_XTAL_12_2MHZ     0x00000480  // External crystal is 12.288 MHz
 *  SYSCTL_XTAL_13_5MHZ     0x000004C0  // External crystal is 13.56 MHz
 *  SYSCTL_XTAL_14_3MHZ     0x00000500  // External crystal is 14.31818 MHz
 *  SYSCTL_XTAL_16MHZ       0x00000540  // External crystal is 16 MHz
 *  SYSCTL_XTAL_16_3MHZ     0x00000580  // External crystal is 16.384 MHz
 *  SYSCTL_XTAL_18MHZ       0x000005C0  // External crystal is 18.0 MHz
 *  SYSCTL_XTAL_20MHZ       0x00000600  // External crystal is 20.0 MHz
 *  SYSCTL_XTAL_24MHZ       0x00000640  // External crystal is 24.0 MHz
 *  SYSCTL_XTAL_25MHZ       0x00000680  // External crystal is 25.0 MHz
 *
 *
 *  values below SYSCTL_XTAL_5MHZ are not valid when the PLL is in operation
 *
 */

/******** (3) The use of the PLL is chosen with either  ********/
/**
 *
 *  SYSCTL_USE_PLL          0x00000000  // System clock is the PLL clock
 *  SYSCTL_USE_OSC          0x00003800  // System clock is the osc clock
 */


/******** (4) The system clock divider is chosen with one of the following value ********/

/**
 * SYSCTL_SYSDIV_1         0x07800000  // Processor clock is osc/pll /1  ---> not use in PLL
 * SYSCTL_SYSDIV_2         0x00C00000  // Processor clock is osc/pll /2  ---> not use in PLL
 * SYSCTL_SYSDIV_3         0x01400000  // Processor clock is osc/pll /3
 * to
 * SYSCTL_SYSDIV_64        0x01400000  // Processor clock is osc/pll /64
 *
 * SYSCTL_SYSDIV_2_5       0xC1000000  // Processor clock is pll / 2.5
 * SYSCTL_SYSDIV_3_5       0xC1800000  // Processor clock is pll / 3.5
 * SYSCTL_SYSDIV_4_5       0xC2000000  // Processor clock is pll / 4.5
 * SYSCTL_SYSDIV_5_5       0xC2800000  // Processor clock is pll / 5.5
 * SYSCTL_SYSDIV_6_5       0xC3000000  // Processor clock is pll / 6.5
 * SYSCTL_SYSDIV_7_5       0xC3800000  // Processor clock is pll / 7.5
 * SYSCTL_SYSDIV_8_5       0xC4000000  // Processor clock is pll / 8.5
 * SYSCTL_SYSDIV_9_5       0xC4800000  // Processor clock is pll / 9.5
 * SYSCTL_SYSDIV_10_5      0xC5000000  // Processor clock is pll / 10.5
 * SYSCTL_SYSDIV_11_5      0xC5800000  // Processor clock is pll / 11.5
 * SYSCTL_SYSDIV_12_5      0xC6000000  // Processor clock is pll / 12.5
 * SYSCTL_SYSDIV_13_5      0xC6800000  // Processor clock is pll / 13.5
 * SYSCTL_SYSDIV_14_5      0xC7000000  // Processor clock is pll / 14.5
 * SYSCTL_SYSDIV_15_5      0xC7800000  // Processor clock is pll / 15.5
 * SYSCTL_SYSDIV_16_5      0xC8000000  // Processor clock is pll / 16.5
 * SYSCTL_SYSDIV_17_5      0xC8800000  // Processor clock is pll / 17.5
 * SYSCTL_SYSDIV_18_5      0xC9000000  // Processor clock is pll / 18.5
 * SYSCTL_SYSDIV_19_5      0xC9800000  // Processor clock is pll / 19.5
 * SYSCTL_SYSDIV_20_5      0xCA000000  // Processor clock is pll / 20.5
 * SYSCTL_SYSDIV_21_5      0xCA800000  // Processor clock is pll / 21.5
 * SYSCTL_SYSDIV_22_5      0xCB000000  // Processor clock is pll / 22.5
 * SYSCTL_SYSDIV_23_5      0xCB800000  // Processor clock is pll / 23.5
 * SYSCTL_SYSDIV_24_5      0xCC000000  // Processor clock is pll / 24.5
 * SYSCTL_SYSDIV_25_5      0xCC800000  // Processor clock is pll / 25.5
 * SYSCTL_SYSDIV_26_5      0xCD000000  // Processor clock is pll / 26.5
 * SYSCTL_SYSDIV_27_5      0xCD800000  // Processor clock is pll / 27.5
 * SYSCTL_SYSDIV_28_5      0xCE000000  // Processor clock is pll / 28.5
 * SYSCTL_SYSDIV_29_5      0xCE800000  // Processor clock is pll / 29.5
 * SYSCTL_SYSDIV_30_5      0xCF000000  // Processor clock is pll / 30.5
 * SYSCTL_SYSDIV_31_5      0xCF800000  // Processor clock is pll / 31.5
 * SYSCTL_SYSDIV_32_5      0xD0000000  // Processor clock is pll / 32.5
 * SYSCTL_SYSDIV_33_5      0xD0800000  // Processor clock is pll / 33.5
 * SYSCTL_SYSDIV_34_5      0xD1000000  // Processor clock is pll / 34.5
 * SYSCTL_SYSDIV_35_5      0xD1800000  // Processor clock is pll / 35.5
 * SYSCTL_SYSDIV_36_5      0xD2000000  // Processor clock is pll / 36.5
 * SYSCTL_SYSDIV_37_5      0xD2800000  // Processor clock is pll / 37.5
 * SYSCTL_SYSDIV_38_5      0xD3000000  // Processor clock is pll / 38.5
 * SYSCTL_SYSDIV_39_5      0xD3800000  // Processor clock is pll / 39.5
 * SYSCTL_SYSDIV_40_5      0xD4000000  // Processor clock is pll / 40.5
 * SYSCTL_SYSDIV_41_5      0xD4800000  // Processor clock is pll / 41.5
 * SYSCTL_SYSDIV_42_5      0xD5000000  // Processor clock is pll / 42.5
 * SYSCTL_SYSDIV_43_5      0xD5800000  // Processor clock is pll / 43.5
 * SYSCTL_SYSDIV_44_5      0xD6000000  // Processor clock is pll / 44.5
 * SYSCTL_SYSDIV_45_5      0xD6800000  // Processor clock is pll / 45.5
 * SYSCTL_SYSDIV_46_5      0xD7000000  // Processor clock is pll / 46.5
 * SYSCTL_SYSDIV_47_5      0xD7800000  // Processor clock is pll / 47.5
 * SYSCTL_SYSDIV_48_5      0xD8000000  // Processor clock is pll / 48.5
 * SYSCTL_SYSDIV_49_5      0xD8800000  // Processor clock is pll / 49.5
 * SYSCTL_SYSDIV_50_5      0xD9000000  // Processor clock is pll / 50.5
 * SYSCTL_SYSDIV_51_5      0xD9800000  // Processor clock is pll / 51.5
 * SYSCTL_SYSDIV_52_5      0xDA000000  // Processor clock is pll / 52.5
 * SYSCTL_SYSDIV_53_5      0xDA800000  // Processor clock is pll / 53.5
 * SYSCTL_SYSDIV_54_5      0xDB000000  // Processor clock is pll / 54.5
 * SYSCTL_SYSDIV_55_5      0xDB800000  // Processor clock is pll / 55.5
 * SYSCTL_SYSDIV_56_5      0xDC000000  // Processor clock is pll / 56.5
 * SYSCTL_SYSDIV_57_5      0xDC800000  // Processor clock is pll / 57.5
 * SYSCTL_SYSDIV_58_5      0xDD000000  // Processor clock is pll / 58.5
 * SYSCTL_SYSDIV_59_5      0xDD800000  // Processor clock is pll / 59.5
 * SYSCTL_SYSDIV_60_5      0xDE000000  // Processor clock is pll / 60.5
 * SYSCTL_SYSDIV_61_5      0xDE800000  // Processor clock is pll / 61.5
 * SYSCTL_SYSDIV_62_5      0xDF000000  // Processor clock is pll / 62.5
 * SYSCTL_SYSDIV_63_5      0xDF800000  // Processor clock is pll / 63.5
 *
 */

 const RCC_t RCC_config80 = {
                    SYSCTL_OSC_MAIN,
                    SYSCTL_XTAL_16MHZ,
                    SYSCTL_USE_PLL,
                    SYSCTL_SYSDIV_2_5
};
 const RCC_t RCC_config16 = {
                    SYSCTL_OSC_MAIN,
                    SYSCTL_XTAL_16MHZ,
                    SYSCTL_USE_OSC,
                    SYSCTL_SYSDIV_1
};
 const RCC_t RCC_config40 = {
                    SYSCTL_OSC_MAIN,
                    SYSCTL_XTAL_16MHZ,
                    SYSCTL_USE_PLL,
                    SYSCTL_SYSDIV_5
};
  const RCC_t RCC_config50 = {
                    SYSCTL_OSC_MAIN,
                    SYSCTL_XTAL_16MHZ,
                    SYSCTL_USE_PLL,
                    SYSCTL_SYSDIV_4
};
 const RCC_t RCC_config66 = {
                    SYSCTL_OSC_MAIN,
                    SYSCTL_XTAL_16MHZ,
                    SYSCTL_USE_PLL,
                    SYSCTL_SYSDIV_3
};
const RCC_INT_t RCC_configInt16 = {
                    SYSCTL_OSC_INT,
                    SYSCTL_USE_OSC,
                    SYSCTL_SYSDIV_1
};
	

