/*
 * File:	   BIT_MATH.h
 * Author:     Nadin Magdy
 * Created on: Aug 18, 2023
 * Layer:      C:\Users\nadin\Documents\Eclipse\Drivers\DIO\src\LIB\BIT_MATH.h 
 *      
 */

/*Preprocessor file guard*/
#ifndef SRC_LIB_BIT_MATH_H_
#define SRC_LIB_BIT_MATH_H_

#define 	 SET_BIT(REG,BIT)     		REG|=(1<<BIT)
#define 	 CLR_BIT(REG,BIT)			REG&=~(1<<BIT)
#define 	 TGL_BIT(REG,BIT)			REG^=~(1<<BIT)
#define 	 GET_BIT(REG,BIT)			((REG>>BIT)&1)
#define 	 SWAP_NIBBLES(REG) 			(((REG & 0x0F)<<4)|((REG & 0xF0)>>4))
#define 	 SWAP_TWO_BYTES(REG) 		(((REG & 0x00FF)<<8)|((REG & 0xFF00)>>8))
#define		 GET_HIGH_NIBBLE(REG)		(((u8)(REG>>4)) & 0x0F) 		/*not sure if working*/
#define		 GET_LOW_NIBBLE(REG)		(((u8)(REG)) & 0x0F) 		/*not sure if working*/
//#define		 SWAP_ENDIANS(REG)
#define 	CLR_BITS(REG,MSK)            (REG) &= ~(MSK)
#define 	CLR_ALL_BITS(REG)            (REG) =  (0x00000000)

#endif /* SRC_LIB_BIT_MATH_H_ */
