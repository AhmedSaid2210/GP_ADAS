/*
 * RCC.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef RCC_H_
#define RCC_H_



/******************************** Section :Includes start *****************************/
#include "STD_Types.h"
#include "driverlib/sysctl.h"

/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/
/******************************** Section: Macro Declarations end *********************/


/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/


/******************************** Section: Data Type Declarations start ***************/
typedef struct {
    uint32_t SYSCTL_OSC    ;     // oscillator is chosen with one of the following value
    uint32_t SYSCTL_XTAL   ;     // The external crystal frequency (SYSCTL_OSC_MAIN) is chosen with one of the following value
    uint32_t SYSCTL_USE    ;     // The use of the PLL or osc
    uint32_t SYSCTL_SYSDIV ;     // The system clock divider is chosen with one of the following value

}RCC_t;


typedef struct {
    uint32_t SYSCTL_OSC    ;     // oscillator is chosen with one of the following value
    uint32_t SYSCTL_USE    ;     // The use of the PLL or osc
    uint32_t SYSCTL_SYSDIV ;     // The system clock divider is chosen with one of the following value

}RCC_INT_t;
/******************************** Section: Data Type Declarations end *****************/




/*********************************Section: Functions Declarations start ***************/
/**
 * @brief This function used to initialize internal clock source .
 *
 * @param RCC The variable initialize by user contain config of internal clock source .
 *
 */
Std_ReturnType MCAL_RCC_SysCtlClockInternal(const RCC_INT_t *RCC);

/**
 * @brief This function used to initialize external clock source  .
 *
 * @param RCC The variable initialize by user contain config of external clock source .
 *
 */
Std_ReturnType MCAL_RCC_SysCtlClockExternal(const RCC_t *RCC);

/*********************************Section: Functions Declarations end *****************/



#endif /* RCC_H_ */
