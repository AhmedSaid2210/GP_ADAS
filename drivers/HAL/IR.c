#include "IR.h"

Std_ReturnType HAL_IR_Inti(IR_t *ir)
{
	  Std_ReturnType ret = E_OK;
         if(NULL == ir)
         {
             ret = E_NOT_OK;
         }
         else
         {
            MCAL_GPIO_Pin_Init(ir->LeftIR);
					  MCAL_GPIO_Pin_Init(ir->RightIR);
         }
         return ret;
}

Std_ReturnType HAL_IR_Read_RightIR(IR_t *ir ,uint8_t *val )
{
		  Std_ReturnType ret = E_OK;
         if(NULL == ir)
         {
             ret = E_NOT_OK;
         }
         else
         {

					  *val = MCAL_GPIO_Pin_Read(ir->RightIR);
         }
         return ret;
	
}


Std_ReturnType HAL_IR_Read_LeftIR(IR_t *ir ,uint8_t *val )
{
		  Std_ReturnType ret = E_OK;
         if(NULL == ir)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 *val = MCAL_GPIO_Pin_Read(ir->LeftIR);
         }
         return ret;
}
