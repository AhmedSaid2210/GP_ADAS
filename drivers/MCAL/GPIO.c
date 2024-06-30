/*
 * GPIO.c
 *
 *  Created on: ???/???/????
 *      Author: scs9112021
 */


#include "GPIO.h"



Std_ReturnType MCAL_GPIO_Pin_Init(const pin_t *pin)
{
    Std_ReturnType ret = E_OK;
      if(NULL == pin)
      {
          ret = E_NOT_OK;
      }
      else
      {
          uint32_t  port_enable = 0;
          switch(pin->port)
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
				
          //SysCtlGPIOAHBEnable(port_enable);

          SysCtlPeripheralEnable(port_enable);
					if((pin->port == PORT_F && pin->pin == PIN_0) || (pin->port == PORT_D && pin->pin == PIN_7) || (pin->port == PORT_A && pin->pin == PIN_2)
						|| (pin->port == PORT_A && pin->pin == PIN_3)|| (pin->port == PORT_A && pin->pin == PIN_4)|| (pin->port == PORT_A && pin->pin == PIN_5))
					{
						GPIOUnlockPin(pin->port,pin->pin);
						
					}

          while(!SysCtlPeripheralReady(port_enable)) {  /* Nothing */}

          GPIOPadConfigSet(pin->port, pin->pin, pin->current, pin->type);

          GPIODirModeSet(pin->port, pin->pin, pin->dir);

          GPIOPinWrite(pin->port, pin->pin, LOW);

      }
      return ret;
}
Std_ReturnType MCAL_GPIO_Pin_Write(const pin_t *pin , uint8_t logic)
{
    Std_ReturnType ret = E_OK;
      if(NULL == pin || logic > 2)
      {
          ret = E_NOT_OK;
      }
      else
      {
          uint8_t pin_state = 0;

          switch(logic)
          {
          case HIGH :
              GPIOPinWrite(pin->port, pin->pin, pin->pin);
              break;

          case LOW :
              GPIOPinWrite(pin->port, pin->pin, 0x00);
              break;

          default:  // TOGGLE
              pin_state = GPIOPinRead(pin->port, pin->pin);
              if(pin->pin == pin_state)
              {
                  GPIOPinWrite(pin->port, pin->pin, 0x00);
              }
              else
              {
                  GPIOPinWrite(pin->port, pin->pin, pin->pin);
              }
              break;
          }
      }
      return ret;
}
uint8_t MCAL_GPIO_Pin_Read(const pin_t *pin )
{
    Std_ReturnType ret = E_OK;
      if(NULL == pin )
      {
          ret = E_NOT_OK;
      }
      else
      {
          uint8_t pin_state = 0;

          pin_state = GPIOPinRead(pin->port, pin->pin);

          if(pin->pin == pin_state)
          {
             return  PIN_HIGH;
          }
          else
          {
              return  PIN_LOW;
          }
      }
      
}


/**
 * @brief This function for interrupt  .
 *
 * @param Int_pin The variable initialize by user contain config of interrupt.
 *
 * @return E_OK if success function or E_NOT_OK if function fail
 */
Std_ReturnType MCAL_GPIO_Int_Config(const Int_pin_t *Int_pin, void (*fun)(void))
{
    Std_ReturnType ret = E_OK;
          if(NULL == Int_pin)
          {
              ret = E_NOT_OK;
          }
          else
          {
              IntMasterDisable();

              GPIOIntClear(Int_pin->port, Int_pin->pin);

              IntRegister(Int_pin->Int_port , fun );

              GPIOIntTypeSet(Int_pin->port, Int_pin->pin, Int_pin->Int_type);

              IntPrioritySet(Int_pin->Int_port, Int_pin->pri);

              GPIOIntEnable(Int_pin->port, Int_pin->pin);

              IntEnable(Int_pin->Int_port);

              IntMasterEnable();

          }
          return ret;
}

