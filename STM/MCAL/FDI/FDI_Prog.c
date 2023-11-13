/*
 * FLASHREG_Prog.c
 *
 *  Created on: Sep 27, 2023
 *      Author: Somia Soliman
 */

/*****************************************************************************************************
									 Library Includes
 ****************************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*****************************************************************************************************
									 FDI Includes
 ****************************************************************************************************/
#include "FDI_Private.h"

/**
 * @brief Erases the flash memory chosen sector by waiting for flash to be ready then unlock flash register then choosing the sector to be erased then starting the erasing process
 * @param A_u8SectorNum holds the sector number to be erased
 * @return void
 */

void MFDI_voidEraseSector(u8 A_u8SectorNum){

	if( A_u8SectorNum==0 ||  A_u8SectorNum>5){
	}else {
 //error sequence
	}
	//wait if flash is busy
	while(GET_BIT(MFDI->FLASH_SR,16)==1);
	//check if authorized for configuration, if not unlock flash register using KEYR
	if(GET_BIT(MFDI->FLASH_CR,31)==1){
		//Unlock flash register using KEYR
		MFDI->FLASH_KEYR = MFDI_KEY1;
		MFDI->FLASH_KEYR = MFDI_KEY2;
	}
	//selection of selector to be erased
	MFDI->FLASH_CR &=~((u32)(0b1111<<3)); //clear 3 selection bits (3->5)
	MFDI->FLASH_CR |= ((u32)( A_u8SectorNum <<3)); //selecting the selector

	//activate selector erase
	SET_BIT(MFDI->FLASH_CR,1);

	//start erase operation
	SET_BIT(MFDI->FLASH_CR,16);

	//wait until erasing is finished
	while(GET_BIT(MFDI->FLASH_SR,16)==1);

	//clear EOP flag
	SET_BIT(MFDI->FLASH_SR,0);

	//deactivate sector erase
	CLR_BIT(MFDI->FLASH_CR,1);

}
/**
 * @brief Writing the new hex file after erasing the flash by waiting for flash to be ready then unlock flash register then select element size then activating programming the flash then writing data array on flash address
 * @param A_u32Address holds the flash address
 * @param * A_ptrData pointer that points to array that holds the data to be flashed
 * @param A_u8DataLength holds the data length
 * @return void
 */
void MFDI_voidFlashWrite(u32 A_u32Address,u16 * A_ptrData , u16 A_u8DataLength){
	//wait if busy bit is set
	while(GET_BIT(MFDI->FLASH_SR,16)==1);
	//check if authorized for configuration, if not unlock flash register using KEYR
	if(GET_BIT(MFDI->FLASH_CR,31)==1){
		//Unlock flash register using KEYR
		MFDI->FLASH_KEYR = MFDI_KEY1;
		MFDI->FLASH_KEYR = MFDI_KEY2;
	}
  //select element size
  MFDI->FLASH_CR &=0xFFFFFCFF;
  MFDI->FLASH_CR |= WRITE_HALF_WORD<<8;
  //activate programming flash
  SET_BIT(MFDI->FLASH_CR,0);
// write Data Array on flash address
  for(u8 i=0;i<A_u8DataLength;i++){

      *((volatile u16 *)A_u32Address)= A_ptrData[i];
      A_u32Address +=2; //as we have half word 2bytes

  	//wait until flashing is finished
  	while(GET_BIT(MFDI->FLASH_SR,16)==1);

  	//clear EOP flag
  	SET_BIT(MFDI->FLASH_SR,0);

	//deactivate programing flash
  	CLR_BIT(MFDI->FLASH_CR,0);


  }
}
/**
 * @brief Erases the application from flash memory by erasing each sector
 * @param None
 * @return void
 */
void MFDI_voidEraseApp(){
 u8 L_u8Iterator ;
 for(L_u8Iterator=1 ; L_u8Iterator<=7 ; L_u8Iterator++){
	 MFDI_voidEraseSector(L_u8Iterator);
 }
}

