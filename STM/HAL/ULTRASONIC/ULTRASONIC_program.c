/*
 * ULTRASONIC_program.c
 *
 *  Created on: Nov 1, 2023
 *      Author: Compu Tech
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include	"../../MCAL/GPIO/GPIO_Interface.h"
#include 	"../../MCAL/STK/STK_interface.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_interface.h"

/**
 * @brief Function that initializes Ultrasonic pins, which are the trigger pins and the echo pin. The trigger pin is set as output anf the echo pin is set as an input.
 * @param None
 * @return void
 */
void HULTRASONIC_voidInit(void)
{

	MGPIO_voidSetPinMode(TRIG_PORT, TRIG_PIN, MGPIO_MODE_OUTPUT);  //for TRIG_PIN  --> output
	MGPIO_voidSetOutputMode(TRIG_PORT,TRIG_PIN, MGPIO_OUTPUT_PUSHPULL);
	MGPIO_voidSetSpeed(TRIG_PORT,TRIG_PIN, MGPIO_OUTPUT_SPEED_HIGH);

	MGPIO_voidSetPinMode(ECHO_PORT,ECHO_PIN,MGPIO_MODE_INPUT);  //for echo pin  --> input
	MGPIO_voidSetPullState(ECHO_PORT,ECHO_PIN, MGPIO_PULL_DOWN);
}


/**
 * @brief This function generates the sequece of steps to make the ultrasonic works. It sets the trigger pin as low for 3 microseconds, then high for 10 microseconds, then low again for 250 microseconds. During the 250 microseconds 8 pulses of frequence 40KHz are generated. We wait while the echo pin is low, then when it is read as high, we count the time ticks for it to be recevied high. Then we use this number to calculate the distance between us and the object, by an equation that multiples the disatbnce by the speed of sound. This distance is then divided by two as this is the total time for the wave pulses to go from the Ultrasonic sensor and back. The distance is then returned as a float number
 * @param None
 * @return f32
 */
f32 HULTRASONIC_f32GetDistance(void)
{

	u32 L_u32Ticks = 0;
	f32 L_f32Distance= 0.0;
	f32 L_f32IterationNum=4.9;
	//trig pulse to trigger pin low (3 micro)  high (10 micro) low

	MGPIO_voidSetPinValue(TRIG_PORT,TRIG_PIN,MGPIO_LOW);
	MSTK_voidSetBusyWait(3);
	MGPIO_voidSetPinValue(TRIG_PORT,TRIG_PIN,MGPIO_HIGH);
	MSTK_voidSetBusyWait(10) ;
	MGPIO_voidSetPinValue(TRIG_PORT,TRIG_PIN, MGPIO_LOW);

	//wait for the generation of 8 pusles of 40KHZ
	MSTK_voidSetBusyWait(250) ;

	//wait until ECHO pin is high
	while (MGPIO_u8GetPinValue(ECHO_PORT, ECHO_PIN) == 0);
	while (MGPIO_u8GetPinValue(ECHO_PORT, ECHO_PIN) == 1)
	{

		L_u32Ticks++;
		MSTK_voidSetBusyWait(2) ;
	}
	L_f32Distance = (L_u32Ticks + 0.0f)*L_f32IterationNum*0.0343 ;
	L_f32Distance = L_f32Distance / 2 ;


	L_u32Ticks=0 ;
	return L_f32Distance ;
}
