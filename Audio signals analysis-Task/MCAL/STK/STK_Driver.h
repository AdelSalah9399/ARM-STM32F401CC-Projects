/*
 * STK_Driver.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Adel
 */

#ifndef STK_STK_DRIVER_H_
#define STK_STK_DRIVER_H_

#include "../Common/STD_TYPE.h"
#include "../Common/Util.h"


/*STK_CLK_SRC options*/
#define AHB					1
#define AHB_Div_8			0

/*STK_INT_EN options*/
#define DISABLE			0
#define ENABLE			1

			//Pre_build Configuration
//#########################################
#define STK_CLK_SRC				AHB_Div_8
#define STK_INT_EN				ENABLE
//#########################################

void STK_StartInit(void);

void STK_Stop(void);

void STK_PeriodMS(u32 PeriodMS);

void STK_PeriodUS(u32 PeriodUS);

u32 STK_RemainingTime(void);

u32 STK_ElapsedTime(void);

void STK_CallBack(void (*ptr)(void));




#endif /* STK_STK_DRIVER_H_ */
