/*******************************************************************************/
/******************* Name : Ahmed Elsayed **************************************/
/******************* Date : 6/8/2021      **************************************/
/******************* Version : 1.0v       **************************************/ 
/******************* SWC : STD_TYPES.h *****************************************/ 
/*******************************************************************************/
#ifndef STD_H
#define STD_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;
typedef float f32;
typedef double f64;

typedef enum{

    GPIOA_PORT=0,
    GPIOB_PORT=1,
    GPIOC_PORT=2,
	GPIOD_PORT,
	GPIOE_PORT,

}PORT;

typedef enum{

    PIN_0=0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15

}PIN;

typedef enum{
	
	STD_TYPES_NOK=0,
	STD_TYPES_OK
	
}ERROR_enumSTATE;

#define NULL 	((void *)0)


#endif