/*
 * STK_interface.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Compu Tech
 */

#ifndef MCAL_STK_STK_INTERFACE_H_
#define MCAL_STK_STK_INTERFACE_H_

void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 copy_u32ticks);

void MSTK_voidSetIntervalSingle(u32 copy_u32ticks , void (*copy_ptr)(void));

void MSTK_voidSetIntervalPeriodic(u32 copy_u32ticks , void (*copy_ptr)(void));

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTime(void);


u32 MSTK_u32GetRemainingTime(void);


#endif /* MCAL_STK_STK_INTERFACE_H_ */
