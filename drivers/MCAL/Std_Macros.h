/*
 * Std_Macros.h
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_




/******************************** Section :Includes start *****************************/

/******************************** Section :Includes end *******************************/



/******************************** Section: Macro Declarations start *******************/


#define SET_BIT(reg,bit)   reg|=(1<<bit)
#define CLR_BIT(reg,bit)   reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)   reg^=(1<<bit)
#define READ_BIT(reg,bit)  ((reg&(1<<bit))>>bit)


#define IS_BIT_SIT(reg,bit)  ((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,bit)       reg=(res<<(REGISTER_SIZE-bit)|(res>>bit))
#define ROL(reg,bit)       reg=(res>>(REGISTER_SIZE-bit)|(res<<bit))


/******************************** Section: Macro Declarations end *********************/



/******************************** Section: Macro Functions Declarations start *********/
/******************************** Section: Macro Functions Declarations end ***********/



/******************************** Section: Data Type Declarations start ***************/

/******************************** Section: Data Type Declarations end *****************/



/*********************************Section: Functions Declarations start ***************/
/*********************************Section: Functions Declarations end *****************/



#endif /* STD_MACROS_H_ */
