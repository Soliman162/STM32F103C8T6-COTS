#ifndef STEPPER_CONFIG_H
#define STEPPER_CONFIG_H

/**
 * @brief 
 * stepper motor connected to which port
 * 
 * GPIOA_PORT
 * GPIOB_PORT
 * GPIOC_PORT
 */
#define STEPPER_MOTOR_PORT  GPIOA_PORT

/**
 * @brief 
 * FROM 0 --> 15
 * 4 pins of the motor
 */
#define COIL_START_PIN      (PIN)0
#define COIL_END_PIN        (PIN)4

/**
 * @brief 
 * coils pin mode 
 */
#define COILS_PIN_MODE  GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ

/**
 * @brief 
 * max delay between 2 step in (ms)
 */
#define MAX_DELAY   10

#endif