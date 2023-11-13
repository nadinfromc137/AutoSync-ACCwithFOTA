/*
 * STK_program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Compu Tech
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "STK_config.h"
#include "STK_private.h"
#include "STK_interface.h"

static void (*STK_callback)(void)=0;
static u8 flag_single;

/**
 * @brief Starts the
 * @param None
 * @return void
 */
void MSTK_voidInit(void){

	//SET_BIT(STK_REG->STK_CTRL,0);
	SET_BIT(STK_REG->STK_CTRL,1);
	CLR_BIT(STK_REG->STK_CTRL,2);
}

/**
 * @brief Makes the program stop execution for a given number of system ticks
 * @param copy_u32ticks
 */
void MSTK_voidSetBusyWait(u32 copy_u32ticks)
{
	STK_REG->STK_VAL=0;
	STK_REG->STK_LOAD=copy_u32ticks;

	SET_BIT(STK_REG->STK_CTRL,0);
	while(GET_BIT(STK_REG->STK_CTRL,16) != 1);
	CLR_BIT(STK_REG->STK_CTRL,0);
}

/**
 * @brief Sets an asychronus timer interrupt
 * @param copy_u32ticks The number of system ticks to wait to generate the interrupt
 * @param copy_ptr The functin to call every time an interrut is fired
 * @return void
 */
void MSTK_voidSetIntervalSingle(u32 copy_u32ticks , void (*copy_ptr)(void)){

	STK_callback=copy_ptr;
	flag_single=1;
	//CLEAR_BIT(STK_REG->STK_CTRL,0);
	STK_REG->STK_VAL=0;
	STK_REG->STK_LOAD=copy_u32ticks;
	SET_BIT(STK_REG->STK_CTRL,0);

}

/**
 * @brief Creates a periodic interrupt every given number of ticks
 * @param copy_u32ticks The number of system ticks to wait to generate the interrupt
 * @param copy_ptr The functin to call every time an interrut is fired
 */
void MSTK_voidSetIntervalPeriodic(u32 copy_u32ticks , void (*copy_ptr)(void)){
	STK_callback=copy_ptr;
	flag_single=0;
	//CLEAR_BIT(STK_REG->STK_CTRL,0);
	STK_REG->STK_VAL=0;
	STK_REG->STK_LOAD=copy_u32ticks;
	SET_BIT(STK_REG->STK_CTRL,0);

}

/**
 * @brief Stops the periodic timer
 * @param None
 * @return void
 */
void MSTK_voidStopInterval(void){

	CLR_BIT(STK_REG->STK_CTRL,0);

}

/**
 * @brief  Gets the time elapsed since the timer was started
 * @param Gets the time elapsed since the timer was started
 * @return u32
 */
u32 MSTK_u32GetElapsedTime(void){
	return ((STK_REG->STK_LOAD)-(STK_REG->STK_VAL));
}


/**
 * @brief Get the counts remaining in the STK value register
 * @param None
 * @return void
 */
u32 MSTK_u32GetRemainingTime(void){

	return (STK_REG->STK_VAL);
}
/*void MSTK_voidCallBack(void (*ptr)(void)){
	STK_callback=ptr;
}*/

/**
 * @brief Handles the systick interrupt
 * @param None
 * @returns void
 */
void SysticK_Handler(void)
{
	STK_callback();
	if(flag_single)
	{
		MSTK_voidStopInterval();
		STK_REG->STK_VAL=0;
		STK_REG->STK_LOAD=0;
	}
	else
	{

	}
}
