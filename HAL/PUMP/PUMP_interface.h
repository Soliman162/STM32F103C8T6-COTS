#ifndef PUMP_INTERFACE_H
#define PUMP_INTERFACE_H

typedef struct 
{
    GPIO_CONFIG_t Pump_pin;
    
}PUMP_Config_t;


void PUMP_voidInit(const PUMP_Config_t * Copy_pumpPin );
void PUMP_voidOpen(const PUMP_Config_t * Copy_pumpPin);
void PUMP_voidClose(const PUMP_Config_t * Copy_pumpPin);


#endif