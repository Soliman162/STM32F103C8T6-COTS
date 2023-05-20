#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"

#include "RCC_interface.h"

#include "GPT_interface.h"
#include "GPT_private.h"
#include "GPT_config.h"

static void (*GPT_Timer_ISR[3])(void) = {NULL};
static GPT_2_5_REG_DEF_t *Timer_2_5[4] = {GPT_2,GPT_3,GPT_4};

void Timer_voidInit(GP_Timer_Config Timer_num)
{
   RCC_enumPeripheralCLKEnable(APB1_BUS,Timer_num.Timer);
   Timer_2_5[Timer_num.Timer]->CR1 = (0 | 0b11<<8 | 1<<7 | Timer_num.Direction<<4 | 1<<2 )  ;
   Timer_2_5[Timer_num.Timer]->PSC = Timer_num.Prescaller-1; 
}

void Timer_voidStart_Count(GP_Timer_Config Timer_num,Timer_Size_t Count_value)
{
   /* set counter value at auto reload register */
   Timer_2_5[Timer_num.Timer]->ARR = Count_value;
   /*enable counter*/
   SET_BIT(Timer_2_5[Timer_num.Timer]->CR1,0);
}

void Timer_voidStop(GP_Timer_Config Timer_num)
{
    /*disable counter*/
   CLR_BIT(Timer_2_5[Timer_num.Timer]->CR1, 0); 
}

void Timer_voidDelay_Us(GP_Timer_Config Timer_num,u32 Count_value)
{
   /* set counter value at auto reload register */
   Timer_2_5[Timer_num.Timer]->ARR = MAX_COUNTER_VALUE;
   /*enable counter*/
   SET_BIT(Timer_2_5[Timer_num.Timer]->CR1,0);

   while (Count_value>=MAX_COUNTER_VALUE)
   {
      /*wait until counter overflow*/  
      while(GET_BIT(Timer_2_5[Timer_num.Timer]->SR,0) != 1);
      /* clear update intrrupt flag */ 
      CLR_BIT(Timer_2_5[Timer_num.Timer]->SR,0);
      Count_value -= MAX_COUNTER_VALUE;
   }
   if(Count_value>0)
   {
      /* set counter value at auto reload register */
      Timer_2_5[Timer_num.Timer]->ARR = Count_value;
      /*wait until counter overflow*/ 
      while(GET_BIT(Timer_2_5[Timer_num.Timer]->SR,0) != 1);
   }
   /*disable counter*/
   CLR_BIT(Timer_2_5[Timer_num.Timer]->CR1,0);
}

void Timer_voidUpdateINT_Enable(GP_Timer_Config Timer_num, void (*Copy_ptrISR)(void))
{
   GPT_Timer_ISR[Timer_num.Timer] = Copy_ptrISR;
   SET_BIT(Timer_2_5[Timer_num.Timer]->DIER,0);
}
void Timer_voidUpdateINT_Disable(GP_Timer_Config Timer_num)
{
   GPT_Timer_ISR[Timer_num.Timer] = NULL;
   CLR_BIT(Timer_2_5[Timer_num.Timer]->DIER,0);
}

void TIM2_IRQHandler(void)
{
   if( GPT_Timer_ISR[GP_TIMER_2] != NULL )
   {
      CLR_BIT(Timer_2_5[GP_TIMER_2]->SR,0);
      GPT_Timer_ISR[GP_TIMER_2]();
   }
}
void TIM3_IRQHandler(void)
{
   if( GPT_Timer_ISR[GP_TIMER_3] != NULL )
   {
      CLR_BIT(Timer_2_5[GP_TIMER_3]->SR,0);
      GPT_Timer_ISR[GP_TIMER_3]();
   }
}
void TIM4_IRQHandler(void)
{
   if( GPT_Timer_ISR[GP_TIMER_4] != NULL )
   {
      CLR_BIT(Timer_2_5[GP_TIMER_4]->SR,0);
      GPT_Timer_ISR[GP_TIMER_4]();
   }
}
