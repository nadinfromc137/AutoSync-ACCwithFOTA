/*
 * GPIO_private.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Compu Tech
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

/*base addresses for GPIO */

#define GPIO_A_BASE_ADDRESS		0x40020000
#define GPIO_B_BASE_ADDRESS		0x40020400
#define GPIO_C_BASE_ADDRESS 	0x40020800
#define GPIO_D_BASE_ADDRESS		0x40020C00
#define GPIO_E_BASE_ADDRESS		0x40021000
#define GPIO_H_BASE_ADDRESS		0x40021C00

/*struct for GPIO registers*/
typedef struct
{
	volatile u32 MODER;   /* GPIO port mode register  with address offset : 0x00 */

	volatile u32 OTYPER;  /* GPIO port Output type register  with address offset : 0x04 */

	volatile u32 OSPEEDR;   /* GPIO port Output Speed  with address offset : 0x08 */

	volatile u32 PUPDR;  /* GPIO port Pull UP / Pull Down  register  with address offset : 0x0C */

	volatile u32 IDR;   /*  GPIO port Input Data register  with address offset : 0x10 */

	volatile u32 ODR;  /* GPIO port Output Data register   with address offset : 0x14 */

	volatile u32 BSRR;   /* GPIO port  Set / Reset bit register  with address offset : 0x18 */

	volatile u32 LCKR;  /* GPIO port Lock Pin  register  with address offset : 0x1C */

	volatile u32 AFRL;  /* GPIO port Alternate Function Low register  with address offset : 0x20 */

	volatile u32 AFRH;  /* GPIO port Alternate Function High register  with address offset : 0x24 */

}GPIO_X_R;


/*pointers for each GPIO register*/

#define         MGPIOA                 ((volatile GPIO_X_R*)GPIO_A_BASE_ADDRESS)



#define         MGPIOB                 ((volatile GPIO_X_R*)GPIO_B_BASE_ADDRESS)




#define         MGPIOC                 ((volatile GPIO_X_R*)GPIO_C_BASE_ADDRESS)

#define         MGPIOD                 ((volatile GPIO_X_R*)GPIO_D_BASE_ADDRESS)

#define         MGPIOE                 ((volatile GPIO_X_R*)GPIO_E_BASE_ADDRESS)

#define         MGPIOH                 ((volatile GPIO_X_R*)GPIO_H_BASE_ADDRESS)

#define _LUCKED_PIN 16U


#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
