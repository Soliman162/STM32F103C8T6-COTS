#ifndef GPT_INTERFACE_H
#define GPT_INTERFACE_H

typedef enum 
{
    GP_TIMER_2=0,
    GP_TIMER_3,
    GP_TIMER_4

}GP_TIMER;
 
typedef enum
{
    UP=0,
    DOWN
    
}COUNT_DIR;

typedef struct 
{
    GP_TIMER Timer;
    COUNT_DIR  Direction;
    Timer_Size_t Prescaller;
    
}GP_Timer_Config;

void Timer_voidInit(GP_Timer_Config Timer_num);
void Timer_voidStart_Count(GP_Timer_Config Timer_num,Timer_Size_t Count_value);

void Timer_voidUpdateINT_Enable(GP_Timer_Config Timer_num, void (*Copy_ptrISR)(void));
void Timer_voidUpdateINT_Disable(GP_Timer_Config Timer_num);

void Timer_voidStop(GP_Timer_Config Timer_num);
void Timer_voidDelay_Us(GP_Timer_Config Timer_num,u32 Count_value);

#endif
