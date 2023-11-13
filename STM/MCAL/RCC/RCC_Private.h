/*
 * File:	   RCC_Private.h
 * Author:     Nadin Magdy
 * Created on: Sep 10, 2023
 * Version:    1.0.0 
 *      
 */

/*Preprocessor file guard*/
#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

#define NULL ((void *)0)

#include 	"../../LIB/STD_TYPES.h"
#include 	"../../LIB/BIT_MATH.h"


/*
 * RCC has 3 different clocks
 * HSI high speed internal  --> internal 16mhz osc
 * HSE high speed external
 * PLL
 *
 * AHB is configured using prescalers , its max is 84mhz
 * and max of apb-high-speed is 84mhx also
 * of apb is 42mhz
 *
 * rcc gives ecternal clock with ahb / 8
 *
 * */


/*RCC Clock Control Register*/
#define			RCC_CCR_BASE_ADDRESS		0x40023800

typedef struct{
	u32  	RCC_CR;
	u32		RCC_PLLCFGR;
	u32		RCC_CFGR;
	u32		RCC_CIR;
	u32		RCC_AHB1RSTR;
	u32		RCC_AHB2RSTR;

	u32		RESERVED1[2];

	u32		RCC_APB1RSTR;
	u32		RCC_APB2RSTR;

	u32		RESERVED2[2];

	u32		RCC_AHB1ENR;
	u32		RCC_AHB2ENR;

	u32 	RESERVED3[2];

	u32		RCC_APB1ENR;
	u32		RCC_APB2ENR;

	u32		RESERVED4[2];

	u32		RCC_AHB1LPENR;
	u32		RCC_AHB2LPENR;

	u32		RESERVED5[2];

	u32		RCC_APB1LPENR;
	u32		RCC_APB2LPENR;

	u32 	RESERVED6[2];

	u32		RCC_BDCR;
	u32		RCC_CSR;

	u32 	RESERVED7[2];

	u32		RCC_SSCGR;
	u32		RCC_PLL2I2SCFGR;

	u32		RESERVED8;

	u32		RCC_DCKCFGR;
} RCC_t;


#define		RCC_REG		((RCC_t * )(RCC_CCR_BASE_ADDRESS))



#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
