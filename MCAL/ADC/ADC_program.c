#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"

#include "RCC_interface.h"
#include "GPT_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

//GP_Timer_Config Glob_timer

void ADC_voidInit(void)
{
    RCC_enumPeripheralCLKEnable(APB2_BUS,ADC1_CLK);
    /*enable ADC set ADON in CR2*/
    SET_BIT(ADC1->CR2,0);
    #if GROUP_SELECTION == REGULAR
        /*choose number of conversions in group*/
        ADC1->SQRX[0] |= (NUM_OF_CONVERSION-1)<<20;
    #elif GROUP_SELECTION == INJECTED
        /*choose number of conversions in group*/
        ADC1->JSQR |= (NUM_OF_CONVERSION-1)<<20;
    #endif

    for(u8 i=0;i<NUM_OF_CONVERSION;i++)
    {
        SET_voidChannel_sequence(CONVERSIONS[i][0],CONVERSIONS[i][1]);
    }
}
f32 *ADC_f32GET_Conversion(void)
{
    static f32 result[4] = 0.0;
    /*start conversion ADC set ADON in CR2*/
    SET_BIT(ADC1->CR2,0);
    
    #if GROUP_SELECTION == REGULAR
        while(GET_BIT(ADC1->SR,1) != 1);
        result = (ADC1->DR&0x0000FFFF) * STEPSIZE;
    #elif GROUP_SELECTION == INJECTED
        while(GET_BIT(ADC1->SR,2) != 1);
        result[i] = (ADC1->JDR[0] &0x0000FFFF) * STEPSIZE;
    #endif
    return &result;
}

void ADC_voidEnable_INT(void)
{
    SET_BIT(ADC1->CR1,5);
}

static inline void SET_voidChannel_sequence(u8 Channel , u8 SEQuence)
{
    #if GROUP_SELECTION == REGULAR
        if( SEQuence<=6 && SEQuence>=1 )
        {
            ADC1->SQRX[2] |= Channel<<((SEQuence-1)*5) ;
        }else if (SEQuence<=12 && SEQuence>=7)
        {
            ADC1->SQRX[1] |= Channel<<((SEQuence-7)*5) ;
        }else if (SEQuence<=16 && SEQuence>=13)
        {
            ADC1->SQRX[0] |= Channel<<((SEQuence-13)*5) ;
        }
    #elif GROUP_SELECTION == INJECTED
        ADC1->JSQR |= Channel<<((SEQuence-1)*5) ;
    #endif
} 
