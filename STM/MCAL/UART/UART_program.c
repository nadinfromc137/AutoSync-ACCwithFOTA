/*
 * UART_program.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Compu Tech
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "UART_interface.h"
#include "UART_private.h"

static void(*MUSART_CALLPTR)(void)   = NULL ;

/**
 * @brief Initializes UART by configuring its baud rate data length, etc. and enables receiving and transmitting
 * @param None
 * @return void
 */
void UARTvoidInit()
{

	/*set baud rate*/
	UART1_REG->USART_BRR=0x0682; //9600

	/*over8*/
	SET_BIT(UART1_REG->USART_CR1,15);

	/*enable USART*/
	SET_BIT(UART1_REG->USART_CR1,13);

	/*word length 8 bits bata*/

	CLR_BIT(UART1_REG->USART_CR1,12);

	/*set interrupts
  SET_BIT(UART1_REG->USART_CR1,8);
  SET_BIT(UART1_REG->USART_CR1,6);*/

	/*enable transmit*/
	SET_BIT(UART1_REG->USART_CR1,3);
	/*enable receive*/
	SET_BIT(UART1_REG->USART_CR1,2);

	/*set stop bits*/
	CLR_BIT(UART1_REG->USART_CR2,12);
	CLR_BIT(UART1_REG->USART_CR2,13);
	UART1_REG->USART_SR=0;


}

/**
 * @brief Waits till any previous data is being transmitted then starts transmiting new data
 * @returns void
 * @param copy_data The data to transmit
 */
void UARTvoidTransmit( u8 copy_data )
{

	while(GET_BIT(UART1_REG->USART_SR,7)==0);

	UART1_REG->USART_DR=copy_data;
	while(GET_BIT(UART1_REG->USART_SR,6)==0);
	UART1_REG->USART_SR=0;


}

/**
 * @brief Returns received data after this dtaa has been completely trasnmitted
 * @return u8
 * @param None
 */
u8 UARTu8Receive()
{
	u8 val=0;

	while(GET_BIT(UART1_REG->USART_SR,5)==0);
	val=UART1_REG->USART_DR;

	return val;

}

/**
 * @brief Iterated over a string and sends it
 * @param Copy_u8data The string to send, its a character pointer
 * @return void
 */
void UART_SendString(char* copy_data )
{
	for(u8 i=0; copy_data[i] !=0  ;i++)
	{

		UART1_REG->USART_DR=copy_data[i] ;
		while(GET_BIT(UART1_REG->USART_SR,7)==0);
	}
}

/**
 * @brief Non-blocking data receive, returns status 1 if there is data recived and 0 if not
 * @param Copy_u8Data The data to send
 * @return u8
 */
u8 UART_u8ReadDataSynch(u8 *Copy_u8Data)
{

	u8 LOC_u8Status = 1 ;
	if(GET_BIT(UART1_REG->USART_SR,5) == 1)
	{
		*Copy_u8Data = UART1_REG->USART_DR  ;
	}
	else
	{
		LOC_u8Status = 0 ;
	}
	return  LOC_u8Status ;
}

/**
 * @brief Enables the UART interupt
 * @param None
 * @return void
 */
void MUSART_EnableInterrupt( )
{

	SET_BIT(UART1_REG->USART_CR1,5);

}

/**
 * @brief Receives data asychronusly
 * @param Copy_ptr The pointer to data being received
 * @return u8
 */
u8 MUSART_u8ReceiveByteAsynch_( u8* ptr )
{
	u8 Status=1 ;
	if(GET_BIT(UART1_REG->USART_SR,5)==1)
	{
		*ptr= UART1_REG->USART_DR  ;
	}
	else
	{
		Status = 0;
	}
	return Status ;
}

/**
 * @brief Receives data but blocks for a maximum number of time ticks, otherwise returns 255
 * @param None
 * @return u8
 */
u8 MUART_u8ReceiveByteSynchNonBlocking ( )
{
	u8  L_u8Data    = 0;
	u32 L_u8TimeOut = 0;
	while ((GET_BIT(UART1_REG->USART_SR,5)==0) && (L_u8TimeOut < 200000) )
	{
		L_u8TimeOut++;
	}
	if (L_u8TimeOut==200000)
	{
		L_u8Data = 255;
	}
	else
	{
		L_u8Data = UART1_REG->USART_DR;
	}
	return L_u8Data;
}

/**
 * @brief Handles UART callback function
 * @param Fptr
 */
void UART_voidCallBack(void(*Fptr)(void))
{

	MUSART_CALLPTR = Fptr ;
}




void USART1_IRQHandler(void)
{
	MUSART_CALLPTR() ;
}
