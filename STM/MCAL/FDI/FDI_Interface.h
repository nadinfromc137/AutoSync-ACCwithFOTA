/*
 * FLASHREG_Interface.h
 *
 *  Created on: Sep 27, 2023
 *      Author: HP
 */

#ifndef MCAL_FLASH_REG_FDI_INTERFACE_H_
#define MCAL_FLASH_REG_FDI_INTERFACE_H_



void MFDI_voidEraseSector(u8 A_u8SectorNum);

void MFDI_voidFlashWrite(u32 A_u32Address,u16 * A_ptrData , u8 A_u8DataLength);

void MFDI_voidEraseApp(void);

#endif /* MCAL_FLASH_REG_FDI_INTERFACE_H_ */
