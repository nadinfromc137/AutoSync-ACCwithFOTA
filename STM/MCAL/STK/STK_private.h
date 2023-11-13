
/*
 * STK_private.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Compu Tech
 */

#ifndef MCAL_STK_STK_PRIVATE_H_
#define MCAL_STK_STK_PRIVATE_H_

#define STK_BASE_ADDRESS 0xE000E010

typedef struct
{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;

}STK_R;


#define MSTK_SRC_AHB     0
#define MSTK_SRC_AHB_8   1

#define MSTK_SINGLE_INTERVAL  0
#define MSTK_PERIOD_INTERVAL  1

#define STK_REG ((volatile STK_R*)(STK_BASE_ADDRESS))

#endif /* MCAL_STK_STK_PRIVATE_H_ */
