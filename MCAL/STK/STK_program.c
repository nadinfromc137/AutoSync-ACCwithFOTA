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
void MSTK_voidInit(void){

	//SET_BIT(STK_REG->STK_CTRL,0);
	SET_BIT(STK_REG->STK_CTRL,1);
	CLR_BIT(STK_REG->STK_CTRL,2);
}

void MSTK_voidSetBusyWait(u32 copy_u32ticks)
{ STK_REG->STK_VAL=0;
STK_REG->STK_LOAD=copy_u32ticks;

SET_BIT(STK_REG->STK_CTRL,0);
while(GET_BIT(STK_REG->STK_CTRL,16) != 1);
CLR_BIT(STK_REG->STK_CTRL,0);
}
void MSTK_voidSetIntervalSingle(u32 copy_u32ticks , void (*copy_ptr)(void)){

	STK_callback=copy_ptr;
	flag_single=1;
	//CLEAR_BIT(STK_REG->STK_CTRL,0);
	STK_REG->STK_VAL=0;
	STK_REG->STK_LOAD=copy_u32ticks;
	SET_BIT(STK_REG->STK_CTRL,0);

}

void MSTK_voidSetIntervalPeriodic(u32 copy_u32ticks , void (*copy_ptr)(void)){
	STK_callback=copy_ptr;
	flag_single=0;
	//CLEAR_BIT(STK_REG->STK_CTRL,0);
	STK_REG->STK_VAL=0;
	STK_REG->STK_LOAD=copy_u32ticks;
	SET_BIT(STK_REG->STK_CTRL,0);

}

void MSTK_voidStopInterval(void){

	CLR_BIT(STK_REG->STK_CTRL,0);

}

u32 MSTK_u32GetElapsedTime(void){
	return ((STK_REG->STK_LOAD)-(STK_REG->STK_VAL));
}


u32 MSTK_u32GetRemainingTime(void){

	return (STK_REG->STK_VAL);
}
/*void MSTK_voidCallBack(void (*ptr)(void)){
	STK_callback=ptr;
}*/

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
