#ifndef GPT_PRIVATE_H
#define GPT_PRIVATE_H

//GP_Timer_Config GLOB_Timer_4 = {GP_TIMER_4,UP,8};

#define MAX_COUNTER_VALUE       0xFFFF//65536//2^16

void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);

#endif