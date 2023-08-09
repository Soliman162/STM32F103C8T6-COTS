#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "PUMP_interface.h"

void PUMP_voidInit(const PUMP_Config_t * Copy_pumpPin )
{
    GPIO_enumSETPinMODE(&(Copy_pumpPin->Pump_pin));
}
void PUMP_voidOpen(const PUMP_Config_t * Copy_pumpPin)
{
    GPIO_enumSETPinValue(&(Copy_pumpPin->Pump_pin),GPIO_HIGH);
}
void PUMP_voidClose(const PUMP_Config_t * Copy_pumpPin)
{
    GPIO_enumSETPinValue(&(Copy_pumpPin->Pump_pin),GPIO_LOW);
}