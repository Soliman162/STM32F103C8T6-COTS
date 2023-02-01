#include "STD_TYPES.h"

#include "GPIO_interface.h"

#include "DC_interface.h"
#include "DC_private.h"
#include "DC_config.h"

void DCMotor_voidInit(const DC_Motor_Config_t* CopY_Motor)
{
    GPIO_enumSETPinMODE( &CopY_Motor->Motor_Data[CW_INDEX] );
    GPIO_enumSETPinMODE( &CopY_Motor->Motor_Data[CCW_INDEX] );
}
void DCMotor_voidRotate_CW(const DC_Motor_Config_t* CopY_Motor)
{
    GPIO_enumSETPinValue( &CopY_Motor->Motor_Data[CCW_INDEX]  , GPIO_LOW );
    GPIO_enumSETPinValue( &CopY_Motor->Motor_Data[CW_INDEX]  , GPIO_HIGH );
}
void DCMotor_voidRotate_CCW(const DC_Motor_Config_t* CopY_Motor)
{
    GPIO_enumSETPinValue( &CopY_Motor->Motor_Data[CW_INDEX]  , GPIO_LOW );
    GPIO_enumSETPinValue( &CopY_Motor->Motor_Data[CCW_INDEX]  , GPIO_HIGH );
}
void DCMotor_voidStop(const DC_Motor_Config_t *CopY_Motor)
{
    GPIO_enumSETPinValue( &CopY_Motor->Motor_Data[CW_INDEX]  , GPIO_LOW );
    GPIO_enumSETPinValue( &CopY_Motor->Motor_Data[CCW_INDEX]  , GPIO_LOW );
}
