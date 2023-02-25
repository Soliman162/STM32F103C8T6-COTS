#ifndef STEPPER_PRIVATE_H
#define STEPPER_PRIVATE_H

u8 Stepper_motor_Half_Step[8] = {
                                    0b1001, //step 1
                                    0b1000, //step 2
                                    0b1100, //step 3
                                    0b0100, //step 4
                                    0b0110, //step 5
                                    0b0010, //step 6
                                    0b0011, //step 7
                                    0b0001  //step 8 
}; 

u8 Stepper_motor_Full_Step[4] = {
                                    0b1001, //step 1
                                    0b1100, //step 2
                                    0b0110, //step 3
                                    0b0011  //step 4
};

u8 *Stepper_movment_Mode[2] = {Stepper_motor_Full_Step,Stepper_motor_Half_Step};



#endif