/*
 * File:	   Motor_Interface.h
 * Author:     Nadin Magdy
 * Created on: Oct 14, 2023
 * Version:    1.0.0 
 *      
 */

/*Preprocessor file guard*/
#ifndef HAL_MOTOR_MOTOR_INTERFACE_H_
#define HAL_MOTOR_MOTOR_INTERFACE_H_

#define 	MOTOR_RIGHT_PINA		MGPIO_PIN3
#define		MOTOR_RIGHT_PINB		MGPIO_PIN6

#define 	MOTOR_LEFT_PINA			MGPIO_PIN4
#define		MOTOR_LEFT_PINB			MGPIO_PIN7

void HMOTOR_voidInit(void);
void HMOTOR_voidMove(void);

#endif /* HAL_MOTOR_MOTOR_INTERFACE_H_ */
