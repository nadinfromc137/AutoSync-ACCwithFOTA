/*
 * File:	   RCC_Program.c
 * Author:     Nadin Magdy
 * Created on: Sep 10, 2023
 * Version:    1.0.0
 *
 */
/*****************************************************************************************************
									 Library Includes
 ****************************************************************************************************/
#include		"../../LIB/STD_TYPES.h"
#include		"../../LIB/BIT_MATH.h"

/*****************************************************************************************************
									 RCC Includes
 ****************************************************************************************************/
#include		"RCC_Interface.h"
#include		"RCC_Configuration.h"
#include		"RCC_Private.h"


/*****************************************************************************************************
									 RCC Function Implementations
 ****************************************************************************************************/
/**
 * @brief Starts the clock system of the microcontroller
 */
void	MRCC_voidInit(void)
{
	#if		MRCC_CLK == MRCC_HSI_CLK
		CLR_BIT(RCC_REG->RCC_CFGR, 0);
		CLR_BIT(RCC_REG->RCC_CFGR, 1);
		SET_BIT(RCC_REG->RCC_CR, 0);
	#elif	MRCC_CLK == MRCC_HSE_CLK
		SET_BIT(RCC_REG->RCC_CFGR, 0);
		CLR_BIT(RCC_REG->RCC_CFGR, 1);
		SET_BIT(RCC_REG->RCC_CR, 16);
	#elif CLOCK_TYPE == MRCC_PLL_CLK
		SET_BIT(RCC_REG->RCC_CR, 24);
		SET_BIT(RCC_REG->RCC_CFGR,1);
		CLR_BIT(RCC_REG->RCC_CFGR,0);

	#endif
	RCC_REG->RCC_CFGR = ((RCC_REG->RCC_CFGR & 0xFFFF030F)|(8U << 4U)|(0U << 10U)|(0U << 13U));
}

/**
 * @brief Enables the given peripheral depending on the bus architecture - it is connected to which of the 4 buses
 * @param Copy_u8PeripheralBus
 * @param Copy_u8PeripheralNum
 */
void	MRCC_voidEnablePeripheral(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralNum)
{
	switch(Copy_u8PeripheralBus)
	{
		case AHB1_BUS: SET_BIT(RCC_REG->RCC_AHB1ENR, Copy_u8PeripheralNum); break;
		case AHB2_BUS: SET_BIT(RCC_REG->RCC_AHB2ENR, Copy_u8PeripheralNum); break;
		case APB1_BUS: SET_BIT(RCC_REG->RCC_APB1ENR, Copy_u8PeripheralNum); break;
		case APB2_BUS: SET_BIT(RCC_REG->RCC_APB2ENR, Copy_u8PeripheralNum); break;
	}
}

/**
 * @brief Disbales the given peripheral depending on the bus architecture - it is connected to which of the 4 buses
 * @param Copy_u8PeripheralBus
 * @param Copy_u8PeripheralNum
 */
void	MRCC_voidDisablePeripheral(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralNum)
{
	switch(Copy_u8PeripheralBus)
	{
		case AHB1_BUS: CLR_BIT(RCC_REG->RCC_AHB1ENR, Copy_u8PeripheralNum); break;
		case AHB2_BUS: CLR_BIT(RCC_REG->RCC_AHB2ENR, Copy_u8PeripheralNum); break;
		case APB1_BUS: CLR_BIT(RCC_REG->RCC_APB1ENR, Copy_u8PeripheralNum); break;
		case APB2_BUS: CLR_BIT(RCC_REG->RCC_APB2ENR, Copy_u8PeripheralNum); break;
	}
}
