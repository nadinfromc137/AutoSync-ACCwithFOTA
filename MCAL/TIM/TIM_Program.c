/*
 * File:	   		TIM_Program.c
 * Author:     		Nadin Magdy
 * Created on: 		Oct 10, 2023
 * Version:    		1.0.0
 * Microcontroller: STM32F401CCU6
 *
 * Module Features   1 - MTIM_voidStartTimer
 * 					 2 - MTIM_voidStopTimer
 * 					 3 - MTIM_voidSetPrescaler
 * 					 4 - MTIM_voidSetCounter
 * 					 5 - MTIM_voidClearCounter
 * 					 6 - MTIM_voidSetAutoreloadPreload
 * 					 7 - MTIM_u32GetCurrentCount
 * 					 8 - MTIM_u32GetCaptureValue
 * 					 9 - MTMR_voidSetChannelOutput
 * 					 10 - MTIM_voidSetCCR1
 * 					 11 - MTIM_voidTIM2init
 *
 */

 /*
 ****************************************************************************************************
									 Library Files Include
 ****************************************************************************************************
*/
#include	"../../LIB/STD_TYPES.h"
#include	"../../LIB/BIT_MATH.h"

 /*
 ****************************************************************************************************
									 TMR Include
 ****************************************************************************************************
*/
#include	"TIM_Registers.h"
#include	"TIM_Private.h"
#include	"TIM_Interface.h"

/*
 ****************************************************************************************************
									FUNCTION IMPLEMENTATION
 ****************************************************************************************************
*/
/**
 * @brief Enables the timer passed to it
 * @param Copy_uddtTMR
 */
void 	MTIM_voidStartTimer(TMRn_t Copy_uddtTMR)
{
	switch(Copy_uddtTMR)
	{
	case _TIM2:
		/*Set mode to count up*/
		//CLR_BIT(TIM2->TIM_CR1, CR1_DIR);
		/*Enable count*/
		SET_BIT(TIM2->TIM_CR1, CR1_CEN);
		break;
	case _TIM3:
		/*Set mode to count up*/
		CLR_BIT(TIM3->TIM_CR1, CR1_DIR);
		/*Enable count*/
		SET_BIT(TIM3->TIM_CR1, CR1_CEN);
		break;
	case _TIM4:
		/*Set mode to count up*/
		CLR_BIT(TIM4->TIM_CR1, CR1_DIR);
		/*Enable count*/
		SET_BIT(TIM4->TIM_CR1, CR1_CEN);
		break;
	case _TIM5:
		/*Set mode to count up*/
		CLR_BIT(TIM5->TIM_CR1, CR1_DIR);
		/*Enable count*/
		SET_BIT(TIM5->TIM_CR1, CR1_CEN);
		break;
	default:
		break;
	}
}

/**
 * @brief Stops the timer by disabling
 * @param Copy_uddtTMR
 */
void 	MTIM_voidStopTimer(TMRn_t Copy_uddtTMR)
{
	switch(Copy_uddtTMR)
		{
		case _TIM2:
			/*Disable count bit*/
			CLR_BIT(TIM2->TIM_CR1, CR1_CEN);
			break;
		case _TIM3:
			/*Disable count bit*/
			CLR_BIT(TIM3->TIM_CR1, CR1_CEN);
			break;
		case _TIM4:
			/*Disable count bit*/
			CLR_BIT(TIM4->TIM_CR1, CR1_CEN);
			break;
		case _TIM5:
			/*Disable count bit*/
			CLR_BIT(TIM5->TIM_CR1, CR1_CEN);
			break;
		default:
			break;
		}
}


/**
 * @brief		Sets the prescaler of the timer
 * @details 	From data sheet manual:
 	 	 	 	Counter Clock Frequency = Fck_psc/(PSC+1)
 	 	 	 	PSC values --> from 1 to 65536

 * @param Copy_uddtTMR
 * @param Copy_u16Prescaler
 */
void 	MTIM_voidSetPrescaler(TMRn_t Copy_uddtTMR, u16 Copy_u16Prescaler)
{
	switch(Copy_uddtTMR)
			{
			case _TIM2:
				/*Clear any previous prescaler*/
				CLR_ALL_BITS(TIM2 -> TIM_PSC);
				TIM2->TIM_PSC |= Copy_u16Prescaler - 1;
				break;
			case _TIM3:
				/*Clear any previous prescaler*/
				TIM3->TIM_PSC &= 0;
				TIM3->TIM_PSC |= Copy_u16Prescaler - 1;
				break;
			case _TIM4:
				/*Clear any previous prescaler*/
				TIM4->TIM_PSC &= 0;
				TIM4->TIM_PSC |= Copy_u16Prescaler - 1;
				break;
			case _TIM5:
				/*Clear any previous prescaler*/
				TIM5->TIM_PSC &= 0;
				TIM5->TIM_PSC |= Copy_u16Prescaler - 1;
				break;
			default:
				break;
			}
}


/**
 * @brief Sets the counter value for each timer register
 * @details 	TIM2 and TIM5 are 32 bit
 * 				TIM3 and TIM4 are 16 bit
 * @param Copy_uddtTMR
 * @param Copy_u16Count
 * @param Copy_u32Count
 */
void 	MTIM_voidSetCounter(TMRn_t Copy_uddtTMR, u16 Copy_u16Count, u32 Copy_u32Count)
{
	switch(Copy_uddtTMR)
	{
		case _TIM2:
			TIM2->TIM_CNT = Copy_u32Count;
			break;
		case _TIM3:
			TIM3->TIM_CNT = Copy_u16Count;
			break;
		case _TIM4:
			TIM4->TIM_CNT = Copy_u16Count;
			break;
		case _TIM5:
			TIM5->TIM_CNT = Copy_u32Count;
			break;
		default:
			break;
		}
}


/**
 * @brief Sets autoload reload value that timer counts up to
 * @param Copy_uddtTMR
 * @param Copy_u16ARR
 */
void 	MTIM_voidSetAutoreloadPreload(TMRn_t Copy_uddtTMR, u16 Copy_u16ARR)
{
	switch(Copy_uddtTMR)
	{
		case _TIM2:
			TIM2->TIM_ARR = Copy_u16ARR;
			break;
		case _TIM3:
			TIM3->TIM_ARR = Copy_u16ARR;
			break;
		case _TIM4:
			TIM4->TIM_ARR = Copy_u16ARR;
			break;
		case _TIM5:
			TIM5->TIM_ARR = Copy_u16ARR;
			break;
		default:
			break;
		}
}

//void	MTIM_voidCaptureCompareModeInit(void);
u32		MTIM_u32GetCurrentCount(TMRn_t Copy_uddtTMR)
{
	switch(Copy_uddtTMR)
	{
		case _TIM2:
			return TIM2->TIM_CNT;
			break;
		case _TIM3:
			return (u16)TIM3->TIM_CNT;
			break;
		case _TIM4:
			return (u16)TIM4->TIM_CNT;
			break;
		case _TIM5:
			return TIM5->TIM_CNT;
			break;
		default:
			break;
		}
	return 0;
}


u32		MTIM_u32GetCaptureValue(TMRn_t Copy_uddtTMR)
{
	switch(Copy_uddtTMR)
		{
			case _TIM2:
				return TIM2->TIM_CCR1;
				break;
			case _TIM3:
				return (u16)TIM3->TIM_CCR1;
				break;
			case _TIM4:
				return (u16)TIM4->TIM_CCR1;
				break;
			case _TIM5:
				return TIM5->TIM_CCR1;
				break;
			default:
				break;
			}
	return 0;
}


/**
 * @brief Chooses which channel of which timer to set to which mode of the 7 modes (frozen, pwm1 pwm2, etc.)
 * @param Copy_uddtTMR_no
 * @param Copy_uddtFn
 * @param Copy_uddtChNo
 */
void MTMR_voidSetChannelOutput(TMRn_t Copy_uddtTMR_no, MODEn_t Copy_uddtFn, CHANNELn_t Copy_uddtChNo)
{
	switch(Copy_uddtTMR_no)
	{
	case _TIM2:
		switch(Copy_uddtChNo)
		{
			case _CHANNEL1:
				CLR_BITS(TIM2 -> TIM_CCMR1, 0x00000073);
				//TIM2->TIM_CCMR1 &= ~(0b111011);
				TIM2->TIM_CCMR1 |= (Copy_uddtFn << CCMR1_OC1M_SHIFT);
				SET_BIT(TIM2->TIM_CCER, 0U);
				break;
			case _CHANNEL2:
				break;
			case _CHANNEL3:
				TIM2->TIM_CCMR2 &= ~(0b111011);
				TIM2->TIM_CCMR2 |= (Copy_uddtFn << CCMR1_OC1M_SHIFT);
				SET_BIT(TIM2->TIM_CCER, CCER_CC3E);
				break;
			case _CHANNEL4:
				break;
		}
		break;
		default:
			break;
	}
}

/**
 * @brief Sets Capture Compare Value that sends interrupt to timer when the value is reached through the channel activated
 * @param Copy_uddtTMR_no
 * @param copy_u32CmpValue
 */
void MTIM_voidSetCCR1(TMRn_t Copy_uddtTMR_no, u32 copy_u32CmpValue)
{
	switch(Copy_uddtTMR_no)
	{
		case _TIM2:
			TIM2 -> TIM_CCR1 = copy_u32CmpValue;
			break;
		case _TIM3:

			break;
		case _TIM4:

			break;
		case _TIM5:

			break;
		default:
			break;
		}
}

void MTIM_voidTIM2init()
{
	/*Select output mode*/
	CLR_BIT(TIM2 -> TIM_CCMR2, 0);
	CLR_BIT(TIM2 -> TIM_CCMR2, 1);
	/*Select polarity as Active High*/
	CLR_BIT(TIM2 -> TIM_CCER, 9);
	/*Select PWM mode 1*/
	CLR_BIT(TIM2 -> TIM_CCMR2,4);
	SET_BIT(TIM2 -> TIM_CCMR2,5);
	SET_BIT(TIM2 -> TIM_CCMR2,6);

	SET_BIT(TIM2 -> TIM_CCMR2,3);
	/*Enable capture compare*/
	SET_BIT(TIM2 -> TIM_CCER, CCER_CC3E);

	CLR_BIT(TIM2 -> TIM_CR1, 7);
	/*Select counting mode*/
	CLR_BIT(TIM2 -> TIM_CR1,4);
	CLR_BIT(TIM2 -> TIM_CR1,5);
	CLR_BIT(TIM2 -> TIM_CR1,6);
}

