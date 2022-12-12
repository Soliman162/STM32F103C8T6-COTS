#include "STD_TYPES.h"

#include "IR_inferared_interface.h"
#include "IR_inferared_private.h"
#include "IR_inferared_config.h"

EXISTANCE Object_Check = OBJECT_ABSENT ;

void IR_voidInit(const IR_Config_t * Copy_ptrstrIR)
{
    GPIO_CONFIG_t CopY_IR_GPIO = {Copy_ptrstrIR->port,Copy_ptrstrIR->Pin,INPUT_FLOATING};    
    GPIO_enumSETPinMODE( &CopY_IR_GPIO );
}

EXISTANCE Check_enumObject_Existance(const IR_Config_t * Copy_ptrstrIR)
{
    GPIO_CONFIG_t CopY_IR = {Copy_ptrstrIR->port,Copy_ptrstrIR->Pin,INPUT_FLOATING};

    GPIO_enumGETPinValue(&CopY_IR, &Object_Check );

    return Object_Check;
}