#ifndef STEPPER_INTERFACE_H
#define STEPPER_INTERFACE_H

#define FULL_STEP   4
#define HALF_STEP   8

void Stepper_voidInit(void);
void stepper_voidRotate_CW(u8 Copy_StepMode, u16 degree );
void stepper_voidRotate_CCW(u8 Copy_StepMode, u16 degree );
void stepper_voidStop(void);


#endif