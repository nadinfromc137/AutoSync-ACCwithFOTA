/*
 * File:	   SPI_Interface.h
 * Author:     Nadin Magdy
 * Created on: Sep 20, 2023
 * Version:    1.0.0 
 *      
 */

/*Preprocessor file guard*/
#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

/*****************************************************************************************************
									 SPI Prototypes
 ****************************************************************************************************/

/**
 * @brief Initializes SPI so it is ready to send and receive as a master
 */
void	MSPI1_voidInit(void);

/**
 * @brief Transmit data or receive
 * @param Copy_u8data
 * @return
 */
u8 MSPI_voidMasterTransmitReceive(u8 cpy_data);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
