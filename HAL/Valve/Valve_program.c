#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "Valve_interface.h"

void VALVE_voidInit(const VALVE_Config_t * Copy_valvePin )
{
    GPIO_enumSETPinMODE(&(Copy_valvePin->Valve_pin));
}
void VALVE_voidON(const VALVE_Config_t * Copy_valvePin)
{
    GPIO_enumSETPinValue(&(Copy_valvePin->Valve_pin),GPIO_HIGH);
}
void VALVE_voidOFF(const VALVE_Config_t * Copy_valvePin)
{
    GPIO_enumSETPinValue(&(Copy_valvePin->Valve_pin),GPIO_LOW);
}