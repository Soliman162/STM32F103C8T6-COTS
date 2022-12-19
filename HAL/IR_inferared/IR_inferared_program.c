#include "STD_TYPES.h"

#include "GPIO_interface.h"

#include "IR_inferared_interface.h"
#include "IR_inferared_private.h"
#include "IR_inferared_config.h"

void IR_voidInit(const IR_Config_t * Copy_ptrstrIR)
{
    GPIO_CONFIG_t CopY_IR_GPIO = {Copy_ptrstrIR->port,Copy_ptrstrIR->Pin,INPUT_FLOATING};    
    GPIO_enumSETPinMODE( &CopY_IR_GPIO );
}

void Check_voidObject_Existance(const IR_Config_t * Copy_ptrstrIR, EXISTANCE *Copy_Check )
{
    GPIO_CONFIG_t CopY_IR = {Copy_ptrstrIR->port,Copy_ptrstrIR->Pin,INPUT_FLOATING};
    GPIO_enumGETPinValue(&CopY_IR, Copy_Check );
}