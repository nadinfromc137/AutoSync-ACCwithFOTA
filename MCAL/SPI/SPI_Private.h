/*
 * File:	   SPI_Private.h
 * Author:     Nadin Magdy
 * Created on: Sep 20, 2023
 * Version:    1.0.0 
 *      
 */

/*Preprocessor file guard*/
#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_


#define		SPI1_BASE_ADDRESS		0x40013000
#define		SPI2_BASE_ADDRESS		0x40003800
#define		SPI3_BASE_ADDRESS		0x40003C00
#define		SPI4_BASE_ADDRESS		0x40013400


typedef struct {
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_CFGR;
	volatile u32 SPI_I2SPR;
} SPI_t;


#define		SPI1_REG 	((volatile SPI_t *)(SPI1_BASE_ADDRESS))
#define		SPI2_REG 	((volatile SPI_t *)(SPI2_BASE_ADDRESS))
#define		SPI3_REG 	((volatile SPI_t *)(SPI3_BASE_ADDRESS))
#define		SPI4_REG 	((volatile SPI_t *)(SPI4_BASE_ADDRESS))

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
