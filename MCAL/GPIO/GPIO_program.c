/*
 * GPIO_program.c
 *
 *  Created on: Sep 8, 2023
 *      Author: Compu Tech
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GPIO_config.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"


/**
 * @param Sets the pin as one of 4 pin modes: input, output, alternating function, or analogue modes.
 * @param Copy_u8PortName The port to set the pin in as. We have a choice of 3 registers: GPIO A, GPIO B, GPIO C.
 * @param Copy_u8PinNum The pin in the port to set. We have a choice between 16 pins for GPIO A, 16 pins for GPIO B, and 3 pins for GPIO C.
 * @param Copy_u8Mode The mode we want to set the pin as: input, output, alternating function, or analogue mode.
 * @return void
 */
void MGPIO_voidSetPinMode (u8 Copy_u8PortName , u8 Copy_u8PinNum , u8 Copy_u8Mode)
{
	if(Copy_u8PinNum < 16)
	{
       switch(Copy_u8PortName)
          {
                case MGPIO_PORTA:

                	MGPIOA->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum)) ;  break;
                case MGPIO_PORTB:
                	MGPIOB->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum)) ;  break;
                case MGPIO_PORTC:
                	MGPIOC->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum)) ;  break;
                case MGPIO_PORTD: MGPIOD->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum)) ;  break;
                case MGPIO_PORTE: MGPIOE->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum)) ;  break;
                case MGPIO_PORTH: MGPIOH->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum)) ;  break;
                default: break;

          }
    }
	else
	{

	}
}

/**
 * @param Sets all the pins for a GPIO as one of 4 pin modes: input, output, alternating function, or analogue modes.
 * @param Copy_u8PortName The port to set the pin in as. We have a choice of 3 registers: GPIO A, GPIO B, GPIO C.
 * @param Copy_u32Mode The mode we want to set the pin as: input, output, alternating function, or analogue mode.
 * @return void
 */
void MGPIO_voidSetPortMode (u8 Copy_u8PortName , u32 Copy_u32Mode)
{

	if(Copy_u32Mode == MGPIO_MODE_INPUT)
	{ switch(Copy_u8PortName)
	{
		case MGPIO_PORTA: MGPIOA->MODER = 0b00000000000000000000000000000000;break;
		case MGPIO_PORTB: MGPIOB->MODER = 0b00000000000000000000000000000000;break;
		case MGPIO_PORTC: MGPIOC->MODER = 0b00000000000000000000000000000000;break;
	}
	}
	else if(Copy_u32Mode == MGPIO_MODE_OUTPUT)
	{
		switch(Copy_u8PortName){
		case MGPIO_PORTA: MGPIOA->MODER = 0b01010101010101010101010101010101;break;
		case MGPIO_PORTB: MGPIOB->MODER = 0b01010101010101010101010101010101;break;
		case MGPIO_PORTC: MGPIOC->MODER = 0b01010101010101010101010101010101;break;
		default : break;
		}
	}
	else if(Copy_u32Mode == MGPIO_MODE_ALTF)
	{switch(Copy_u8PortName){
		case MGPIO_PORTA: MGPIOA->MODER = 0b10101010101010101010101010101010;break;
		case MGPIO_PORTB: MGPIOB->MODER = 0b10101010101010101010101010101010;break;
		case MGPIO_PORTC: MGPIOC->MODER = 0b10101010101010101010101010101010;break;
		default : break;
	}
	}
	else if(Copy_u32Mode == MGPIO_MODE_ANALOG)
	{switch(Copy_u8PortName){
		case MGPIO_PORTA: MGPIOA->MODER = 0b11111111111111111111111111111111;break;
		case MGPIO_PORTB: MGPIOB->MODER = 0b11111111111111111111111111111111;break;
		case MGPIO_PORTC: MGPIOC->MODER = 0b11111111111111111111111111111111;break;
		default : break;
	}
	}
}

/**
 * @brief Sets the output pin as one of 2 modes:  push-pull or open-drain.
 * @param copy_u8PortName The port to set the pin in as. We have a choice of 3 registers: GPIO A, GPIO B, GPIO C.
 * @param copy_u8PinNum The pin in the port to set. We have a choice between 16 pins for GPIO A, 16 pins for GPIO B, and 3 pins for GPIO C.
 * @param Copy_u8OutputMode
 * @return void
 */
void MGPIO_voidSetOutputMode (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8OutputMode )
{

	if(copy_u8PinNum < 16)
	{
       switch(copy_u8PortName)
          {
       case MGPIO_PORTA: MGPIOA->OTYPER |= (u32)(Copy_u8OutputMode << ( copy_u8PinNum)) ;  break;
       case MGPIO_PORTB: MGPIOB->OTYPER |= (u32)(Copy_u8OutputMode << ( copy_u8PinNum)) ;  break;
       case MGPIO_PORTC: MGPIOC->OTYPER |= (u32)(Copy_u8OutputMode << ( copy_u8PinNum)) ;  break;
       default:break;
          }
    }
	else
	{

	}

}

/**
 * @brief Sets the speed of the output pin as one of 4 speeds: Low, Medium, High, and Very High.  The typical frequency range for the Low Speed option is around 2 MHz to 12 MHz. The typical frequency range for the Medium Speed option is around 12 MHz to 50 MHz.The typical frequency range for the High Speed option is around 25 MHz to 100 MHz. The typical frequency range for the Very High Speed option is around 50 MHz to 150 MHz.
 * @param copy_u8PortName The port to set the pin in as. We have a choice of 3 registers: GPIO A, GPIO B, GPIO C.
 * @param copy_u8PinNum The pin in the port to set. We have a choice between 16 pins for GPIO A, 16 pins for GPIO B, and 3 pins for GPIO C.
 * @param Copy_u8OutputSpeed The speed chosen, whether Low, Medium, High or Low.
 * @return None
 */
void MGPIO_voidSetSpeed  (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8OutputSpeed )
{
	if(copy_u8PinNum<16)
	{
		switch (copy_u8PortName)
		{
			case MGPIO_PORTA  :  MGPIOA->OSPEEDR |= (u32)(Copy_u8OutputSpeed << ( 2U * copy_u8PinNum)) ;  break;

			case MGPIO_PORTB  :  MGPIOB->OSPEEDR |= (u32)(Copy_u8OutputSpeed << ( 2U * copy_u8PinNum)) ;  break;

			case MGPIO_PORTC  :  MGPIOC->OSPEEDR |= (u32)(Copy_u8OutputSpeed << ( 2U * copy_u8PinNum)) ;  break;

			default : break;
		}
	}
	else
	{

	}

}
/**
 * @brief Set the pull state for the input pins, and sets it as: float, or up, or down.
 * @param copy_u8PortName The port to set the pin in as. We have a choice of 3 registers: GPIO A, GPIO B, GPIO C.
 * @param copy_u8PinNum The pin in the port to set. We have a choice between 16 pins for GPIO A, 16 pins for GPIO B, and 3 pins for GPIO C.
 * @param Copy_u8PullState Takes one of 3 values: MGPIO_PULL_FLOAT, MGPIO_PULL_UP, MGPIO_PULL_DOWN.
 */
void MGPIO_voidSetPullState  (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8PullState )
{
	if(copy_u8PinNum<16)
	{
		switch (copy_u8PortName)
		{
			case MGPIO_PORTA  :  MGPIOA->PUPDR |= (u32)(Copy_u8PullState << ( 2U * copy_u8PinNum)) ;  break;

			case MGPIO_PORTB  :  MGPIOB->PUPDR |= (u32)(Copy_u8PullState << ( 2U * copy_u8PinNum)) ;  break;

			case MGPIO_PORTC  :  MGPIOC->PUPDR |= (u32)(Copy_u8PullState << ( 2U * copy_u8PinNum)) ;  break;
			default : break;
		}
	}
	else
	{

	}
}

u8 MGPIO_u8GetPinValue  (u8 copy_u8PortName , u8 copy_u8PinNum )
{
	u8 L_u8PinValue = 0;

	switch (copy_u8PortName)
	{
		case MGPIO_PORTA  :  L_u8PinValue = GET_BIT(MGPIOA->IDR , copy_u8PinNum ) ;  break;

		case MGPIO_PORTB  :  L_u8PinValue = GET_BIT(MGPIOB->IDR , copy_u8PinNum ) ;  break;

		case MGPIO_PORTC  :  L_u8PinValue = GET_BIT(MGPIOC->IDR , copy_u8PinNum ) ;  break;

		default : break;
	}

	return L_u8PinValue;
}

void MGPIO_voidSetPinValue  (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8Pinval )
{
	if(copy_u8PinNum<16)
	{
		if(Copy_u8Pinval == MGPIO_HIGH)
		{

			switch(copy_u8PortName)
			{
			case MGPIO_PORTA: SET_BIT(MGPIOA->ODR,copy_u8PinNum);break;
			case MGPIO_PORTB: SET_BIT(MGPIOB->ODR,copy_u8PinNum);break;
			case MGPIO_PORTC: SET_BIT(MGPIOC->ODR,copy_u8PinNum);break;
			default:break;
			}
		}
		else if(Copy_u8Pinval == MGPIO_LOW)
		{
			switch(copy_u8PortName)
					{
					case MGPIO_PORTA: CLR_BIT(MGPIOA->ODR,copy_u8PinNum);break;
					case MGPIO_PORTB: CLR_BIT(MGPIOB->ODR,copy_u8PinNum);break;
					case MGPIO_PORTC: CLR_BIT(MGPIOC->ODR,copy_u8PinNum);break;
					default:break;
					}

		}

	}
	else
	{

	}
}


void MGPIO_voidDirectSetReset (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8SetResetState )
{
	if(copy_u8PinNum<16)
		{
			if(Copy_u8SetResetState == MGPIO_HIGH)
			{

				switch(copy_u8PortName)
				{
				case MGPIO_PORTA: (u32)(MGPIOA->BSRR = (1U << copy_u8PinNum ));break;
				case MGPIO_PORTB: (u32)(MGPIOB->BSRR = (1U << copy_u8PinNum ));break;
				case MGPIO_PORTC: (u32)(MGPIOC->BSRR = (1U << copy_u8PinNum ));break;
				default:break;
				}
			}
			else if(Copy_u8SetResetState == MGPIO_LOW)
			{ copy_u8PinNum+=16;
				switch(copy_u8PortName)
						{
				            case MGPIO_PORTA: (u32)(MGPIOA->BSRR = (1U << copy_u8PinNum ));break;
							case MGPIO_PORTB: (u32)(MGPIOB->BSRR = (1U << copy_u8PinNum ));break;
							case MGPIO_PORTC: (u32)(MGPIOC->BSRR = (1U << copy_u8PinNum ));break;
						default:break;
						}

			}

		}
		else
		{

		}
}


void MGPIO_voidSetPortVal (u8 copy_u8PortName , u32 Copy_u32OutputVal)
{

		switch (copy_u8PortName)
		{
			case MGPIO_PORTA : MGPIOA -> ODR =  Copy_u32OutputVal ;  break ;

			case MGPIO_PORTB : MGPIOB -> ODR = Copy_u32OutputVal ;   break ;
		}

}

void MGPIO_voidPinLock(u8 copy_u8PortName, u8 copy_u8PinNum)
{
    if (copy_u8PinNum < 16)
    {
        switch (copy_u8PortName)
        {
            case MGPIO_PORTA:
                MGPIOA->LCKR = (1U << copy_u8PinNum) | (1U << 16);  // Set the bit corresponding to the pin and enable the lock key
                MGPIOA->LCKR = (1U << copy_u8PinNum);  // Reset the lock key
                MGPIOA->LCKR = (1U << copy_u8PinNum) | (1U << 16);  // Set the lock key again
                volatile u32 dummy1 = MGPIOA->LCKR;  // Read the lock key to finalize the lock
                break;

            case MGPIO_PORTB:
                MGPIOB->LCKR = (1U << copy_u8PinNum) | (1U << 16);
                MGPIOB->LCKR = (1U << copy_u8PinNum);
                MGPIOB->LCKR = (1U << copy_u8PinNum) | (1U << 16);
                volatile u32 dummy2 = MGPIOB->LCKR;
                break;

            case MGPIO_PORTC:
                MGPIOC->LCKR = (1U << copy_u8PinNum) | (1U << 16);
                MGPIOC->LCKR = (1U << copy_u8PinNum);
                MGPIOC->LCKR = (1U << copy_u8PinNum) | (1U << 16);
                volatile u32 dummy3 = MGPIOC->LCKR;
                break;
        }
    }
    else
    {
        // Handle the case when copy_u8PinNum is greater than or equal to 16
    }
}
void MGPIO_voidSetAltFun (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8AltFun )
{


	if(copy_u8PinNum<16)
	{
		if(copy_u8PinNum<=7)
		{
		switch(copy_u8PortName)
		{

		case MGPIO_PORTA: MGPIOA->AFRL |= (Copy_u8AltFun)<<(4*copy_u8PinNum);break;
		case MGPIO_PORTB: MGPIOB->AFRL |= (Copy_u8AltFun)<<(4*copy_u8PinNum);break;
		case MGPIO_PORTC: MGPIOC->AFRL |= (Copy_u8AltFun)<<(4*copy_u8PinNum);break;
		default:break;

		}
		}
		else if(copy_u8PinNum<= 15U)
		{
			switch(copy_u8PortName)
			{

			case MGPIO_PORTA: MGPIOA->AFRH |= (Copy_u8AltFun)<<(4*copy_u8PinNum);break;
			case MGPIO_PORTB: MGPIOB->AFRH |= (Copy_u8AltFun)<<(4*copy_u8PinNum);break;
			case MGPIO_PORTC: MGPIOC->AFRH |= (Copy_u8AltFun)<<(4*copy_u8PinNum);break;
			default:break;

			}
		}
	}
	else
	{

	}
}

