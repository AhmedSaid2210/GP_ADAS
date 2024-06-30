
#include "communication.h"

Std_ReturnType HAL_Comm_Inti(void)
{
	 Std_ReturnType ret = E_OK;
         
			#if defined SPI
					 	MCAL_SSI_Inti(&SPI_config);
		  #elif defined UART
					  MCAL_UART_Inti(&UART_Config);
      #endif
         return ret;

}

Std_ReturnType HAL_Comm_SendFrame( uint8_t * SendData )
{
	{
	 Std_ReturnType ret = E_OK;
         if(NULL == SendData)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 	SendData[5] = HAL_Comm_CheckSum_Generator( SendData[4] );
					
						for(int i =0;i<7;i++){
							
							#if defined SPI
							
								MCAL_SSI_SendData(&SPI_config,SendData[i]);
							
							#elif defined UART
							
								
								MCAL_UART_SendData(&UART_Config,SendData[i]);
							
							#endif
								
							
						}
         }
         return ret;

}
}

Std_ReturnType HAL_Comm_ReceiveFrame( uint8_t * ReceiveData )
{
	 Std_ReturnType ret = E_OK;
         if(NULL == ReceiveData)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 
						for(int i =0;i<7;i++){
							
							#if defined SPI
							
							MCAL_SSI_ReceiveData(&SPI_config, ReceiveData + i);
							
							#elif defined UART
							
								MCAL_UART_ReceiveData(&UART_Config, ReceiveData + i);
							#endif
							
							
						}

         }
         return ret;

}

uint8_t HAL_Comm_CheckSum_Generator(uint8_t Data )
{
	return (0xFF ^ Data);
}

Std_ReturnType HAL_Comm_CheckFrame( uint8_t * ReceiveData )
{
	 Std_ReturnType ret = E_OK;
         if(NULL == ReceiveData)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 uint8_t data_checksum ;
					 
					 data_checksum = HAL_Comm_CheckSum_Generator( ReceiveData[4] );
					 
					 if(ReceiveData[5] != data_checksum)
					 {
						 ret = E_NOT_OK;
					 }
					 else
					 {
						 
					 }

         }
         return ret;

}

