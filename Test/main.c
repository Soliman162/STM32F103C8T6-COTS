/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "STD_TYPES.h"
#include "STM32F103C8.h"

#include "FreeRTOSConfig.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"

#include "stepper_interface.h"
#include "DC_interface.h"
#include "IR_inferared_interface.h"
#include "CLCD_interface.h"


void SystemClock_Config(void);

#define LINE1_MOTOR_MOTOR_PORT  GPIOA_PORT
#define LINE2_MOTOR_MOTOR_PORT  GPIOA_PORT

#define LINE1_MOTOR_CW_PIN   PIN_0
#define LINE1_MOTOR_CCW_PIN  PIN_1

#define LINE2_MOTOR_CW_PIN   PIN_2
#define LINE2_MOTOR_CCW_PIN  PIN_3

xTaskHandle test_handel = NULL;

void vtestTask(void *pvParameters)
{
  GPIO_CONFIG_t LED = {GPIOA_PORT,PIN_0,GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ};
  GPIO_enumSETPinMODE(&LED);
  for(;;)
  {
    GPIO_enumSETPinValue(&LED,GPIO_HIGH);
    vTaskDelay(500);
    GPIO_enumSETPinValue(&LED,GPIO_LOW);
    vTaskDelay(500);
  }
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  SystemClock_Config();
  UART_voidInit();
  UART_enumTransimite_String((u8 *)"Start app\n");
  UART_enumTransimite_String((u8 *)"Start app\n");
  UART_enumTransimite_String((u8 *)"Start app\n");
  xTaskCreate( vtestTask,
               "test",
               configMINIMAL_STACK_SIZE,
               ( void * ) NULL,
               2,  /* In effect ( tskIDLE_PRIORITY | portPRIVILEGE_BIT ), but tskIDLE_PRIORITY is zero. */
               &test_handel );

  vTaskStartScheduler();
  for(;;)

  return 0;
}

void vApplicationTickHook(void)
{
  
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  //RCC_enumPeripheralCLKEnable(APB2_BUS, IOPA_CLK);

      /*init clk with my config*/
   RCC_voidCLKInit();
  
  RCC_enumPeripheralCLKEnable(APB2_BUS, IOPA_CLK);
  RCC_enumPeripheralCLKEnable(APB2_BUS, IOPC_CLK);
  RCC_enumPeripheralCLKEnable(APB2_BUS, IOPB_CLK); 

  RCC_enumPeripheralCLKEnable(APB2_BUS,USART1_CLK);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
