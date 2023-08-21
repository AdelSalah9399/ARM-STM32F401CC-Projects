/*
 * RCC_APP.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Adel
 */

#include "RCC_Driver.h"
#include "../MCAL/GPIO/GPIO_Driver.h"

#define HSIRDY   1


#define PLLM_MASK   0xFFFFFFC0
#define PLLN_MASK   0xFFFF803F
#define PLLP_MASK   0xFFFCFFFF

/*********************************************************************************************************/
#define RCC_BaseAddresss     0x40023800
/********************************Registers**************************************/
typedef struct{
	 u32 CR;
	 u32 PLLCFGR;
	 u32 CFGR;
	 u32 CIR;
	 u32 AHB1RSTR;
	 u32 AHB2RSTR;
	 u32 Reserved_1;
	 u32 Reserved_2;
	 u32 APB1RSTR;
	 u32 APB2RSTR;
	 u32 Reserved_3;
	 u32 Reserved_4;
	 u32 AHB1ENR;
	 u32 AHB2ENR;
	 u32 Reserved_5;
	 u32 Reserved_6;
	 u32 APB1ENR;
	 u32 APB2ENR;
	 u32 Reserved_7;
	 u32 Reserved_8;
	 u32 AHB1LPENR;
	 u32 AHB2LPENR;
	 u32 Reserved_9;
	 u32 Reserved_10;
	 u32 APB1LPENR;
	 u32 APB2LPENR;
	 u32 Reserved_11;
	 u32 Reserved_12;
	 u32 BDCR;
	 u32 CSR;
	 u32 Reserved_13;
	 u32 Reserved_14;
	 u32 SSCGR;
	 u32 PLLI2SCFGR;
	 u32 Reserved_15;
	 u32 DCKCFGR;
}RCC_t;

 static volatile RCC_t * const RCC_ptr = (volatile RCC_t * const) RCC_BaseAddresss ;
/*********************************************************************************************************/




/********************************FUNC**************************************/



/*func implementatio*/

ret_t MRCC_EnableCLK(u32 clk)
{

	if((clk==clk_HSI)||(clk==clk_HSE)||(clk==clk_PLL))
	{
		RCC_ptr->CR |=clk;
//		switch(clk)
//		{
//		case clk_HSI: RCC_ptr->CR |= (1<<0);
//		case clk_HSE: RCC_ptr->CR |= (1<<16);
//		case clk_PLL: RCC_ptr->CR |= (1<<24);
//		}
		switch(clk)
		{
		case clk_HSI: while( (RCC_ptr->CR >> HSIRDY) & 1 == 0);break;
		case clk_HSE: while( (RCC_ptr->CR >> 17) & 1 == 0);break;
		case clk_PLL: while( (RCC_ptr->CR >> 25) & 1 == 0);break;
		}

	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}

ret_t MRCC_DisableCLK(u32 clk)
{

	if((clk==clk_HSI)||(clk==clk_HSE)||(clk==clk_PLL))
	{
		RCC_ptr->CR &=~clk;
//		switch(clk)
//		{
//		case clk_HSI: RCC_ptr->CR &= ~(1<<0);
//		case clk_HSE: RCC_ptr->CR &= ~(1<<16);
//		case clk_PLL: RCC_ptr->CR &= ~(1<<24);
//		}
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}

ret_t MRCC_SelectCLK(u32 clk)
{
	switch(clk)
	{
	case clk_HSI:RCC_ptr->CFGR &= ~(1<<0);RCC_ptr->CFGR &= ~(1<<1);   break;
	case clk_HSE:RCC_ptr->CFGR |= (1<<0); RCC_ptr->CFGR &= ~(1<<1);   break;
	case clk_PLL:RCC_ptr->CFGR |= (1<<0); RCC_ptr->CFGR |= (1<<1);   break;
	default     :return ret_Error;   break;
	}
	return ret_OK;
}

ret_t MRCC_EnablePeripheralCLK(u32 peri,u32 peri_bus)
{

	switch(peri_bus)
	{
	case peri_busAHB1:RCC_ptr->AHB1ENR |= (1<<peri);break;
	case peri_busAHB2:RCC_ptr->AHB2ENR |= peri; break;
	case peri_busAPB1:RCC_ptr->APB1ENR |= peri; break;
	case peri_busAPB2:RCC_ptr->APB2ENR |= peri; break;
	default: return ret_Error;
	}
	return ret_OK;
}

ret_t MRCC_DisablePeripheralCLK(u32 peri,u32 peri_bus)
{
	switch(peri_bus)
	{
	case peri_busAHB1:RCC_ptr->AHB1ENR &= ~(1<<peri);break;
	case peri_busAHB2:RCC_ptr->AHB2ENR &= ~peri; break;
	case peri_busAPB1:RCC_ptr->APB1ENR &= ~peri; break;
	case peri_busAPB2:RCC_ptr->APB2ENR &= ~peri; break;
	default: return ret_Error;
	}
	return ret_OK;
}

ret_t MRCC_PLL_CFG_CLK(u32 PLLSRC,u32 PLLM,u32 PLLN,u32 PLLP)
{
	switch(PLLSRC)
	{
	case clk_HSI: RCC_ptr->PLLCFGR &= ~(1<<22); break;
	case clk_HSE: RCC_ptr->PLLCFGR |= (1<<22); break;
	default : return ret_Error; break;
	}
	if((PLLM>=2) && (PLLM<=63))
	{
		RCC_ptr->PLLCFGR &= PLLM_MASK;
		RCC_ptr->PLLCFGR |= PLLM;
	}
	else
	{
		return ret_Error;
	}
	if((PLLN>=192) && (PLLN<=432))
	{
		RCC_ptr->PLLCFGR &= PLLN_MASK;
		RCC_ptr->PLLCFGR |= PLLN;
	}
	else
	{
		return ret_Error;
	}
	if( ((PLLP%2)==0) && (PLLP>0) && (PLLP<=8))
	{
		RCC_ptr->PLLCFGR &= PLLP_MASK;
		RCC_ptr->PLLCFGR |= PLLP;
	}
	else
	{
		return ret_Error;
	}
	return ret_OK;
}



