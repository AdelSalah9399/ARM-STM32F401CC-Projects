/*
 * RCC_Driver.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Adel
 */

#ifndef RCC_DRIVER_H_
#define RCC_DRIVER_H_

#include "../../Common/STD_TYPE.h"
#include "../../Common/Util.h"

/*clk options*/
#define clk_HSI		BIT0_MASK
#define clk_HSE		BIT16_MASK
#define clk_PLL		BIT24_MASK


/************************************************Peripheral Buses*******************************************************************/
#define        peri_busAHB1 								0
#define        peri_busAHB2 								1
#define        peri_busAPB1 								2
#define        peri_busAPB2 								3
/************************************************AHB1-Bus Peripherals***************************************************************/
#define        peri_AHB1_GPIOA 							    0
#define        peri_AHB1_GPIOB 							    1
#define        peri_AHB1_GPIOC 							    2
#define        peri_AHB1_GPIOD 							    BIT3_MASK
#define        peri_AHB1_GPIOE 							    BIT4_MASK
#define        peri_AHB1_GPIOH 							    BIT7_MASK
#define        peri_AHB1_CRC   							    BIT12_MASK
#define        peri_AHB1_DMA1  							    BIT21_MASK
#define        peri_AHB1_DMA2  							    BIT22_MASK

/************************************************AHB2-Bus Peripherals***************************************************************/
#define        peri_AHB2_OTGFS   							BIT7_MASK
/************************************************APB1-Bus Peripherals***************************************************************/
#define        peri_APB1_TIM2    							BIT0_MASK
#define        peri_APB1_TIM3       						BIT1_MASK
#define        peri_APB1_TIM4       						BIT2_MASK
#define        peri_APB1_TIM5       						BIT3_MASK
#define        peri_APB1_WWDG       					 	BIT11_MASK
#define        peri_APB1_SPI2       					 	BIT14_MASK
#define        peri_APB1_SPI3       					 	BIT15_MASK
#define        peri_APB1_USART2     					 	BIT17_MASK
#define        peri_APB1_I2C1       					 	BIT21_MASK
#define        peri_APB1_I2C2       					 	BIT22_MASK
#define        peri_APB1_I2C3       					 	BIT23_MASK
#define        peri_APB1_PWR        					 	BIT28_MASK
/************************************************APB2-Bus Peripherals***************************************************************/
#define        peri_APB2_TIM1    							BIT0_MASK
#define        peri_APB2_USART1      						BIT4_MASK
#define        peri_APB2_USART6      						BIT5_MASK
#define        peri_APB2_ADC1        						BIT8_MASK
#define        peri_APB2_SDIO        						BIT11_MASK
#define        peri_APB2_SPI1        						BIT12_MASK
#define        peri_APB2_SPI4        						BIT13_MASK
#define        peri_APB2_SYSCFG      						BIT14_MASK
#define        peri_APB2_TIM9        						BIT16_MASK
#define        peri_APB2_TIM10       						BIT17_MASK
#define        peri_APB2_TIM11       						BIT18_MASK


ret_t MRCC_EnableClk(u32 clk);

ret_t MRCC_DisableCLK(u32 clk);

ret_t MRCC_SelectCLK(u32 clk);

ret_t MRCC_EnablePeripheralCLK(u32 peri,u32 peri_bus);

ret_t MRCC_DisablePeripheralCLK(u32 peri,u32 peri_bus);

ret_t MRCC_PLL_CFG_CLK(u32 PLLSRC,u32 PLLM,u32 PLLN,u32 PLLP);

#endif /* RCC_DRIVER_H_ */
