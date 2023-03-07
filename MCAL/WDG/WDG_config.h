#ifndef WDG_CONFIG_H
#define WDG_CONFIG_H


//Prescaler WDGTB Min timeout value Max timeout value
/*  113 μs 7.28 ms
    227 μs 14.56 ms
    455 μs 29.12 ms
    910 μs 58.25 ms

           WDGT
                  0 
                  1 
                  2 
                  3 

                  T[5:0] max  63
                  T[5:0] min  0

 */

#define CLK     16000000UL

/**
 * @brief 
 * 
 * Prescaller Value:-
 *      DIVED_BY_1 
 *      DIVED_BY_2 
 *      DIVED_BY_4 
 *      DIVED_BY_8 
 * 
 */
//#define PRESCALLER   DIVED_BY_1

/**
 * @brief 
 * 
 * window watchdog timeout by (ms)
 * 
 */
#define WWDG_TIMEOUT    65.5F





#endif