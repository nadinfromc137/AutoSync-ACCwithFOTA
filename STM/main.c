/*
 * File:	   		main.c
 * Author:     		Nadin Magdy
 * Created on: 		Oct 10, 2023
 * Version:    		1.0.0
 * Microcontroller: STM32F401CCU6
 *
 */

/*
 ****************************************************************************************************
									 Library Includes
 ****************************************************************************************************
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

 /*
 ****************************************************************************************************
									 Interface Includes
 ****************************************************************************************************
*/
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/STK/STK_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/TIM/TIM_Interface.h"
#include "HAL/MOTOR/Motor_Interface.h"
#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "SERVICE/ACC/ACC.h"
#include "SERVICE/SYSTEM/SYS.h"

 /*
 ****************************************************************************************************
									 Global Variables
 ****************************************************************************************************
*/
extern u8 data;
extern TMRn_t Global_uddtTimerNumber;
extern u8  Global_u8DutyCycle;
extern u16 Global_u16ARR;
extern u16 Global_u16Prescaler;
extern u8 Global_u8data;
extern MODEn_t Global_uddtMode;
extern CHANNELn_t Global_uddtChNo;
extern u8 Global_u8ACCMode;
extern u8 Global_u8CruiseControlMode;

/*
****************************************************************************************************
									 Main Function
****************************************************************************************************
*/
int main()
{

	SYS_Init();
	SYS_TimerInit();
	HMOTOR_voidInit();

	////////////////////////////////// Pins for signaling
	///
	///
	/*
	SYS_InitPinAsOutput(MGPIO_PORTA , MGPIO_PIN1);
	SYS_InitPinAsOutput(MGPIO_PORTA , MGPIO_PIN2);
	SYS_InitPinAsOutput(MGPIO_PORTA , MGPIO_PIN3);
	SYS_InitPinAsOutput(MGPIO_PORTA , MGPIO_PIN4);
	*/

    //UARTvoidInit();
	SYS_USARTInit();
	HULTRASONIC_voidInit();
    data = 0;

    ///
    ///
    SYS_InitPinAsOutput(MGPIO_PORTA, MGPIO_PIN8);

    while (1)
    {
        //data2 = MUSART_u8ReceiveByteAsynch_(dataptr);
    	data=MUART_u8ReceiveByteSynchNonBlocking();
    	UARTvoidTransmit(data);
    	SYS_HandleUARTInput(data);

    	if( 30 == Global_u8CruiseControlMode )
    	{
    		ACC_AdaptiveSpeedControl();
    	}

    	if(20 == Global_u8CruiseControlMode)
    	{
    		f32 dist = HULTRASONIC_f32GetDistance();
    		if(dist < 8.00)
    		{
    			MGPIO_voidSetPinValue(MGPIO_PORTA, MGPIO_PIN8, MGPIO_HIGH);
    			ACC_voidStopCar();
    		}
    		else
    		{

    		}
    	}



    }

    return 0;
}
