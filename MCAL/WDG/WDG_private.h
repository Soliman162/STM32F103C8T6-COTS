#ifndef WDG_PRIVATE_H
#define WDG_PRIVATE_H

#define T_BIT_MAX   63

#define TIMEOUT_FORMULA(wdgt,Tbits)   ((float)(4096*wdgt*(Tbits+1))/CLK)*1000     

static inline ERROR_enumSTATE Calc_voidPrescaller_TBits(u8 *prescaller, u8 * Tbit);


#endif