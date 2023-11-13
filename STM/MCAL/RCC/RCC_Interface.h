/*
 * File:	   RCC_Interface.h
 * Author:     Nadin Magdy
 * Created on: Sep 10, 2023
 * Version:    1.0.0 
 *      
 */

/*Preprocessor file guard*/
#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

#include	"../../LIB/STD_TYPES.h"
#include	"../../LIB/BIT_MATH.h"

/* Macros of RCC Clocks */
#define		MRCC_HSI_CLK		0U
#define		MRCC_HSE_CLK		1U
#define		MRCC_PLL_CLK		2U

/* Macros of Buses */
#define		AHB1_BUS		0U
#define		AHB2_BUS		1U
#define		APB1_BUS		2U
#define		APB2_BUS		3U

/* Macros of peripherals of RCC_AHB1_ */
#define RCC_AHB1_GPIOA		0
#define RCC_AHB1_GPIOB		1
#define RCC_AHB1_GPIOC		2
#define RCC_AHB1_CRC		12
#define RCC_AHB1_DMA1		21
#define RCC_AHB1_DMA2		22

/* Macros of peripherals of RCC_AHB2 */
#define RCC_AHB2_OTGFS		7

/* Macros of peripherals of RCC_APB1 */
#define RCC_APB1_TIMER2		0
#define RCC_APB1_TIMER3		1
#define RCC_APB1_TIMER4		2
#define RCC_APB1_TIMER5		3
#define RCC_APB1_WWDG		11
#define RCC_APB1_SPI2		14
#define RCC_APB1_SPI3		15
#define RCC_APB1_USART2		17
#define RCC_APB1_I2C1		21
#define RCC_APB1_I2C2		22
#define RCC_APB1_I2C3		23
#define RCC_APB1_PWR			28

/* Macros of peripherals of RCC_APB2 */
#define RCC_APB2_TIMER1		0
#define RCC_APB2_USART1		4
#define RCC_APB2_USART6		5
#define RCC_APB2_ADC1		8
#define RCC_APB2_SDIO		11
#define RCC_APB2_SPI1		12
#define RCC_APB2_SPI4		13
#define RCC_APB2_SYSCFG		14


void	MRCC_voidInit(void);

void	MRCC_voidEnablePeripheral(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralNum);

void	MRCC_voidDisablePeripheral(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralNum);

#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
