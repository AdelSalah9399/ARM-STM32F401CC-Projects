/*
 * STK_APP.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Adel
 */


#include "STK_Driver.h"


static void (*Global_Ptr)(void);

#define AHB_8_FACTOR_2MHZ 	2000
#define AHB_FACTOR_16MHZ 	16000


#define BASE_ADDRESS 	0xE000E010


typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_t;

//#define  STK_ptr2 ((volatile STK_t *)BASE_ADDRESS)
static volatile STK_t * const STK_ptr = (volatile STK_t * const) BASE_ADDRESS ;


void STK_StartInit(void)
{
	//if(STK_CLK_SRC == AHB || STK_CLK_SRC == AHB_Div_8 ||STK_INT_EN ==ENABLE || )
	STK_ptr->CTRL = (STK_CLK_SRC<<2 | STK_INT_EN<<1);
	STK_ptr->CTRL |= (1<<0);

}

void STK_Stop(void)
{
	STK_ptr->CTRL &= ~(1<<0);
}

void STK_PeriodMS(u32 PeriodMS)
{
	if(STK_CLK_SRC==AHB_Div_8)
	{
		PeriodMS *= AHB_8_FACTOR_2MHZ;
	}
	else if(STK_CLK_SRC==AHB)
	{
		PeriodMS *= AHB_FACTOR_16MHZ;
	}
	else
	{
		/*do nothing*/
	}
	STK_ptr->LOAD =PeriodMS;
}

void STK_PeriodUS(u32 PeriodUS)
{
	if(STK_CLK_SRC==AHB_Div_8)
	{
		PeriodUS *= 2;
	}
	else if(STK_CLK_SRC==AHB)
	{
		PeriodUS *= 16;
	}
	else
	{
		/*do nothing*/
	}
	STK_ptr->LOAD =PeriodUS;
}


u32 STK_RemainingTime(void)
{
	if(STK_CLK_SRC==AHB_Div_8)
	return ((STK_ptr->VAL)/(AHB_8_FACTOR_2MHZ));
	else if(STK_CLK_SRC==AHB)
	return ((STK_ptr->VAL)/(AHB_FACTOR_16MHZ));

}

u32 STK_ElapsedTime(void)
{
	return ((STK_ptr->LOAD)-(STK_ptr->VAL));
}



void STK_CallBack(void (*Func_Ptr)(void))
{
	if(Func_Ptr!=NULL)
	{
		Global_Ptr=Func_Ptr;
	}
}

void SysTick_Handler(void)
{
	if(Global_Ptr!=NULL)
	Global_Ptr();
}

