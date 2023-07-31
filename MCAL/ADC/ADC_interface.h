#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


typedef enum
{
    CHANNEL0=0,
    CHANNEL1,
    CHANNEL2,
    CHANNEL3,
    CHANNEL4,
    CHANNEL5,
    CHANNEL6,
    CHANNEL7,
    CHANNEL8,
    CHANNEL9,
    CHANNEL10,
    CHANNEL11,
    CHANNEL12,
    CHANNEL13,
    CHANNEL14,
    CHANNEL15

}ADC_Channel;

typedef enum
{
    SEQUENCE1=0,
    SEQUENCE2,
    SEQUENCE3,
    SEQUENCE4,
    SEQUENCE5,
    SEQUENCE6,
    SEQUENCE7,
    SEQUENCE8,
    SEQUENCE9,
    SEQUENCE10,
    SEQUENCE11,
    SEQUENCE12,
    SEQUENCE13,
    SEQUENCE14,
    SEQUENCE15,
    SEQUENCE16

}ADC_Sequence;

void ADC_voidInit(void);
f32 ADC_f32GET_Conversion(void);

void ADC_voidEnable_INT(void);


#endif
