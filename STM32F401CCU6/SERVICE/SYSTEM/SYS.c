/*
 * File:	   SYS.c
 * Author:     Nadin Magdy
 * Created on: Oct 29, 2023
 * Version:    1.0.0 
 * Layer: 		SERVICE
 * Description: Has APIs that allows system components to interact
 *
 * Module Features    1 - sys_init
					  2 - sys_timerinit
					  3 - sys_USARTInit
					  4 - sys_HandleUARTInput
					  5 - sys_InitPinAsOutput
					  6 - sys_SetPinHigh
					  7 - sys_SetPinHigh
 */
/*****************************************************************************************************
									 Library Includes
 ****************************************************************************************************/
#include 	"../../LIB/BIT_MATH.h"
#include 	"../../LIB/STD_TYPES.h"

/*****************************************************************************************************
									 Interface Includes
 ****************************************************************************************************/
#include	"../../MCAL/RCC/RCC_Interface.h"
#include	"../../MCAL/GPIO/GPIO_Interface.h"
#include	"../../MCAL/TIM/TIM_Interface.h"
#include 	"../../MCAL/STK/STK_interface.h"
#include	"../../MCAL/UART/UART_interface.h"
#include	"../../HAL/MOTOR/Motor_Interface.h"
#include 	"../ACC/ACC.h"
#include	"SYS.h"

/*****************************************************************************************************
									 Global Variables
 ****************************************************************************************************/
u8 DutyCycle;
u8 data;
TMRn_t Global_uddtTimerNumber;
u8  Global_u8DutyCycle;
u16 Global_u16ARR;
u16 Global_u16Prescaler;
u8 Global_u8data;
MODEn_t Global_uddtMode;
CHANNELn_t Global_uddtChNo;
u8 Global_SafeDistance;

/***
	Global_u8CruiseControlMode Options:
  			10  :  Car off
 			20  :  Normal Cruise Control
 			30  :  Adaptive Cruise Control
 * */
u8 Global_u8CruiseControlMode;


/*****************************************************************************************************
									 Function Implementation
 ****************************************************************************************************/
/**
 * @brief This fucntion initializes the RCC and STK, and enables the needed GPIO ports
 * @return void
 * @param None
 */
void SYS_Init(void)
{
	/*Initilize RCC*/
	MRCC_voidInit();
	/*Initialize Systick*/
	MSTK_voidInit();

	/*Enable needed peripherals*/
	MRCC_voidEnablePeripheral(APB2_BUS, RCC_APB2_USART1);
	MRCC_voidEnablePeripheral(AHB1_BUS, RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(AHB1_BUS, RCC_AHB1_GPIOB);

	Global_SafeDistance = 10;

	/*
	 * Initialize USART1 PINS
	 *  PIN B6 -----> TX
	 *  PIN B7 -----> RX
	 *  */
	MGPIO_voidSetPinMode(MGPIO_PORTB, MGPIO_PIN7, MGPIO_MODE_ALTF);
	MGPIO_voidSetAltFun(MGPIO_PORTB, MGPIO_PIN7,MGPIO_ALTFN_7);
	MGPIO_voidSetPinMode(MGPIO_PORTB, MGPIO_PIN6,MGPIO_MODE_ALTF);
	MGPIO_voidSetAltFun(MGPIO_PORTB, MGPIO_PIN6,MGPIO_ALTFN_7);

	/*
	 * Initialize TIMER2 PIN
	 *  A0 as alternating function 1
	 *  */
	MRCC_voidEnablePeripheral(APB1_BUS, RCC_APB1_TIMER2);
	MGPIO_voidSetPinMode(MGPIO_PORTA, MGPIO_PIN0, MGPIO_MODE_ALTF);
	MGPIO_voidSetAltFun(MGPIO_PORTA, MGPIO_PIN0, MGPIO_ALTFN_1);

}


/**
 * @brief Configures the timer and starts it
 * @return void
 * @param None
 */
void SYS_TimerInit()
{
	/*Set the values you want to configure*/
	Global_uddtTimerNumber = _TIM2;
	Global_u8DutyCycle = 30;
	Global_u16ARR = 9999;
	Global_u16Prescaler = 64;
	Global_uddtMode = PWM_MODE_1;
	Global_uddtChNo = _CHANNEL1;
	Global_u8CruiseControlMode = 20;
	/*Start ACC by timer*/
	ACC_Init(Global_uddtTimerNumber, Global_u16Prescaler, Global_u16ARR, Global_uddtMode, Global_uddtChNo, Global_u8DutyCycle);

}

/**
 * @brief Initializes the UART 1 peripheral
 */
void SYS_USARTInit(void)
{
    UARTvoidInit();
}

/**
 * @brief Initializes the motor
 */
void SYS_MotorInit(void)
{
    HMOTOR_voidInit();
}

/**
 * @brief Function that takes UART input received and handles it depending on the value
 * @param Copy_u8Data
 * @details  	UART options:\n\n
  						1 :	Choose Adaptive Cruise Control Mode \n
  						2 : Choose Normal Cruise Control Mode \n
  						5 : Turn Car off \n

  						0 : Speed 0 in Normal Cruise Control Mode \n
  						3 : Speed 30 in Normal Cruise Control Mode \n
  						6 : Speed 60 in Normal Cruise Control Mode \n
  						9 : Speed 90 in Normal Cruise Control Mode \n
 * @returns void
 */
void SYS_HandleUARTInput(u8 Copy_u8Data)
{
	switch(Copy_u8Data)
	{
		/**/
		case 1:
			Global_u8CruiseControlMode = 30;
			break;
		/* */
		case 2:

			Global_u8CruiseControlMode = 20;
			Global_u8DutyCycle = 30;
			break;
		/* */
		case 5:
			Global_u8CruiseControlMode = 10;
			Global_u8DutyCycle = 30;
			break;
		/* */
		case 0:
			ACC_voidSetSpeed(Global_uddtTimerNumber, Copy_u8Data);
			break;
		/* */
		case 3:
			ACC_voidSetSpeed(Global_uddtTimerNumber, Copy_u8Data);
			break;
		/* */
		case 6:
			ACC_voidSetSpeed(Global_uddtTimerNumber, Copy_u8Data);
			break;
		/* */
		case 9:
			ACC_voidSetSpeed(Global_uddtTimerNumber, Copy_u8Data);
			break;
	}
}

/**
 * @brief Configures a pin as an output
 * @param Copy_u8PortName
 * @param Copy_u8PinNum
 * @return void
 */
void SYS_InitPinAsOutput(u8 Copy_u8PortName , u8 Copy_u8PinNum)
{
	MGPIO_voidSetPinMode(Copy_u8PortName, Copy_u8PinNum, MGPIO_MODE_OUTPUT);
	MGPIO_voidSetOutputMode(Copy_u8PortName, Copy_u8PinNum, MGPIO_OUTPUT_PUSHPULL);
	MGPIO_voidSetSpeed(Copy_u8PortName, Copy_u8PinNum, MGPIO_OUTPUT_SPEED_LOW);
}

/**
 * @brief Sets the given pin as high
 * @param Copy_u8PortName The port the pin is in
 * @param Copy_u8PinNum The pin number
 */
void SYS_SetPinHigh(u8 Copy_u8PortName , u8 Copy_u8PinNum)
{
    MGPIO_voidSetPinValue(Copy_u8PortName, Copy_u8PinNum, MGPIO_HIGH);
}

/**
 * @brief Sets the given pin as low
 * @param Copy_u8PortName The port the pin is in
 * @param Copy_u8PinNum The pin number
 */
void SYS_SetPinLow(u8 Copy_u8PortName , u8 Copy_u8PinNum)
{
    MGPIO_voidSetPinValue(Copy_u8PortName, Copy_u8PinNum, MGPIO_LOW);
}


