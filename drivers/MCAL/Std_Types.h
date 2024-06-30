/*
 * Std_Types.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_





/******************************** Section :Includes start *****************************/
/**
 * @headerfile <stdlib.h>
 */
#include <stdlib.h>

/**
 * @headerfile <stdint.h>
 */
#include <stdint.h>
/**
 * @headerfile <stdbool.h>
 */
#include <stdbool.h>


/******************************** Section :Includes end *******************************/


/******************************** Section: Macro Declarations start *******************/
/**
 * @brief  success return code.
 *
 */
#define E_OK       0x00


/**
 * @brief Return code for error .
 *
 */
#define E_NOT_OK   0x01


/******************************** Section: Macro Declarations end *********************/



/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/



/******************************** Section: Data Type Declarations start ***************/
/**
 * @brief  type can be used as standard API return type which is shared between the RTE and BSW modules
 * @implements Std_ReturnType
 */
typedef unsigned char Std_ReturnType;

typedef enum{
    Idle_State,
    MovingHighSpeed_State,
    MovingLowSpeed_State
}State_t;
/******************************** Section: Data Type Declarations end *****************/



/*********************************Section: Functions Declarations start ***************/
/*********************************Section: Functions Declarations end *****************/




#endif /* STD_TYPES_H_ */
