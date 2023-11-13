/*
 * File:	   Motor_Program.c
 * Author:     Nadin Magdy
 * Created on: Oct 14, 2023
 * Version:    1.0.0 
 *      
 */

/*
 ****************************************************************************************************
									 Interface Includes
 ****************************************************************************************************/
#include	"../../MCAL/RCC/RCC_Interface.h"
#include	"../../MCAL/GPIO/GPIO_Interface.h"
#include	"../../MCAL/TIM/TIM_Interface.h"
#include 	"Motor_Interface.h"

/**
 * @brief	Initialise the motor direction pins.
 * @param None
 * @return void
 */
void HMOTOR_voidInit(void)
{
	MGPIO_voidSetPinMode(MGPIO_PORTA, MOTOR_RIGHT_PINA, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetOutputMode(MGPIO_PORTA, MOTOR_RIGHT_PINA, MGPIO_OUTPUT_PUSHPULL);
	MGPIO_voidSetSpeed(MGPIO_PORTA, MOTOR_RIGHT_PINA, MGPIO_OUTPUT_SPEED_HIGH);

	MGPIO_voidSetPinMode(MGPIO_PORTA, MOTOR_LEFT_PINA, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetOutputMode(MGPIO_PORTA, MOTOR_LEFT_PINA, MGPIO_OUTPUT_PUSHPULL);
	MGPIO_voidSetSpeed(MGPIO_PORTA, MOTOR_LEFT_PINA, MGPIO_OUTPUT_SPEED_HIGH);

	MGPIO_voidSetPinMode(MGPIO_PORTA, MOTOR_RIGHT_PINB, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetOutputMode(MGPIO_PORTA, MOTOR_RIGHT_PINB, MGPIO_OUTPUT_PUSHPULL);
	MGPIO_voidSetSpeed(MGPIO_PORTA, MOTOR_RIGHT_PINB, MGPIO_OUTPUT_SPEED_HIGH);

	MGPIO_voidSetPinMode(MGPIO_PORTA, MOTOR_LEFT_PINB, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetOutputMode(MGPIO_PORTA, MOTOR_LEFT_PINB, MGPIO_OUTPUT_PUSHPULL);
	MGPIO_voidSetSpeed(MGPIO_PORTA, MOTOR_LEFT_PINB, MGPIO_OUTPUT_SPEED_HIGH);

	/***Pins A3 and A6 are set to high***/
    MGPIO_voidSetPinValue(MGPIO_PORTA, MOTOR_RIGHT_PINA, MGPIO_HIGH);
    MGPIO_voidSetPinValue(MGPIO_PORTA, MOTOR_RIGHT_PINB, MGPIO_LOW);

    /***Pins A4 and A7 are set to low***/
	MGPIO_voidSetPinValue(MGPIO_PORTA, MOTOR_LEFT_PINA, MGPIO_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PORTA, MOTOR_LEFT_PINB, MGPIO_LOW);
}

/**
 * @brief Moves the motor forward.
 * @param None
 * @return void
 */
void HMOTOR_voidMove(void)
{
	/***Pins A3 and A6 are set to high***/
    MGPIO_voidSetPinValue(MGPIO_PORTA, MOTOR_RIGHT_PINA, MGPIO_HIGH);
    MGPIO_voidSetPinValue(MGPIO_PORTA, MOTOR_RIGHT_PINB, MGPIO_LOW);

    /***Pins A4 and A7 are set to low***/
	MGPIO_voidSetPinValue(MGPIO_PORTA, MOTOR_LEFT_PINA, MGPIO_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PORTA, MOTOR_LEFT_PINB, MGPIO_LOW);
}

/**
 * @brief Reverses the motor turning direction.
 * @param None
 * @return void
 */
void HMOTOR_voidReverseMotorDirection()
{
	/***Pins A3 and A6 are set to low***/
    MGPIO_voidSetPinValue(MGPIO_PORTA, MGPIO_PIN3, MGPIO_LOW);
    MGPIO_voidSetPinValue(MGPIO_PORTA, MGPIO_PIN6, MGPIO_LOW);

    /***Pins A4 and A7 are set to high***/
	MGPIO_voidSetPinValue(MGPIO_PORTA, MGPIO_PIN4, MGPIO_HIGH);
	MGPIO_voidSetPinValue(MGPIO_PORTA, MGPIO_PIN7, MGPIO_HIGH);
}



