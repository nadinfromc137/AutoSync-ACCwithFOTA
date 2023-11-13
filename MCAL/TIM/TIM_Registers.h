/*
 * File:	   TIM_Registers.h
 * Author:     Nadin Magdy
 * Created on: Oct 10, 2023
 * Version:    1.0.0 
 *      
 */

/*Preprocessor file guard*/
#ifndef MCAL_TIM_TIM_REGISTERS_H_
#define MCAL_TIM_TIM_REGISTERS_H_

/*
 ****************************************************************************************************
									TIM Addresses
 ****************************************************************************************************
*/

/*Operating on APB2 - ADVANCED CONTROL TIMER*/
#define			TIM1_BASE_ADDRESS		0x4001000
/*Operating on APB1 - GENERAL PURPOSE TIMERS*/
#define			TIM2_BASE_ADDRESS		0x40000000
#define			TIM3_BASE_ADDRESS		0x4000400
#define			TIM4_BASE_ADDRESS		0x4000800
#define			TIM5_BASE_ADDRESS		0x4000C00

/*
 ****************************************************************************************************
									TIM Structs
 ****************************************************************************************************
*/

/*TIM1 Advanced Control Timer*/
/*
 * TIM_CR1:		Control Register 1
 * TIM_CR2:		Control Register 2
 * TIM_SMCR:	Slave Mode Control Register
 * TIM_DIER:	DMA/Interrupt Enable Register
 * TIM_SR:		Status Register
 * TIM_EGR: 	Event Generation Register
 * TIM_CCMR1:	Capture/Compare Mode Register 1
 * TIM_CCMR2:	Capture/Compare Mode Register 2
 * TIM_CCER:	Capture/Compare Enable Register
 * TIM_CNT:		Counter Register
 * TIM_PSC: 	Prescaler Register
 * TIM_ARR:		Auto-reload Register
 * TIM_RCR:		Repetition Count Register
 * TIM_CCR1: 	Capture/Compare Register 1
 * TIM_CCR2: 	Capture/Compare Register 2
 * TIM_CCR3: 	Capture/Compare Register 3
 * TIM_CCR4: 	Capture/Compare Register 4
 * TIM_BDTR:	Break and Dead-time Register
 * TIM_DCR:		DMA Control Register
 * TIM_DMAR: 	DMA Address for Full Transfer
 *
 * */
typedef struct{
	volatile u32 TIM_CR1;
	volatile u32 TIM_CR2;
	volatile u32 TIM_SMCR;
	volatile u32 TIM_DIER;
	volatile u32 TIM_SR;
	volatile u32 TIM_EGR;
	volatile u32 TIM_CCMR1;
	volatile u32 TIM_CCMR2;
	volatile u32 TIM_CCER;
	volatile u32 TIM_CNT;
	volatile u32 TIM_PSC;
	volatile u32 TIM_ARR;
	volatile u32 TIM_RCR;
	volatile u32 TIM_CCR1;
	volatile u32 TIM_CCR2;
	volatile u32 TIM_CCR3;
	volatile u32 TIM_CCR4;
	volatile u32 TIM_BDTR;
	volatile u32 TIM_DCR;
	volatile u32 TIM_DMAR;
} TIM1_t;



/*TIM2 to TIM5 General Purpose Timers*/
/*
 * TIM_CR1:		Control Register 1
 * TIM_CR2:		Control Register 2
 * TIM_SMCR:	Slave Mode Control Register
 * TIM_DIER:	DMA/Interrupt Enable Register
 * TIM_SR:		Status Register
 * TIM_EGR: 	Event Generation Register
 * TIM_CCMR1:	Capture/Compare Mode Register 1
 * TIM_CCMR2:	Capture/Compare Mode Register 2
 * TIM_CCER:	Capture/Compare Enable Register
 * TIM_CNT:		Counter Register
 * TIM_PSC: 	Prescaler Register
 * TIM_ARR:		Auto-reload Register
 * TIM_CCR1: 	Capture/Compare Register 1
 * TIM_CCR2: 	Capture/Compare Register 2
 * TIM_CCR3: 	Capture/Compare Register 3
 * TIM_CCR4: 	Capture/Compare Register 4
 * TIM_DCR:		DMA Control Register
 * TIM_DMAR: 	DMA Address for Full Transfer
 * TIM_OR:		Option Register for Timers 2 and 5 only
 *
 * */
typedef struct{
	volatile u32 TIM_CR1;
	volatile u32 TIM_CR2;
	volatile u32 TIM_SMCR;
	volatile u32 TIM_DIER;
	volatile u32 TIM_SR;
	volatile u32 TIM_EGR;
	volatile u32 TIM_CCMR1;
	volatile u32 TIM_CCMR2;
	volatile u32 TIM_CCER;
	volatile u32 TIM_CNT;
	volatile u32 TIM_PSC;
	volatile u32 TIM_ARR;
	volatile u32 RESERVED1;
	volatile u32 TIM_CCR1;
	volatile u32 TIM_CCR2;
	volatile u32 TIM_CCR3;
	volatile u32 TIM_CCR4;
	volatile u32 RESERVED2;
	volatile u32 TIM_DCR;
	volatile u32 TIM_DMAR;
	volatile u32 TIM_OR;
} TIM2to5_MemoryMap_t;


/*
 ****************************************************************************************************
									PIN MACROS
 ****************************************************************************************************
*/
#define		CR1_CEN			0U
#define		CR1_UDIS		1U
#define		CR1_URS			2U
#define		CR1_OPM			3U
#define		CR1_DIR			4U
#define		CR1_CMS			5U
#define		CR1_CKD			6U

#define		CR2_CCDS		3U
#define		CR2_MMS0		4U
#define		CR2_MMS1		5U
#define		CR2_MMS2		6U
#define		CR2_TI1S		7U

#define		CCER_CC3E		8U			/*Capture/Compare output enable*/
#define		CCMR1_OC1M_SHIFT		4U

/*
 ****************************************************************************************************
									TIM Register Pointers
 ****************************************************************************************************
*/
#define		TIM1	((volatile TIM1_t *)(TIM1_BASE_ADDRESS))
#define		TIM2	((volatile TIM2to5_MemoryMap_t *)(TIM2_BASE_ADDRESS))
#define		TIM3	((volatile TIM2to5_MemoryMap_t *)(TIM3_BASE_ADDRESS))
#define		TIM4	((volatile TIM2to5_MemoryMap_t *)(TIM4_BASE_ADDRESS))
#define		TIM5	((volatile TIM2to5_MemoryMap_t *)(TIM5_BASE_ADDRESS))

#endif /* MCAL_TIM_TIM_REGISTERS_H_ */
