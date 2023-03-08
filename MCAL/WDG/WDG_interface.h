#ifndef WDG_INTERFACE_H
#define WDG_INTERFACE_H

ERROR_enumSTATE WWDG_voidInit(void);
void WWDG_voidSet_EWI_CallBack_func(void (*EWI_ISR)(void));

#endif