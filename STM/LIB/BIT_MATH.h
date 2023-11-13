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

/**
 * @brief Sets the given bit in the register
 */
#define 	 SET_BIT(REG,BIT)     		REG|=(1<<BIT)

/**
 * @brief Clears the given bit in the register
 */
#define 	 CLR_BIT(REG,BIT)			REG&=~(1<<BIT)

/**
 * @brief Toggles the given bit in the register
 */
#define 	 TGL_BIT(REG,BIT)			REG^=~(1<<BIT)

/**
 * @brief Gets the given bit in the register
 */
#define 	 GET_BIT(REG,BIT)			((REG>>BIT)&1)

/**
 * @brief Swaps 2 nibbles in the low byte of a register
 */
#define 	 SWAP_NIBBLES(REG) 			(((REG & 0x0F)<<4)|((REG & 0xF0)>>4))

/**
 * @brief Swaps 2 bites in the low word of a register
 */
#define 	 SWAP_TWO_BYTES(REG) 		(((REG & 0x00FF)<<8)|((REG & 0xFF00)>>8))

/**
 * @brief Gets the high nibble in a byte sized register
 */
#define		 GET_HIGH_NIBBLE(REG)		(((u8)(REG>>4)) & 0x0F)

/**
 * @brief  Gets the low nibble in a byte sized register
 */
#define		 GET_LOW_NIBBLE(REG)		(((u8)(REG)) & 0x0F)

/**
 * @brief  Clears the register depending on the mask
 */
#define 	 CLR_BITS(REG,MSK)            (REG) &= ~(MSK)

/**
 * @brief  Clears all bits of a 32 bit register
 */
#define 	 CLR_ALL_BITS(REG)            (REG) =  (0x00000000)

#endif /* SRC_LIB_BIT_MATH_H_ */
