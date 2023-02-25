#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"

#include "GPIO_interface.h"
#include "SysTick_interface.h"

#include "stepper_interface.h"
#include "stepper_private.h"
#include "stepper_config.h"

void Stepper_voidInit(void)
{
    u16 Port_value = 0;

    for(u8 i=COIL_START_PIN;i<=COIL_END_PIN;i++)
    {
        GPIO_CONFIG_t Coils_pin_Mode = {STEPPER_MOTOR_PORT, i, COILS_PIN_MODE};
        GPIO_enumSETPinMODE( &Coils_pin_Mode  );
    }

    GPIO_enumGETPort_OUTPUT_Value(STEPPER_MOTOR_PORT, &Port_value);
    GPIO_enumSETPORTValue( STEPPER_MOTOR_PORT  , (u16)( Port_value & ~(0b1111<<COIL_START_PIN) ) );
    STK_voidInit();
}
void stepper_voidRotate_CW(u8 Copy_StepMode, u16 degree )
{
    u16 Port_Value =  0;
    u16 degree_u16counter = 0;

    GPIO_enumGETPort_OUTPUT_Value(STEPPER_MOTOR_PORT, &Port_Value);
    while(degree_u16counter<degree)
    {
        for( u8 i=0;i<Copy_StepMode;i--)
        {
            GPIO_enumSETPORTValue( STEPPER_MOTOR_PORT  , (u16)( Port_Value | (Stepper_movment_Mode[Copy_StepMode-4][i]<<COIL_START_PIN) ) );
            STK_voidSetBusyWait(MAX_DELAY*1000);
            GPIO_enumSETPORTValue( STEPPER_MOTOR_PORT  , (u16)( Port_Value & ~(0b1111<<COIL_START_PIN) ) );
            degree_u16counter +=DEGREE_PER_STEP;
        }
    }
}
void stepper_voidRotate_CCW(u8 Copy_StepMode, u16 degree )
{
    u16 Port_Value =  0;
    u16 degree_u16counter = 0;

    GPIO_enumGETPort_OUTPUT_Value(STEPPER_MOTOR_PORT, &Port_Value);
    while(degree_u16counter<degree)
    {
        for( u8 i=Copy_StepMode;i>=0;i-- )
        {
            GPIO_enumSETPORTValue( STEPPER_MOTOR_PORT  , (u16)( Port_Value | (Stepper_movment_Mode[Copy_StepMode-4][i]<<COIL_START_PIN) ) );
            STK_voidSetBusyWait(MAX_DELAY*1000);
            GPIO_enumSETPORTValue( STEPPER_MOTOR_PORT  , (u16)( Port_Value & ~(0b1111<<COIL_START_PIN) ) );
            degree_u16counter +=DEGREE_PER_STEP;
        }
    }

}

void stepper_voidStop(void)
{
    u16 Port_Value =  0;

    GPIO_enumGETPort_OUTPUT_Value(STEPPER_MOTOR_PORT, &Port_Value);
    GPIO_enumSETPORTValue( STEPPER_MOTOR_PORT  , (u16)( Port_Value & ~(0b1111<<COIL_START_PIN) ) );
}