/*
 * File:	  		TIM_Interface.h
 * Author:     		Nadin Magdy
 * Created on: 		Oct 10, 2023
 * Version:    		1.0.0
 * Microcontroller: STM32F401CCU6
 *
 * Module Features   1 -
 * 					 2 -
 *      
 */

/*Preprocessor file guard*/
#ifndef MCAL_TIM_TIM_INTERFACE_H_
#define MCAL_TIM_TIM_INTERFACE_H_

 /*
 ****************************************************************************************************
									 TIM Typedefs
 ****************************************************************************************************
*/
typedef enum  {
	_TIM1 = 1,
	_TIM2,
	_TIM3,
	_TIM4,
	_TIM5
}TMRn_t;

typedef enum{
	_CHANNEL1 = 1,
	_CHANNEL2,
	_CHANNEL3,
	_CHANNEL4
}CHANNELn_t;

/*
 * 8 modes, bits 4-->6 in CCMR1
 * */
typedef enum{
	FROZEN, // 000
	ACTIVE_ON_MATCH,
	INACTIVE_ON_MATCH,
	TOGGLE,
	FORCE_INACTIVE,
	FORCE_ACTIVE,
	PWM_MODE_1, // 6, used
	PWM_MODE_2
}MODEn_t;


/*
 ****************************************************************************************************
									TIMER FUNCTION PROTOTYPES
 ****************************************************************************************************
*/
void 	MTIM_voidTIMConfigure(void);
void 	MTIM_voidStartTimer(TMRn_t Copy_uddtTMR);
void 	MTIM_voidStopTimer(TMRn_t Copy_uddtTMR);
void 	MTIM_voidSetPrescaler(TMRn_t Copy_uddtTMR, u16 Copy_u16Prescaler);
void 	MTIM_voidSetCounter(TMRn_t Copy_uddtTMR, u16 Copy_u16Count, u32 Copy_u32Count);
void 	MTIM_voidClearCounter(TMRn_t Copy_uddtTMR);
void 	MTIM_voidSetAutoreloadPreload(TMRn_t Copy_uddtTMR, u16 Copy_u16ARR);
void	MTIM_voidCaptureCompareModeInit(void);
u32		MTIM_u32GetCurrentCount(TMRn_t Copy_uddtTMR);
u32		MTIM_u32GetCaptureValue(TMRn_t Copy_uddtTMR);
void 	MTMR_voidSetChannelOutput(TMRn_t Copy_uddtTMR_no, MODEn_t Copy_uddtFn, CHANNELn_t Copy_uddtChNo);
void 	MTIM_voidTIM2init();
void 	MTIM_voidAll();
void 	MTIM_voidSetCCR1(TMRn_t Copy_uddtTMR_no, u32 copy_u32CmpValue);





#endif /* MCAL_TIM_TIM_INTERFACE_H_ */
