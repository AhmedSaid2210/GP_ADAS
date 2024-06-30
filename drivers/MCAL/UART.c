/*
 * SPI.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */



#include "UART.h"

Std_ReturnType MCAL_UART_Inti(UART_t *uart)
{
    Std_ReturnType ret = E_OK;
      if(NULL == uart)
      {
          ret = E_NOT_OK;
      }
      else
      {
          uint32_t  port_enable = 0;
          switch(uart->PORT)
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
					
					// Enable the UARTn peripheral
					SysCtlPeripheralEnable(uart->SYSCTL_PERIPH_UARTn);
					// Wait for the UARTn module to be ready.
					while(!SysCtlPeripheralReady(uart->SYSCTL_PERIPH_UARTn)){/* Nothing */}

			
          // Configure UART pins
          GPIOPinConfigure(uart->GPIO_Pin_UnRX);
          GPIOPinConfigure(uart->GPIO_Pin_UnTX);
					
					GPIOPinTypeUART(uart->PORT, uart->PINS);


				 // Initialize the UART for  baud rate, bit data,  parity, and stop bit
					UARTConfigSetExpClk(uart->UARTn_BASE, SysCtlClockGet(), uart->baudRate,uart->UART_CONFIGS);

				 // Enable the UART
				  UARTEnable(uart->UARTn_BASE);
      }
      return ret;
}
Std_ReturnType MCAL_UART_SendData(UART_t *uart , uint8_t  SendData )
{
    Std_ReturnType ret = E_OK;
         if(NULL == uart)
         {
             ret = E_NOT_OK;
         }
         else
         {
             UARTCharPut(uart->UARTn_BASE,SendData);
         }
         return ret;
}

Std_ReturnType MCAL_UART_ReceiveData(UART_t *uart , uint8_t * ReceiveData )
{
    Std_ReturnType ret = E_OK;
         if(NULL == uart)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 
					*ReceiveData = UARTCharGet(UART7_BASE);

         }
         return ret;
}
Std_ReturnType MCAL_UART_SendArry(UART_t *uart , uint8_t *SendData ,uint8_t len )
{
	Std_ReturnType ret = E_OK;
         if(NULL == uart)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 
					 for (uint8_t i = 0; i < len; i++) 
							UARTCharPut(uart->UARTn_BASE,SendData[i]);
						
          
         }
         return ret;
}
Std_ReturnType MCAL_UART_ReceiveArry(UART_t *uart , uint8_t * ReceiveData, uint8_t len )
{
		Std_ReturnType ret = E_OK;
         if(NULL == uart)
         {
             ret = E_NOT_OK;
         }
         else
         {
					 
					 for (uint8_t i = 0; i < len; i++) 
							ReceiveData[i] =UARTCharGet(uart->UARTn_BASE);
         }
         return ret;			 
}



