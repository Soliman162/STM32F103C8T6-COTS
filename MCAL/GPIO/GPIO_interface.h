#ifndef INTERFACE_H
#define INTERFACE_H

/*Pin_Value*/
#define GPIO_LOW    0
#define GPIO_HIGH   1

/*MAX_SPEED_10MHZ*/
#define     GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ                  0b0001
#define     GENERAL_PURPOSE_OUTPUT_OPEN_DRAIN_10MHZ                 0b0101
#define     ALTERNATE_FUNCTION_PUSH_PULL_OUTPUT_10MHZ               0b1001
#define     ALTERNATE_FUNCTION_OPEN_DRAIN_OUTPUT_10MHZ              0b1101

/*MAX_SPEED_2MHZ*/
#define     GENERAL_PURPOSE_OUTPUT_PUSH_PULL_2MHZ                   0b0010
#define     GENERAL_PURPOSE_OUTPUT_OPEN_DRAIN_2MHZ                  0b0110
#define     ALTERNATE_FUNCTION_PUSH_PULL_OUTPUT_2MHZ                0b1010
#define     ALTERNATE_FUNCTION_OPEN_DRAIN_OUTPUT_2MHZ               0b1110

/*MAX_SPEED_50MHZ*/
#define     GENERAL_PURPOSE_OUTPUT_PUSH_PULL_50MHZ                  0b0011
#define     GENERAL_PURPOSE_OUTPUT_OPEN_DRAIN_50MHZ                 0b0111
#define     ALTERNATE_FUNCTION_PUSH_PULL_OUTPUT_50MHZ               0b1011
#define     ALTERNATE_FUNCTION_OPEN_DRAIN_OUTPUT_50MHZ              0b1111

/*INPUT*/
#define     INPUT_ANALOG                                            0b0000
#define     INPUT_FLOATING                                          0b0100
#define     INPUT_PULL_DOWN                                         0b1000
#define     INPUT_PULL_UP                                           0b11000

typedef struct{

    PORT PORT_ID;
    PIN  PIN_NUM;
    u8   PIN_MODE;

}GPIO_CONFIG_t;


ERROR_enumSTATE GPIO_enumSETPinMODE( const GPIO_CONFIG_t * Copy_ptru8PIN );
ERROR_enumSTATE GPIO_enumSETPinValue( const  GPIO_CONFIG_t * Copy_ptu8PIN  , u8 Pin_u8Value );
ERROR_enumSTATE GPIO_enumGETPinValue( const  GPIO_CONFIG_t * Copy_ptu8PIN  , u8 *Pin_ptru8Value );

#endif
