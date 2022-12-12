#ifndef IR_INFERARED_INTERFACE_H
#define IR_INFERARED_INTERFACE_H

#include "GPIO_interface.h"

typedef enum
{
    OBJECT_PRESENT = GPIO_LOW,
    OBJECT_ABSENT = GPIO_HIGH

}EXISTANCE;

typedef struct
{
    PORT port;
    PIN Pin;

}IR_Config_t;

void IR_voidInit(const IR_Config_t * Copy_ptrstrIR);
EXISTANCE Check_enumObject_Existance(const IR_Config_t * Copy_ptrstrIR);




#endif