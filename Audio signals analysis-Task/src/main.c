
#include "../MCAL/RCC/RCC_Driver.h"
#include "../MCAL/GPIO/GPIO_Driver.h"
#include "../MCAL/STK/STK_Driver.h"

#include "../SONG/PABLO.h"

#define GPIOA_BASEADDRESS	0x40020000
typedef struct{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDER;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIO_t;
#define  	   	GPIOA      ((volatile GPIO_t*)GPIOA_BASEADDRESS)

volatile u32 i=0;

void SongFun(void)
{
	GPIOA->ODR=PABLO_raw[i];
	i++;
	if(i==28050)
	{
		i=0;
	}
}

int main()
{
	MRCC_EnablePeripheralCLK(peri_AHB1_GPIOA,peri_busAHB1);

	MGPIO_SetPinMode(GPIO_PORTA,PIN0,Mode_OUTPUT);
	MGPIO_SetPinMode(GPIO_PORTA,PIN1,Mode_OUTPUT);
	MGPIO_SetPinMode(GPIO_PORTA,PIN2,Mode_OUTPUT);
	MGPIO_SetPinMode(GPIO_PORTA,PIN3,Mode_OUTPUT);
	MGPIO_SetPinMode(GPIO_PORTA,PIN4,Mode_OUTPUT);
	MGPIO_SetPinMode(GPIO_PORTA,PIN5,Mode_OUTPUT);
	MGPIO_SetPinMode(GPIO_PORTA,PIN6,Mode_OUTPUT);
	MGPIO_SetPinMode(GPIO_PORTA,PIN7,Mode_OUTPUT);

	STK_PeriodUS(125);
	STK_CallBack(&SongFun);
	STK_StartInit();

	return 0;
}

