#ifndef STM32F103C8_H
#define STM32F103C8_H

//#include "STD_TYPES.h"

/***************************************RCC_REG**************************/
typedef struct{

	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;

}RCC_REG_Def_t;

#define RCC     ((RCC_REG_Def_t *)0x40021000)

/**************************************************************************/
/***************************************GPIO_REG**************************/

typedef struct {

	volatile u32  CRL;
	volatile u32  CRH;
	volatile u32  IDR;
	volatile u32  ODR;
	volatile u32  BSRR;
	volatile u32  BRR;
	volatile u32  LCKR;

}GPIO_REG_DEF_t; 

#define GPIOA     ((GPIO_REG_DEF_t *)0x40010800)
#define GPIOB     ((GPIO_REG_DEF_t *)0x40010C00)
#define GPIOC     ((GPIO_REG_DEF_t *)0x40011000)
#define GPIOD	  ((GPIO_REG_DEF_t *)0x40011400)
#define GPIOE	  ((GPIO_REG_DEF_t *)0x40011800)
#define GPIOF     ((GPIO_REG_DEF_t *)0x40011C00)
#define GPIOG     ((GPIO_REG_DEF_t *)0x40012000)

/**************************************************************************/

/***************************************NVIC_REG**************************/

typedef struct{

	volatile u32 ISER[8];
	volatile u32 Reserved_0[24];
	volatile u32 ICER[8];
	volatile u32 Reserved_1[24];
	volatile u32 ISPR[8];
	volatile u32 Reserved_2[24];
	volatile u32 ICPR[8];
	volatile u32 Reserved_3[24];
	volatile u32 IABR[8];
	volatile u32 Reserved_4[56];
	volatile u8  IPR[240];

}NVIC_REG_DEF_t;

#define   NVIC      ( (NVIC_REG_DEF_t *)0xE000E100 )


/*************************************************************************/
/***************************************EXTI_REG**************************/

typedef struct{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_Reg_Def_t;

#define   EXTI      ((EXTI_Reg_Def_t *)0x40010400)

/*************************************************************************/
/***************************************AFIO_REG**************************/

typedef struct{

	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;

}AFIO_Reg_Def_t;

#define   AFIO      ((AFIO_Reg_Def_t *)0x40010000)

/*************************************************************************/
/***************************************SysTick_REG**************************/
typedef struct{

	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALB;

}SysTick_REG_DEF_t;


#define STK         ((SysTick_REG_DEF_t *)0xE000E010)


/*************************************************************************/
/***************************************SPI_REG**************************/
typedef struct{

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;

}SPI1_REG_DEF_t;


#define SPI1         ((SPI1_REG_DEF_t *)0x40013000)

/*************************************************************************/
/***************************************DMA_REG**************************/
typedef struct{

	volatile u32 CCR  ;
	volatile u32 CNDTR;
	volatile u32 CPAR ;
	volatile u32 CMAR ;
	volatile u32 Reserved;

}CHANNEL_DEF_T;

typedef struct{

	volatile u32 ISR;
	volatile u32 IFCR;
	CHANNEL_DEF_T CHANNEL[7];

}DMA1_REG_DEF_t;

#define DMA1         ((DMA1_REG_DEF_t *)0x40020000)

/*************************************************************************/
/***************************************UART_REG**************************/

typedef struct{

	volatile u32 SR_UART;
	volatile u32 DR_UART;
	volatile u32 BRR_UART;
	volatile u32 CR1_UART;
	volatile u32 CR2_UART;
	volatile u32 CR3_UART;
	volatile u32 GTPR_UART;

}UART_REG_DEF_t;

#define UART1         ((UART_REG_DEF_t*)0x40013800)
#define UART2         ((UART_REG_DEF_t*)0x40004400)
#define UART3         ((UART_REG_DEF_t*)0x40004800)

/*************************************************************************/

/***************************************WWDG_REG**************************/

typedef struct{

	volatile u32 WWDG_CR;
	volatile u32 WWDG_CFR;
	volatile u32 WWDG_SR;

}WWDG_REG_DEF_t;

#define WWDG		((WWDG_REG_DEF_t *)0x40002C00)

/*************************************************************************/

/***************************************GPT_REG**************************/

typedef struct{

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;

	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;

	volatile u32 CCMR1;
	volatile u32 CCMR2;

	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;

	volatile u32 ARR;
	volatile u32 RESERVED_1;	
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;

	volatile u32 CCR4;
	volatile u32 RESERVED_2;
	volatile u32 DCR;
	volatile u32 DMAR;

}GPT_2_5_REG_DEF_t;

#define GPT_2		((GPT_2_5_REG_DEF_t *)0x40000000)
#define GPT_3		((GPT_2_5_REG_DEF_t *)0x40000400)
#define GPT_4		((GPT_2_5_REG_DEF_t *)0x40000800)
//#define GPT_5		((GPT_2_5_REG_DEF_t *)0x40000C00)

/*************************************************************************/

/***************************************ADC_REG**************************/

typedef struct{

	volatile  u32 SR;

	volatile  u32 CR1;
	volatile  u32 CR2;

	volatile  u32 SMPR1;
	volatile  u32 SMPR2;

	volatile  u32 JOFR1;
	volatile  u32 JOFR2;
	volatile  u32 JOFR3;
	volatile  u32 JOFR4;

	volatile  u32 HTR;
	volatile  u32 LTR;

	volatile  u32 SQRX[3];
	//volatile  u32 SQR2;
	//volatile  u32 SQR3;

	volatile  u32 JSQR;

	volatile  u32 JDR[4];

	volatile  u32 DR;

}ADC_REG_DEF_t;

#define	ADC1	((ADC_REG_DEF_t *)0x40012400)
#define	ADC2	((ADC_REG_DEF_t *)0x40012800)

/*************************************************************************/

#endif
