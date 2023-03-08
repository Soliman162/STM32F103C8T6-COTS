#include "STD_TYPES.h"
#include "STM32F103C8.h"
#include "BIT_MATH.h"

#include "WDG_interface.h"
#include "WDG_private.h"
#include "WDG_config.h"

static u8 LOC_T_u8Bits = 0;
static void (*WWDG_ISR)(void) = NULL ;

ERROR_enumSTATE WWDG_voidInit(void)
{
    u8 LOC_Prescaller_u8wdgt = 0;

    if ( Calc_voidPrescaller_TBits(&LOC_Prescaller_u8wdgt, &LOC_T_u8Bits) )
    {
        /*set prescaller */
        WWDG->WWDG_CFR |= LOC_Prescaller_u8wdgt<<7;
        /*enable WWDG - T6 must be set before enable WWDG - load downcounter*/
        WWDG->WWDG_CR = (0b11000000 | LOC_T_u8Bits); 
        /*enable early wake up interrupt*/
        SET_BIT(WWDG->WWDG_CFR,9);
    }else
    {
        return STD_TYPES_NOK;
    }
    return STD_TYPES_OK;
}
void WWDG_voidSet_EWI_CallBack_func(void (*EWI_ISR)(void))
{
    WWDG_ISR = EWI_ISR;
}

static inline ERROR_enumSTATE Calc_voidPrescaller_TBits(u8 *prescaller, u8 * Tbit)
{
    f32 reg_f32Value = 0;
    for(u8 i=1;i<=8;i*=2)
    {
        for(u8 j=0;j<=T_BIT_MAX;j++)
        {
            reg_f32Value = TIMEOUT_CALC(i,j);
            if( reg_f32Value<WWDG_TIMEOUT+1 && reg_f32Value>WWDG_TIMEOUT-1 )
            {
                *Tbit = j;
                *prescaller = i;
                return STD_TYPES_OK;
            }
        }
    }
    return STD_TYPES_NOK;
}

void WWDG_IRQHandler(void)
{
    /* clear interrupt flag */
    WWDG->WWDG_SR = 0;
    /*Check call Back function doesn't equle null*/
    if( WWDG_ISR != NULL )
    {
        /*excute call Back function*/
        (*WWDG_ISR)();
    }
    /*reload down counter*/
    WWDG->WWDG_CR = 0b11000000 | LOC_T_u8Bits;
}
