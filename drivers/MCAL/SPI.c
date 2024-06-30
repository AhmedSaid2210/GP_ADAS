/*
 * SPI.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */



#include "SPI.h"

Std_ReturnType MCAL_SSI_Inti(SSI_t *SSI)
{
    Std_ReturnType ret = E_OK;
      if(NULL == SSI)
      {
          ret = E_NOT_OK;
      }
      else
      {
          uint32_t  port_enable = 0;
          switch(SSI->PORT)
          {
          case PORT_A:
              port_enable = SYSCTL_PERIPH_GPIOA ;
              break;
          case PORT_B:
              port_enable = SYSCTL_PERIPH_GPIOB ;
              break;
          case PORT_C:
              port_enable = SYSCTL_PERIPH_GPIOC ;
              break;
          case PORT_D:
              port_enable = SYSCTL_PERIPH_GPIOD ;
              break;
          case PORT_E:
              port_enable = SYSCTL_PERIPH_GPIOE ;
              break;
          case PORT_F :
              port_enable = SYSCTL_PERIPH_GPIOF ;
              break;
          default :
              break;
          }

          // Enable the PORT module
          //SysCtlGPIOAHBEnable(port_enable);

          SysCtlPeripheralEnable(port_enable);

          while(!SysCtlPeripheralReady(port_enable)) { /* Nothing */ }

			
          // Configure SSI0 pins
          GPIOPinConfigure(SSI->SSInCLK);
          GPIOPinConfigure(SSI->SSInFSS);
          GPIOPinConfigure(SSI->SSInTX);
          GPIOPinConfigure(SSI->SSInRX);
					
					// Configure SSI0
          GPIOPinTypeSSI(SSI->PORT,SSI->PINS);
					
          // Enable the SSI0 module
          SysCtlPeripheralEnable(SSI->SYSCTL_PERIPH_SSIn);

          while(!SysCtlPeripheralReady(SSI->SYSCTL_PERIPH_SSIn)) { /* Nothing */ }

         // Configure SSI0 as a master, mode 0, 1 MHz, 8-bit data
         SSIConfigSetExpClk(SSI->SSIn_BASE, SysCtlClockGet(), SSI->SSI_FRF_MOTO_MODE, SSI->SSI_MODE, SSI->BitRate, SSI->DataWidth);

          // Enable the SSI0 module
          SSIEnable(SSI->SSIn_BASE);
      }
      return ret;
}
Std_ReturnType MCAL_SSI_SendData(SSI_t *SSI , uint8_t  SendData )
{
    Std_ReturnType ret = E_OK;
         if(NULL == SSI)
         {
             ret = E_NOT_OK;
         }
         else
         {

             // Wait until the transmit FIFO is not full
             // while(SSIBusy(SSI->SSIn_BASE));

             SSIDataPut(SSI->SSIn_BASE, SendData );
						 //while(SSIDataPutNonBlocking(SSI->SSIn_BASE, SendData) == 0);
         }
         return ret;
}

Std_ReturnType MCAL_SSI_ReceiveData(SSI_t *SSI , uint32_t *ReceiveData )
{
    Std_ReturnType ret = E_OK;
         if(NULL == SSI)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 
					 while(SSIDataGetNonBlocking(SSI->SSIn_BASE, ReceiveData) == 0);
					 
						//SSIDataGet(SSI->SSIn_BASE,ReceiveData);

         }
         return ret;
}
Std_ReturnType MCAL_SSI_SendReceiveSynch(SSI_t *SSI ,uint8_t  SendData , uint32_t * ReceiveData )
{
	Std_ReturnType ret = E_OK;
         if(NULL == SSI)
         {
             ret = E_NOT_OK;
         }
         else
         {

             // Wait until the transmit FIFO is not full
             // while(SSIBusy(SSI->SSIn_BASE));

							while(SSIBusy(SSI->SSIn_BASE));
              SSIDataPut(SSI->SSIn_BASE, SendData );
					    // while(SSIBusy(SSI->SSIn_BASE));

              //while(SSIDataGetNonBlocking(SSI->SSIn_BASE, ReceiveData) == 0	);
					    SSIDataGet(SSI->SSIn_BASE,ReceiveData);

              // Wait until the SSI module is done transferring data
              //while(SSIBusy(SSI->SSIn_BASE));
         }
         return ret;
}
Std_ReturnType MCAL_SSI_SendArray(SSI_t *SSI , uint8_t * SendData ,uint8_t len)
{
		Std_ReturnType ret = E_OK;
         if(NULL == SSI)
         {
             ret = E_NOT_OK;
         }
         else
         {

             uint8_t i;

						for (i = 0; i < len; i++) {
							// Wait until the transmit FIFO is not full
							//while(SSIBusy(SSI->SSIn_BASE));

							// Send data
								SSIDataPut(SSI->SSIn_BASE, SendData[i] );
						}
         }
         return ret;			 
}


Std_ReturnType MCAL_SSI_ReceiveArray(SSI_t *SSI , uint8_t * ReceiveData , uint8_t len )
{
		
				Std_ReturnType ret = E_OK;
         if(NULL == SSI)
         {
             ret = E_NOT_OK;
         }
         else
         {
            uint8_t i;

						for (i = 0; i < len; i++) {
            // Wait until receive FIFO is not empty
            while(SSIDataGetNonBlocking(SSI->SSIn_BASE, &ReceiveData[i]) == 0);
						}
    
         }
         return ret;	
}
