#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define SINGLE_CONVERSION           0
#define CONTINUOUS_CONVERSION       1
#define SCAN                        2
#define DISCONTINUOUS               3


#define REGULAR      16
#define INJECTED     4

static inline void SET_voidChannel_sequence(u8 Channel , u8 SEQuence);


#endif