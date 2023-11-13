/*
 * FLASHREG_Private.h
 *
 *  Created on: Sep 27, 2023
 *      Author: HP
 */

#ifndef MCAL_FLASH_REG_FDI_PRIVATE_H_
#define MCAL_FLASH_REG_FDI_PRIVATE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#define MFDI_BASE_ADDRESS 0x40023C00

typedef struct{
	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_OPTCR;

}MFDI_T;

#define MFDI_KEY1  0x45670123
#define MFDI_KEY2  0xCDEF89AB

#define WRITE_HALF_WORD 1

#define MFDI ((volatile MFDI_T *)MFDI_BASE_ADDRESS)

#endif /* MCAL_FLASH_REG_FDI_PRIVATE_H_ */
