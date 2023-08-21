/*
 * GPIO_Driver.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Adel
 */

#ifndef GPIO_GPIO_DRIVER_H_
#define GPIO_GPIO_DRIVER_H_

#include "../../Common/STD_TYPE.h"
#include "../Common/Util.h"


/*PORT OPTIONS*/
#define GPIO_PORTA		0
#define GPIO_PORTB		1
#define GPIO_PORTC		2


/************************************************GPIOx_PINS************************************************************************/
#define 		PIN0 					 0
#define 		PIN1 					 1
#define 		PIN2 					 2
#define 		PIN3 					 3
#define 		PIN4 					 4
#define 		PIN5 					 5
#define 		PIN6 					 6
#define 		PIN7 					 7
#define 		PIN8 					 8
#define 		PIN9 					 9
#define 		PIN10 					 10
#define 		PIN11 					 11
#define 		PIN12 					 12
#define 		PIN13 					 13
#define 		PIN14 					 14
#define 		PIN15 					 15
/*MODE OPTIONS*/
#define Mode_INPUT               0
#define Mode_OUTPUT              1
#define Mode_AF               	 2
#define Mode_ANALOG              3

/*Type Options*/
#define push_pull    0
#define open_drain   1

/*Speed Options*/
#define LOW_SPEED		0
#define MEDIUM_SPEED	1
#define HIGH_SPEED		2
#define VERYHIGH_SPEED	3

/*PUPDR*/
#define PUPDR_NOPUPD 	 0
#define PUPDR_PULL_UP	 1
#define PUPDR_PULL_DOUWN 2

/*PIN VALUES*/
#define VALUE_LOW     0
#define VALUE_HIGH    1

ret_t MGPIO_SetPinMode(u32 GPIO_PORT,u32 PIN,u32 Mode);

ret_t MGPIO_SetPinType(u32 GPIO_PORT,u32 PIN,u32 Type);

ret_t MGPIO_SetPinValue(u32 GPIO_PORT,u32 PIN,u32 VALUE);

ret_t MGPIO_SetPinSpeed(u32 GPIO_PORT,u32 PIN,u32 Speed);

ret_t MGPIO_SetPinPUPDR(u32 GPIO_PORT,u32 PIN,u32 PUPDR);

ret_t MGPIO_SetPinAtomicValue(u32 GPIO_PORT,u32 PIN,u32 VALUE);


#endif /* GPIO_GPIO_DRIVER_H_ */
