/*
 * HEX_Prog.c

 *
 *  Created on: Sep 28, 2023
 *      Author: Somia Soliman
 */
/*****************************************************************************************************
									 Library Includes
 ****************************************************************************************************/
#include 	"../../LIB/BIT_MATH.h"
#include 	"../../LIB/STD_TYPES.h"


/*****************************************************************************************************
									 Interface Includes
 ****************************************************************************************************/
#include "../../MCAL/FDI/FDI_Interface.h"

u32 FLASH_ADDRESS=0x08000000;
u32 G_u32Higher=0 ;
/**
 * @brief Parsing ASCII digits to hex for example : \n
   '0' --> 0   '0'-'0' = 0;   //'0' = 48  '1' = 49 \n
   '1' --> 1   '1'-'0' = 1; \n
   '9' --> 9   '9'-'0' = 9; \n

//'A' --> 10  'A'-'A'+10=10; \n
//'B' --> 11  'B'-'A'+10=11; \n
 * @param ASCII the ASCII value for each received digit
 * @return u8
 */
u8 HEX_ParsASCII2HEX( u8 ASCII){

	u8 Hex_Value=0;
	//0-->9
	if(ASCII>='0' && ASCII<='9'){
		Hex_Value=ASCII-'0';
		//A-->F , 10-->15
	}else if(ASCII>='A' && ASCII<='F'){
		Hex_Value=ASCII-'A'+10;
	}
	return Hex_Value;
}
/**
 * @brief parses each received record
 * @param *Copy_BufRecord pointer to array that holds the received record
 * @return void
 */
void HEX_voidParseRecord(u8*Copy_BufRecord)
{
	u8  L_u8NOElementInRecord=0 ; // arr[1,2]
	u8  CC_L , CC_H ;
	u32 L_AddressOfRecord=0;
	u32 LowerAddress=0;
	u16 digit3 , digit2, digit1, digit0 ;
	u16 L_u16DataOfRecord[10]; // arr[9,....]

	if(Copy_BufRecord[8]=='4'){
		u32 G_u32Higher=0 ;
		digit0 =  HEX_ParsASCII2HEX(Copy_BufRecord[9]);
		digit1 =  HEX_ParsASCII2HEX(Copy_BufRecord[10]);
		digit2 =  HEX_ParsASCII2HEX(Copy_BufRecord[11]);
		digit3 =  HEX_ParsASCII2HEX(Copy_BufRecord[12]);
		G_u32Higher = (digit0<<12) |(digit1<<8)|(digit2<<4)|(digit3);

	}else {
		CC_H = HEX_ParsASCII2HEX(Copy_BufRecord[1]); // 1
		CC_L = HEX_ParsASCII2HEX(Copy_BufRecord[2]);
		L_u8NOElementInRecord = CC_L | (CC_H<<4);//ok // 0x10  --> 0b 0001 0000 = 0b0000 0000 | (0b0000 0001<<4)
		// 0x4000 = 0100 0000 0000 0000    12,8,4,0
		//indexInArr  3   4    5    6
		//         digit0 , digit1, digit2, digit3
		digit0 =  HEX_ParsASCII2HEX(Copy_BufRecord[3]);
		digit1 =  HEX_ParsASCII2HEX(Copy_BufRecord[4]);
		digit2 =  HEX_ParsASCII2HEX(Copy_BufRecord[5]);
		digit3 =  HEX_ParsASCII2HEX(Copy_BufRecord[6]);
		LowerAddress=0;
		LowerAddress = (digit0<<12) |(digit1<<8)|(digit2<<4)|(digit3); // 0x4000

	}if(G_u32Higher == 0)
	{
		G_u32Higher = 0x800;
	}
	L_AddressOfRecord = LowerAddress | (G_u32Higher<<16) ; //ok
	/*
	 //Data of record index 9 ---> 9+L_u8NOElementInRecord
	 //0 0  0 0    0120 6142 0008 6542 0008 6742 0008  // 12 35   0x  35 12
	 //9 10 11 12 , 13,  17 , 21
	 //digit0 ,1,2,3
	  10 8000 00  00000120 6142 00 08 654200086742000884
	 * */
	for(u8  L_u8Counter=0;L_u8Counter<L_u8NOElementInRecord/2;L_u8Counter++) // u16
	{
		digit0 =  HEX_ParsASCII2HEX(Copy_BufRecord[L_u8Counter*4+9]);
		digit1 =  HEX_ParsASCII2HEX(Copy_BufRecord[L_u8Counter*4+10]);
		digit2 =  HEX_ParsASCII2HEX(Copy_BufRecord[L_u8Counter*4+11]);
		digit3 =  HEX_ParsASCII2HEX(Copy_BufRecord[L_u8Counter*4+12]);
		//			 L_u16DataOfRecord[L_u8Counter]= (digit0<<12) |(digit1<<8)|(digit2<<4)|(digit3);
		L_u16DataOfRecord[L_u8Counter]= (digit2<<12) |(digit3<<8)|(digit0<<4)|(digit1);
	}
	MFDI_voidFlashWrite(L_AddressOfRecord,L_u16DataOfRecord,L_u8NOElementInRecord/2);

}
