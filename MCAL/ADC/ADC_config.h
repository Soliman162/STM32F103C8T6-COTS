#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/**
 * @brief 
 * options:-
 *  SINGLE_CONVERSION    
 *  CONTINUOUS_CONVERSION
 *  SCAN                 
 *  DISCONTINUOUS        
 * 
 */
#define ADC_MODE    SINGLE_CONVERSION

/**
 * @brief 
 * options:-
 *  REGULAR
 *  INJECTED
 * 
 */

#define GROUP_SELECTION    INJECTED 
/**
 * @brief 
 * 
 * 
 */
#define NUM_OF_CONVERSION   2

u8 CONVERSIONS[NUM_OF_CONVERSION][2] = {

                        {CHANNEL0,SEQUENCE2},
                        {CHANNEL10,SEQUENCE1},

}; 

#define STEPSIZE    5

#endif