#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

static GPIO_REG_DEF_t * GPIO_PORT[5] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE};

ERROR_enumSTATE GPIO_enumSETPinMODE( const GPIO_CONFIG_t * Copy_ptru8PIN )
{

	ERROR_enumSTATE LOC_u8State = STD_TYPES_NOK;
	u8 LOC_u8CopyMode ;
	u8 LOc_u8CopyPin_num;
	u8 LOC_u8CopyPort_ID;

	if(Copy_ptru8PIN != NULL)
	{
		LOC_u8CopyMode = Copy_ptru8PIN->PIN_MODE;
		LOc_u8CopyPin_num = Copy_ptru8PIN->PIN_NUM;
		LOC_u8CopyPort_ID =Copy_ptru8PIN->PORT_ID;

		if(  LOC_u8CopyPort_ID <= GPIOC_PORT )
		{
			if( LOc_u8CopyPin_num<=PIN_15 )
			{
				LOC_u8State = STD_TYPES_OK;
				if( LOC_u8CopyMode ==  INPUT_PULL_DOWN_OR_UP )
				{
					GPIO_PORT[LOC_u8CopyPort_ID]->BRR = (1<<LOc_u8CopyPin_num);
				}

				if( LOc_u8CopyPin_num<=PIN_7 )
				{
					(GPIO_PORT[LOC_u8CopyPort_ID]->CRL) &=  (~(0b1111<<(LOc_u8CopyPin_num * 4) ) );
					(GPIO_PORT[LOC_u8CopyPort_ID]->CRL) |=  ( LOC_u8CopyMode << ( LOc_u8CopyPin_num * 4 ) );

				}else if( LOc_u8CopyPin_num>=PIN_8 )
				{
					LOc_u8CopyPin_num-=8;
					GPIO_PORT[LOC_u8CopyPort_ID]->CRH &=  (~(0b1111<< (LOc_u8CopyPin_num * 4) ) ) ;
					GPIO_PORT[LOC_u8CopyPort_ID]->CRH |=  ( LOC_u8CopyMode << (  LOc_u8CopyPin_num * 4) );
				}
			}
		}
	}

	return LOC_u8State;
}


ERROR_enumSTATE GPIO_enumSETPinValue( const GPIO_CONFIG_t * Copy_ptru8PIN  , u8 Pin_u8Value )
{
	ERROR_enumSTATE LOC_u8State = STD_TYPES_NOK;

	if( Copy_ptru8PIN !=NULL)
	{
		if( Copy_ptru8PIN->PORT_ID<=GPIOC_PORT )
		{
			if( Copy_ptru8PIN->PIN_NUM<=PIN_15 )
			{
				LOC_u8State = STD_TYPES_NOK;

				if( Pin_u8Value == GPIO_HIGH )
				{
					GPIO_PORT[Copy_ptru8PIN->PORT_ID]->BSRR = (1<<Copy_ptru8PIN->PIN_NUM);

				}else if (Pin_u8Value == GPIO_LOW )
				{
					GPIO_PORT[Copy_ptru8PIN->PORT_ID]->BRR = (1<<Copy_ptru8PIN->PIN_NUM);
				}
			}
		}
	}
	return LOC_u8State;
}


ERROR_enumSTATE GPIO_enumGETPinValue( const GPIO_CONFIG_t * Copy_ptru8PIN  , u8 *Pin_ptru8Value )
{
	ERROR_enumSTATE LOC_u8State = STD_TYPES_OK;

	if( Copy_ptru8PIN !=NULL )
	{
		if( Pin_ptru8Value != NULL)
		{
			if( Copy_ptru8PIN->PORT_ID<=GPIOC_PORT )
			{
				if( Copy_ptru8PIN->PIN_NUM<=PIN_15 )
				{
					*Pin_ptru8Value = GET_BIT( GPIO_PORT[Copy_ptru8PIN->PORT_ID]->IDR , Copy_ptru8PIN->PIN_NUM );

				}else{ LOC_u8State = STD_TYPES_NOK; }

			}else{ LOC_u8State = STD_TYPES_NOK; }
		}
	}

	return LOC_u8State;
}

ERROR_enumSTATE GPIO_enumSETPORTMode( PORT port_indx  , u8 Port_u8Mode )
{
	ERROR_enumSTATE  LOC_u8State = STD_TYPES_NOK;

	if( (port_indx >= GPIOA_PORT) && (port_indx <=GPIOC_PORT) )
	{
		LOC_u8State = STD_TYPES_OK;
		u32 Port_value = 0;
		/*reset register */
		if(Port_u8Mode == INPUT_PULL_DOWN_OR_UP)
		{
			GPIO_PORT[port_indx]->BRR = 0xFFFF;
		}
		/*Calc port value*/
		for( u8 i=0;i<8;i++ )
		{
			Port_value |= Port_u8Mode<<(i*4);
		}
		/*clear port*/	
		GPIO_PORT[port_indx]->CRL = 0;
		GPIO_PORT[port_indx]->CRH = 0;
		/*set port value*/
		GPIO_PORT[port_indx]->CRL = Port_value;
		GPIO_PORT[port_indx]->CRH = Port_value;
	}

	return LOC_u8State;
}

ERROR_enumSTATE GPIO_enumSETPORTMode_HIGH( PORT port_indx  , u8 Port_u8Mode )
{
	ERROR_enumSTATE  LOC_u8State = STD_TYPES_NOK;

	if( (port_indx >= GPIOA_PORT) && (port_indx <=GPIOC_PORT) )
	{
		LOC_u8State = STD_TYPES_OK;
		u32 Port_value = 0;
		/*reset register */
		if(Port_u8Mode == INPUT_PULL_DOWN_OR_UP)
		{
			GPIO_PORT[port_indx]->BRR = 0xFF<<8;
		}
		/*Calc port value*/
		for( u8 i=0;i<8;i++ )
		{
			Port_value |= Port_u8Mode<<(i*4);
		}
		/*clear port*/	
		GPIO_PORT[port_indx]->CRH = 0;
		/*set port value*/
		GPIO_PORT[port_indx]->CRH = Port_value;
	}

	return LOC_u8State;
}

ERROR_enumSTATE GPIO_enumSETPORTMode_LOW( PORT port_indx  , u8 Port_u8Mode )
{
		ERROR_enumSTATE  LOC_u8State = STD_TYPES_NOK;

	if( (port_indx >= GPIOA_PORT) && (port_indx <=GPIOC_PORT) )
	{
		LOC_u8State = STD_TYPES_OK;
		u32 Port_value = 0;
		/*reset register */
		if(Port_u8Mode == INPUT_PULL_DOWN_OR_UP)
		{
			GPIO_PORT[port_indx]->BRR = 0xFF;
		}
		/*Calc port value*/
		for( u8 i=0;i<8;i++ )
		{
			Port_value |= Port_u8Mode<<(i*4);
		}
		/*clear port*/	
		GPIO_PORT[port_indx]->CRL = 0;
		/*set port value*/
		GPIO_PORT[port_indx]->CRL = Port_value;	
	}
	return LOC_u8State;
}

ERROR_enumSTATE GPIO_enumSETPORTValue( PORT port_indx  , u16 Port_u16Value )
{
	ERROR_enumSTATE  LOC_u8State = STD_TYPES_NOK;
	
	if( (port_indx >= GPIOA_PORT) && (port_indx <= GPIOC_PORT) )
	{
		LOC_u8State = STD_TYPES_OK;
		GPIO_PORT[port_indx]->ODR = Port_u16Value;
	}
	return LOC_u8State;
}

ERROR_enumSTATE GPIO_enumSETPORTValue_HIGH( PORT port_indx  , u8 Port_u16Value )
{
	ERROR_enumSTATE  LOC_u8State = STD_TYPES_NOK;
	if( (port_indx >= GPIOA_PORT) && (port_indx <= GPIOC_PORT) )
	{
		LOC_u8State = STD_TYPES_OK;
		GPIO_PORT[port_indx]->ODR = (u16)Port_u16Value<<8;
	}
	return LOC_u8State;
}
ERROR_enumSTATE GPIO_enumSETPORTValue_LOW( PORT port_indx  , u8 Port_u16Value )
{
	ERROR_enumSTATE  LOC_u8State = STD_TYPES_NOK;
	if( (port_indx >= GPIOA_PORT) && (port_indx <= GPIOC_PORT) )
	{
		LOC_u8State = STD_TYPES_OK;
		GPIO_PORT[port_indx]->ODR = Port_u16Value;
	}
	return LOC_u8State;
}

ERROR_enumSTATE GPIO_enumGETPort_INPUT_Value( PORT port_indx , u16 *Port_ptru8Value )
{
	ERROR_enumSTATE LOC_u8State = STD_TYPES_NOK;

	if( port_indx >= GPIOA_PORT && port_indx <= GPIOC_PORT )
	{
		LOC_u8State = STD_TYPES_OK;
		*Port_ptru8Value = GPIO_PORT[port_indx]->IDR ;		
	}
	return LOC_u8State;
}

ERROR_enumSTATE GPIO_enumGETPort_OUTPUT_Value( PORT port_indx , u16 *Port_ptru8Value )
{
	ERROR_enumSTATE LOC_u8State = STD_TYPES_NOK;

	if( port_indx >= GPIOA_PORT && port_indx <= GPIOC_PORT )
	{
		LOC_u8State = STD_TYPES_OK;
		*Port_ptru8Value = GPIO_PORT[port_indx]->ODR ;		
	}
	return LOC_u8State;
}

