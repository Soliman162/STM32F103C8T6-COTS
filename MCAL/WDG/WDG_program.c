#include "STD_TYPES.h"
#include "STM32F103C8.h"
#include "BIT_MATH.h"

#include "WDG_interface.h"
#include "WDG_private.h"
#include "WDG_config.h"

void (*WWDG_ISR)(void) = NULL ;

void WWDG_voidInit(void)
{
    /* T6 must be set before enable WWDG */
    SET_BIT(WWDG->WWDG_CR, 6);
    /* enable WWDG */
    SET_BIT(WWDG->WWDG_CR,7);
    
}
void WWDG_voidEnable_EarlyWakeUp_INT(void *EWI_ISR(void))
{
    SET_BIT(WWDG->WWDG_CFR,9);
    WWDG_ISR = EWI_ISR;
}

static inline ERROR_enumSTATE Calc_voidPrescaller_TBits(u8 *prescaller, u8 * Tbit)
{
    ERROR_enumSTATE LOC_enumState = STD_TYPES_NOK;
    u8 pow=0;

    for(u8 i=0;i<4;i++)
    {
        //pow = i%2?;
        for(u8 j=0;j<=T_BIT_MAX;j++)
        {
            if( TIMEOUT_CALC(,) )
            {

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
