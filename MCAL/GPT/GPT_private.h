#ifndef GPT_PRIVATE_H
#define GPT_PRIVATE_H

typedef u16 Timer_Size_t;

#define MAX_COUNTER_VALUE       0xFFFF//65536//2^16

void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);

#endif