
/*
 * File:	   SPI_Program.c
 * Author:     Nadin Magdy
 * Created on: Sep 20, 2023
 * Version:    1.0.0 
 *      
 */

/*****************************************************************************************************
									 Library Includes
 ****************************************************************************************************/
#include	"../../LIB/STD_TYPES.h"
#include	"../../LIB/BIT_MATH.h"

/*****************************************************************************************************
									 SPI Includes
 ****************************************************************************************************/
#include 	"SPI_Configuration.h"
#include 	"SPI_Private.h"
#include	"SPI_Interface.h"



/*****************************************************************************************************
									 SPI Prototypes
 ****************************************************************************************************/
/**
 * @brief Initializes SPI so it is ready to send and receive as a master
 * @param None
 * @return void
 */
void	MSPI1_voidInit(void)
{
	/*Set clock polarity to 1 to activate active low  - SPI work swith active low*/
	SET_BIT(SPI1_REG->SPI_CR1, 1);
	/*Set clock phase to capture data on the 2nd clock transition*/
	SET_BIT(SPI1_REG->SPI_CR1, 0);

	/*Configure myself as master */
	SET_BIT(SPI1_REG->SPI_CR1, 2);
	/*Baud rate control*/
	//SPI1_REG->SPI_CR1 = (SPI1_REG->SPI_CR1 &~(0b111<3))|(BAUD_RATE);

	/*Format frame to MSB 1st because thats what TFT requires -- generalize later*/
	CLR_BIT(SPI1_REG->SPI_CR1, 7);

	/*SSM - Disable slave management as slave is external*/
	SET_BIT(SPI1_REG->SPI_CR1, 9);
	/*This next line has no effect as the SSM bit is cleared */
	SET_BIT(SPI1_REG->SPI_CR1, 8);

	/*Data frame format - choose 8*/
	CLR_BIT(SPI1_REG->SPI_CR1, 11);

	/*SPI Enable*/
	SET_BIT(SPI1_REG->SPI_CR1, 6);
}

/**
 * @brief Transmit data or receive
 * @param Copy_u8data The data to transmit
 * @return u8 Received data
 */
u8 MSPI_voidMasterTransmitReceive(u8 Copy_u8data)
{
	SPI1_REG->SPI_DR = (u32)Copy_u8data;

	/*While the Shift Register buffer is empty by bit 1 in status register*/
	while(GET_BIT(SPI1_REG->SPI_SR, 7) == 1);
	/*Return and mask the 1st 16 bits by casting to u8*/
	return ( (u8) SPI1_REG->SPI_DR);
}
