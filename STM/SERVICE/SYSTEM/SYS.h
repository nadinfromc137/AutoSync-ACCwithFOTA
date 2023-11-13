/*
 * File:	   SYS.h
 * Author:     Nadin Magdy
 * Created on: Oct 29, 2023
 * Version:    1.0.0 
 *
 */

/*Preprocessor file guard*/
#ifndef SYSTEM_SYS_H_
#define SYSTEM_SYS_H_

/*****************************************************************************************************
									 System Interface Prototypes
 ****************************************************************************************************/

/**
 * @brief initializes pins and needed buses
 */
void SYS_Init(void);

void SYS_TimerInit(void);

void SYS_USARTInit(void);

void SYS_MotorInit(void);

void SYS_HandleUARTInput(u8 Copy_u8Data);

void SYS_InitPinAsOutput(u8 Copy_u8PortName , u8 Copy_u8PinNum);

void SYS_SetPinHigh(u8 Copy_u8PortName , u8 Copy_u8PinNum);

void SYS_SetPinLow(u8 Copy_u8PortName , u8 Copy_u8PinNum);


#endif /* SYSTEM_SYS_H_ */
