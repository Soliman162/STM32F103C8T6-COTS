#ifndef WDG_INTERFACE_H
#define WDG_INTERFACE_H

void WWDG_voidInit(void);
void WWDG_voidEnable_EarlyWakeUp_INT(void (*EWI_ISR)(void));

#endif