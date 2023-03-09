#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H

/*ENABLE_CLK_BUSS*/
#define AHB_BUS            0
#define APB2_BUS           1
#define APB1_BUS           2

/*AHB_Peripherals*/
#define DMA1_CLK    0
#define DMA2_CLK    1
#define SRAM_CLK    2
#define FLITF_CLK   4
#define CRC_CLK     6
#define FSMC_CLK    8
#define SDIO_CLK    10

/*APB2_Peripherals*/
#define AFIO_CLK    0
#define IOPA_CLK    2
#define IOPB_CLK    3
#define IOPC_CLK    4
#define IOPD_CLK    5
#define IOPE_CLK    6
#define IOPF_CLK    7
#define IOPG_CLK    8
#define ADC1_CLK    9
#define ADC2_CLK    10
#define TIM1_CLK    11
#define SPI1_CLK    12
#define TIM8_CLK    13
#define USART1_CLK  14
#define ADC3_CLK    15
#define TIM9_CLK    19
#define TIM10_CLK   20  
#define TIM11_CLK   21

/*APB1_Peripherals*/
#define TIM2_CLK    0
#define TIM3_CLK    1
#define TIM4_CLK    2
#define TIM5_CLK    3
#define TIM6_CLK    4
#define TIM7_CLK    5
#define TIM12_CLK   6
#define TIM13_CLK   7
#define TIM14_CLK   8
#define WWDG_CLK    11
#define SPI2_CLK    14
#define SPI3_CLK    15
#define USART2_CLK  17  
#define USART3_CLK  18
#define UART4_CLK   19 
#define UART5_CLK   20 
#define I2C1_CLK    21
#define I2C2_CLK    22
#define USB_CLK     23
#define CAN_CLK     25
#define BKP_CLK     27
#define PWR_CLK     28
#define DAC_CLK     29

void RCC_voidCLKInit(void);
ERROR_enumSTATE   RCC_enumPeripheralCLKEnable( u8 Copy_u8BUS ,u8 Copy_u8Peripheral);
ERROR_enumSTATE   RCC_enumPeripheralCLKDisable( u8 Copy_u8BUS ,u8 Copy_u8Peripheral);

#endif
