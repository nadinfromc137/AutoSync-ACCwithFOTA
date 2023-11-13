/*
 * UART_private.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Compu Tech
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#define UART1_BASE_ADDRESS 0x40011000
#define UART2_BASE_ADDRESS 0x40004400
#define UART3_BASE_ADDRESS 0x40011400

typedef struct
{
	u32 USART_SR;
	u32 USART_DR;
	u32 USART_BRR;
	u32 USART_CR1;
	u32 USART_CR2;
	u32 USART_CR3;
	u32 USART_GTPR;

}UART_R;

#define UART1_REG ((volatile UART_R*)(UART1_BASE_ADDRESS))
#define UART2_REG ((volatile UART_R*)(UART2_BASE_ADDRESS))
#define UART3_REG ((volatile UART_R*)(UART3_BASE_ADDRESS))

#endif /* UART_PRIVATE_H_ */
