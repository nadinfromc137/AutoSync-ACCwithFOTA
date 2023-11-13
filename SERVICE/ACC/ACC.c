/*
 * File:	   ACC.c
 * Author:     Nadin Magdy
 * Created on: Oct 29, 2023
 * Version:    1.0.0 
 * Layer: 		SERVICE
 * Description: Controls Car Speed through timer
 *
 * Module Features    1 - ACC_init
					  2 - ACC_voidChangeSpeed
					  3 - ACC_voidSetSpeed
					  4 - ACC_AdaptiveSpeedControl
					  5 - ACC_voidStopCar
 */

/*****************************************************************************************************
									 Library Includes
 ****************************************************************************************************/
#include 	"../../LIB/BIT_MATH.h"
#include 	"../../LIB/STD_TYPES.h"

/*****************************************************************************************************
									 Interface Includes
 ****************************************************************************************************/
#include	"../../MCAL/GPIO/GPIO_Interface.h"
#include	"../../MCAL/TIM/TIM_Interface.h"
#include	"../../HAL/ULTRASONIC/ULTRASONIC_interface.h"

/*****************************************************************************************************
									 ACC Includes
 ****************************************************************************************************/
#include 	"ACC.h"


 /*****************************************************************************************************
									 Global Variables
 *****************************************************************************************************/
u8 DutyCycle;
f32 distaceMeasured;
extern u8 data;
extern TMRn_t Global_uddtTimerNumber;
extern u8  Global_u8DutyCycle;
extern u16 Global_u16ARR;
extern u16 Global_u16Prescaler;
extern u8 Global_u8data;
extern MODEn_t Global_uddtMode;
extern CHANNELn_t Global_uddtChNo;
extern u8 Global_u8CruiseControlMode;
extern u8 Global_SafeDistance;


 /*****************************************************************************************************
									 ACC Function Definitions
 *****************************************************************************************************/

// (_TIM2, 64, 10000-1, 6, 1, DutyCycle)
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
void ACC_Init(TMRn_t Copy_uddtTMR, u16 Copy_u16Prescaler, u16 Copy_u16ARR, MODEn_t Copy_uddtFn, CHANNELn_t Copy_uddtChNo, u8 Copy_u8DutyCycle)
{
	MTIM_voidSetPrescaler(Copy_uddtTMR, Copy_u16Prescaler);
	MTIM_voidSetAutoreloadPreload(Copy_uddtTMR, Copy_u16ARR);
	MTMR_voidSetChannelOutput(Copy_uddtTMR, Copy_uddtFn, Copy_uddtChNo);
	MTIM_voidStartTimer(Copy_uddtTMR);
	DutyCycle = 85; // 1 -->100
	MTIM_voidSetCCR1( Copy_uddtTMR, (100*Copy_u8DutyCycle)-1);
}

/**
 * @brief Changed speed of motors through changing duty cycle
 * @param Copy_uddtTMR
 * @param Copy_u8DutyCycle
 * @return void
 */
void ACC_voidChangeSpeed(TMRn_t Copy_uddtTMR, u8 Copy_u8DutyCycle)
{
	MTIM_voidSetCCR1( Copy_uddtTMR, (100*Copy_u8DutyCycle)-1);
}


/**
 * @brief Depending on UART input, set duty cycle speed
 * @param Copy_uddtTMR
 * @param Copy_u8Signal
 */
void ACC_voidSetSpeed(TMRn_t Copy_uddtTMR, u8 Copy_u8Signal)
{
	/*Check if in Normal Cruise Control*/
	if(20 == Global_u8CruiseControlMode)
	{
		if(0 == Copy_u8Signal)
		{
			Global_u8DutyCycle = 1;
			MTIM_voidSetCCR1(Copy_uddtTMR, (100*Global_u8DutyCycle)-1);
		}
		else if (3 == Copy_u8Signal)
		{
			Global_u8DutyCycle = 30;
			MTIM_voidSetCCR1(Copy_uddtTMR, (100*Global_u8DutyCycle)-1);
		}
		else if (6 == Copy_u8Signal)
		{
			Global_u8DutyCycle = 60;
			MTIM_voidSetCCR1(Copy_uddtTMR, (100*Global_u8DutyCycle)-1);
		}
		else if (9 == Copy_u8Signal)
		{
			Global_u8DutyCycle = 90;
			MTIM_voidSetCCR1(Copy_uddtTMR, (100*Global_u8DutyCycle)-1);
		}
	}

}

/**Call in while if in adaptive mode because will keep adapting speed*/
void ACC_AdaptiveSpeedControl(void)
{
	if(30 == Global_u8CruiseControlMode)
	{
		distaceMeasured = HULTRASONIC_f32GetDistance();
		/*Measure Distace using Ultrasonic*/

		/* If distace less than safe ditance adjust and decrease speed*/
		if(Global_SafeDistance > distaceMeasured)
		{
			/*Check duty cycle, and make sure it is less by 20 */
			if(Global_u8DutyCycle > 20)
			{
				Global_u8DutyCycle -= 10;
				MTIM_voidSetCCR1(Global_uddtTimerNumber, (100*Global_u8DutyCycle)-1);
			}

		}
		/* If distace more than safe ditance adjust and increase speed*/
		else if(Global_SafeDistance < distaceMeasured)
		{
			/*Check duty cycle, and make sure it is less than 90 */
			if(Global_u8DutyCycle < 90)
			{
				Global_u8DutyCycle += 10;
				MTIM_voidSetCCR1(Global_uddtTimerNumber, (100*Global_u8DutyCycle)-1);
			}
		}
		else if (5 > distaceMeasured) /*Collision avoidance*/
		{
			Global_u8DutyCycle = 1;
			MTIM_voidSetCCR1(Global_uddtTimerNumber, (100*Global_u8DutyCycle)-1);
		}
		else {

			/*keep else empty for MISRA C */
		}
	}

}

/**
 * @brief Function that stops the car
 * @param None
 * @return None
 *
 */
void ACC_voidStopCar(void)
{
	MTIM_voidStopTimer(Global_uddtTimerNumber);

}



