#ifndef WDG_PRIVATE_H
#define WDG_PRIVATE_H

#define DIVED_BY_1  0b00
#define DIVED_BY_2  0b01
#define DIVED_BY_4  0b10
#define DIVED_BY_8  0b11

#define T_BIT_MAX   63

// 0 1 2 3
// 2 2 2 2

// 1 2 4 8

#define TIMEOUT_CALC(wdgt,Tbits)   ((float)(4096*wdgt*(Tbits+1))/CLK)*1000     


static inline ERROR_enumSTATE Calc_voidPrescaller_TBits(u8 *prescaller, u8 * Tbit);


#endif