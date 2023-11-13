/*
 * UART_interface.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Compu Tech
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UARTvoidInit();
void UARTvoidTransmit(  u8 copy_data);
u8 UARTu8Receive();
void UART_SendString(char* copy_data);
u8 UART_u8ReadDataSynch(u8 *Copy_u8Data);
u8 MUSART_u8ReceiveByteAsynch_( u8* ptr );
void MUSART_EnableInterrupt();
u8 MUART_u8ReceiveByteSynchNonBlocking(void);
void UART_voidCallBack(void(*Fptr)(void));

#endif /* UART_INTERFACE_H_ */
