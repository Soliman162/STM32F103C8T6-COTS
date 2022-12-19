#ifndef DC_INTERFACE_H
#define DC_INTERFACE_H

#include "GPIO_interface.h"

typedef struct
{
    PORT Port;
    PIN CW_pin;
    PIN CCW_Pin;

}DC_Motor_Config_t;

void DCMotor_voidInit(const DC_Motor_Config_t* CopY_Motor);
void DCMotor_voidRotate_CW(const DC_Motor_Config_t* CopY_Motor);
void DCMotor_voidRotate_CCW(const DC_Motor_Config_t* CopY_Motor);


#endif