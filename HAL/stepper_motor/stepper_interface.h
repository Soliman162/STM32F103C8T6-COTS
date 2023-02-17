#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

#define FULL_STEP   4
#define HALF_STEP   8

void Stepper_voidInit(void);
void stepper_Rotate_CW(u8 Copy_StepMode, u16 degree );
void stepper_Rotate_CCW(u8 Copy_StepMode, u16 degree );


#endif