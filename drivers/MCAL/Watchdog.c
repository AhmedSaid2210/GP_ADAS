
#include "Watchdog.h"

void WatchdogIntHandler(void);

Std_ReturnType MCAL_Watchdog_Inti(void)
{
	Std_ReturnType ret = E_OK;
  
// Enable the Watchdog 0 peripheral
//
	SysCtlPeripheralEnable(SYSCTL_PERIPH_WDOG0);
//
// Wait for the Watchdog 0 module to be ready.
//
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_WDOG0));
//
// Check to see if the registers are locked, and if so, unlock them.
//
	if(WatchdogLockState(WATCHDOG0_BASE) == true)
	{
		WatchdogUnlock(WATCHDOG0_BASE);
	}
		WatchdogIntRegister(WATCHDOG0_BASE, WatchdogIntHandler);
	
    WatchdogIntEnable(WATCHDOG0_BASE);
	
  return ret;
}

Std_ReturnType MCAL_Watchdog_ReloadSet(float ui32Ms)
{
	Std_ReturnType ret = E_OK;
  
//
// Initialize the watchdog timer.
//
  ui32Ms =((float)ui32Ms /1000) * SysCtlClockGet();
	
	WatchdogReloadSet(WATCHDOG0_BASE, ui32Ms);
//
// Enable the reset.
//
	WatchdogResetEnable(WATCHDOG0_BASE);
//
// Enable the watchdog timer.
//
	WatchdogEnable(WATCHDOG0_BASE);

  return ret;
}



Std_ReturnType MCAL_Watchdog_Stop(void)
{
	Std_ReturnType ret = E_OK;
  
//
// Disable the reset.
//
	WatchdogResetDisable(WATCHDOG0_BASE);

  return ret;
}

void WatchdogIntHandler(void)
{
    // Clear the watchdog interrupt
    WatchdogIntClear(WATCHDOG0_BASE);
}
