#ifndef IR_INFERARED_INTERFACE_H
#define IR_INFERARED_INTERFACE_H

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
void Check_voidObject_Existance(const IR_Config_t * Copy_ptrstrIR, EXISTANCE *Copy_Check );

#endif