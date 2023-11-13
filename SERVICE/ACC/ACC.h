/*
 * File:	   ACC.h
 * Author:     Nadin Magdy
 * Created on: Oct 29, 2023
 * Version:    1.0.0 
 *      
 */

/*Preprocessor file guard*/
#ifndef ACC_ACC_H_
#define ACC_ACC_H_

 /*
 ****************************************************************************************************
									 ACC Prototypes
 ****************************************************************************************************
*/

/**
 * @brief Function that takes timer setting and initializes them
 * @param Copy_uddtTMR
 * @param Copy_u16Prescaler
 * @param Copy_u16ARR
 * @param Copy_uddtFn
 * @param Copy_uddtChNo
 * @param Copy_u8DutyCycle
 * @return void
 */
void ACC_Init(TMRn_t Copy_uddtTMR, u16 Copy_u16Prescaler, u16 Copy_u16ARR, MODEn_t Copy_uddtFn, CHANNELn_t Copy_uddtChNo, u8 Copy_u8DutyCycle);

/**
 * @brief Changed speed of motors through changing duty cycle
 * @param Copy_uddtTMR
 * @param Copy_u8DutyCycle
 * @return void
 */
void ACC_voidChangeSpeed(TMRn_t Copy_uddtTMR, u8 Copy_u8DutyCycle);

/**
 * @brief
 * @param Copy_uddtTMR
 * @param Copy_u8Signal
 */
void ACC_voidSetSpeed(TMRn_t Copy_uddtTMR, u8 Copy_u8Signal);

void ACC_AdaptiveSpeedControl(void);

/**
 * @brief
 */
void ACC_voidStopCar(void);

#endif /* ACC_ACC_H_ */
