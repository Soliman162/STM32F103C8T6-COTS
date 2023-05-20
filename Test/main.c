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
#include "main.h"

#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "SysTick_interface.h"
#include "GPIO_interface.h"
#include "WDG_interface.h"
#include "GPT_interface.h"

#include "DC_interface.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  GPIO_CONFIG_t LED_1 = {GPIOA_PORT, PIN_0, GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ};
  GPIO_CONFIG_t LED_2 = {GPIOA_PORT, PIN_1, GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ};

  /*  GPIO_CONFIG_t Motor_pin[2] = {
                                (GPIO_CONFIG_t){GPIOA_PORT,PIN_2,GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ},
                                (GPIO_CONFIG_t){GPIOA_PORT,PIN_3,GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ}
                              }; 

  DC_Motor_Config_t  Motor ;

  Motor.Motor_Data[0] = Motor_pin[0];
  Motor.Motor_Data[1] = Motor_pin[1];
    */
/* 
  DC_Motor_Config_t  Motor = {
                                (GPIO_CONFIG_t){GPIOA_PORT,PIN_2,GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ},
                                (GPIO_CONFIG_t){GPIOA_PORT,PIN_3,GENERAL_PURPOSE_OUTPUT_PUSH_PULL_10MHZ}
                              }; */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */
  
  GPIO_enumSETPinMODE( &LED_1 );
  GPIO_enumSETPinMODE( &LED_2 );

  GPIO_enumSETPinValue( &LED_1  ,GPIO_LOW );
  GPIO_enumSETPinValue( &LED_2  ,GPIO_LOW );
  /* USER CODE END 2 */
  //Timer_voidInit(Test);
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    GPIO_enumSETPinValue( &LED_1  ,GPIO_HIGH );
    GPIO_enumSETPinValue( &LED_2  ,GPIO_HIGH );
    //_delay_us(1000000);
    /* USER CODE BEGIN 3 */
    GPIO_enumSETPinValue( &LED_1  ,GPIO_LOW );
    GPIO_enumSETPinValue( &LED_2  ,GPIO_LOW );
    //_delay_us(1000000);

  }
  /* USER CODE END 3 */

  return 0;
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  /*init clk with my config*/
  RCC_voidCLKInit();
  //Timer_voidInit(GLOB_Timer_4);
  
  RCC_enumPeripheralCLKEnable(APB2_BUS, IOPA_CLK);
  RCC_enumPeripheralCLKEnable(APB2_BUS, IOPC_CLK);
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
