#include "STD_TYPES.h"
#include "STM32F103C8.h"
#include "BIT_MATH.h"

#include "WDG_interface.h"
#include "WDG_private.h"
#include "WDG_config.h"

static void (*WWDG_ISR)(void) = NULL ;

void WWDG_voidInit(void)
{
    u8 LOC_Prescaller_u8wdgt = 0;
    u8 LOC_T_u8Bits = 0;
    /* T6 must be set before enable WWDG */
    SET_BIT(WWDG->WWDG_CR, 6);
    /* enable WWDG */
    SET_BIT(WWDG->WWDG_CR,7);
    if ( Calc_voidPrescaller_TBits(&LOC_Prescaller_u8wdgt, &LOC_T_u8Bits) )
    {
        WWDG->WWDG_CFR |= LOC_Prescaller_u8wdgt<<7;
        WWDG->WWDG_CR |= LOC_T_u8Bits; 
    }else
    {
        #if 1
        #error WWDG_TIMEOUT cant be set
        #endif
    }
}
void WWDG_voidEnable_EarlyWakeUp_INT(void (*EWI_ISR)(void))
{
    SET_BIT(WWDG->WWDG_CFR,9);
    WWDG_ISR = EWI_ISR;
}

static inline ERROR_enumSTATE Calc_voidPrescaller_TBits(u8 *prescaller, u8 * Tbit)
{
    ERROR_enumSTATE LOC_enumState = STD_TYPES_NOK;

    for(u8 i=1;i<=8;i*=2)
    {
        for(u8 j=0;j<=T_BIT_MAX;j++)
        {
            if( TIMEOUT_CALC(i,j) == WWDG_TIMEOUT )
            {
                *Tbit = j;
                *prescaller = i;
                return STD_TYPES_OK;
            }
        }
    }
    return LOC_enumState;
}

void WWDG_IRQHandler(void)
{
    /* clear interrupt flag */
    WWDG->WWDG_SR = 0;
    if( WWDG_ISR != NULL )
    {
        (*WWDG_ISR)();
    }
}
