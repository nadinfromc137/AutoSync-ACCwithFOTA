/*
 * GPIO_interface.h
 *
 *  Created on: Sep 8, 2023
 *      Author: Compu Tech
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/*port macros*/

#define MGPIO_PORTA 0U
#define MGPIO_PORTB 1U
#define MGPIO_PORTC 2U
#define MGPIO_PORTD 3U
#define MGPIO_PORTE 4U
#define MGPIO_PORTH 5U

/*pin macros*/

#define MGPIO_PIN0  0U
#define MGPIO_PIN1  1U
#define MGPIO_PIN2  2U
#define MGPIO_PIN3  3U
#define MGPIO_PIN4  4U
#define MGPIO_PIN5  5U
#define MGPIO_PIN6  6U
#define MGPIO_PIN7  7U
#define MGPIO_PIN8  8U
#define MGPIO_PIN9  9U
#define MGPIO_PIN10 10U
#define MGPIO_PIN11 11U
#define MGPIO_PIN12 12U
#define MGPIO_PIN13 13U
#define MGPIO_PIN14 14U
#define MGPIO_PIN15 15U

/*mode macros*/

#define		MGPIO_MODE_INPUT	0b00
#define		MGPIO_MODE_OUTPUT	0b01
#define		MGPIO_MODE_ALTF		0b10
#define		MGPIO_MODE_ANALOG	0b11

/*speed macros*/
#define		MGPIO_OUTPUT_SPEED_LOW			(0b00)
#define		MGPIO_OUTPUT_SPEED_MEDIUM		(0b01)
#define		MGPIO_OUTPUT_SPEED_HIGH			(0b10)
#define		MGPIO_OUTPUT_SPEED_VERYHIGH		(0b11)


/*pull up / pull down macros*/

#define		MGPIO_PULL_FLOATING				(0b00)
#define		MGPIO_PULL_UP					(0b01)
#define		MGPIO_PULL_DOWN					(0b10)


/*types macros*/
#define		MGPIO_OUTPUT_PUSHPULL		0U
#define		MGPIO_OUTPUT_OPEN_DRAIN		1U

/*write macros*/
#define MGPIO_HIGH 1U
#define MGPIO_LOW 0U

/*alternate functions macros*/

#define MGPIO_ALTFN_0                          (0b0000)
#define MGPIO_ALTFN_1                          (0b0001)
#define MGPIO_ALTFN_2                          (0b0010)
#define MGPIO_ALTFN_3                          (0b0011)
#define MGPIO_ALTFN_4                          (0b0100)
#define MGPIO_ALTFN_5                          (0b0101)
#define MGPIO_ALTFN_6                          (0b0110)
#define MGPIO_ALTFN_7                          (0b0111)
#define MGPIO_ALTFN_8                          (0b1000)
#define MGPIO_ALTFN_9                          (0b1001)
#define MGPIO_ALTFN_10                         (0b1010)
#define MGPIO_ALTFN_11                         (0b1011)
#define MGPIO_ALTFN_12                         (0b1100)
#define MGPIO_ALTFN_13                         (0b1101)
#define MGPIO_ALTFN_14                         (0b1110)
#define MGPIO_ALTFN_15                         (0b1111)

/*function prototypes*/
/***************************01-MGPIO_voidSetPinMode*************************************/
/*	1-  function Description : sets the pin mode
	2-  Options : (A) MGPIO_OUTPUT_MODE
				  (B) MGPIO_INPUT_MODE
				  (C) MGPIO_ALT_FUNCTION_MODE
				  (D) MGPIO_ANALOG_MODE

	3- Function Arguments : (A)  Copy_u8PortName  : The port Number (ex : MGPIO_PORT_A, MGPIO_PORT_B)
							(B)	 Copy_u8PinNum    : The Pin Number (ex : GPIO_PIN_0 , GPIO_PIN_1)
							(C)  Copy_u8Mode      : The Mode (ex : MGPIO_OUTPUT_MODE)

	4- Function Return   :  void

 */
void MGPIO_voidSetPinMode (u8 Copy_u8PortName , u8 Copy_u8PinNum , u8 Copy_u8Mode);







/*******************************************************************************************************/
/*                                      02- MGPIO_voidSetOutputMode
 *                                   */
/*	1-  function Description : sets the  output mode of the pin
	2-  Options : A- MGPIO_OUTPUT_TYPE_PUSH_PULL
                  B-  MGPIO_OUTPUT_TYPE_OPEN_DRAIN

	3- Function Arguments : (A)  Copy_u8PortName  : The port Number (ex : MGPIO_PORT_A, MGPIO_PORT_B)
							(B)	 Copy_u8PinNum    : The Pin Number (ex : GPIO_PIN_0 , GPIO_PIN_1)
							(C)  Copy_u8OutputMode      : The Mode (ex : MGPIO_OUTPUT_TYPE_OPEN_DRAIN)

	4- Function Return   :  void

 */
/*******************************************************************************************************/

void MGPIO_voidSetOutputMode (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8OutputMode );



/*******************************************************************************************************/
/*                                      03- MGPIO_voidSetOutputSpeed                                   */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description : sets the output speed of the pin                  */
/*                                                                                                     */
/*      1-  MGPIO_LOW_SPEED   		  8 MHZ                                                                    */
/*      2-  MGPIO_MEDUIM_SPEED 	  50 MHZ                                                                   */
/*      3-  MGPIO_HIGH_SPEED    	  80 MHZ                                                                   */
/*      4-  MGPIO_VERY_HIGH_SPEED	  180 MHZ                                                                  */
/*																								       */
/*                                                                                                     */
/* 2- Function Input       : Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8OutputSpeed                 */
/* 3- Function Return      : void                                                                     */
/*******************************************************************************************************/

void MGPIO_voidSetSpeed  (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8OutputSpeed );



/*******************************************************************************************************/
/*                                      04- MGPIO_voidSetPullState                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> sets the resistor connection of the pin            */
/*                                                                                                     */
/*      1-  MGPIO_PULL_FLOAT                                                                                  */
/*      2-  MGPIO_PULL_UP                                                                                     */
/*      3-  MGPIO_PULL_DOWN                                                                                   */
/*      4- RESERVED                                                                                    */
/* 2- Function Input       : Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8PullState                   */
/* 3- Function Return     : void                                                                     */
/*******************************************************************************************************/

void MGPIO_voidSetPullState  (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8PullState );



/*******************************************************************************************************/
/*                                      05- MGPIO_u8GetPinVal                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->  Reads the Data from IDR Register                                     */
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum                                        */
/* 3- Function Return      -> u8 PinValue                                                              */
/*******************************************************************************************************/

u8 MGPIO_u8GetPinValue  (u8 copy_u8PortName , u8 copy_u8PinNum );




/*******************************************************************************************************/
/*                                      06- MGPIO_voidSetPinVal                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->  Sets the Pin Value At  ODR Register                                  */
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8Pinval                       */
/* 3- Function Return      -> void
 * 4- options               -> A) MGPIO_HIGH
 *                             B) MPGIO_LOW                                                                  */
/*******************************************************************************************************/

void MGPIO_voidSetPinValue  (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8Pinval );



/*******************************************************************************************************/
/*                                      07- MGPIO_voidDirectSetReset                                   */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->  Sets or Resets  the corresponding Pin Value At  BSRR Register*/
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8SetResetState                */
/* 3- Function Return      -> void                                                                     */
/*******************************************************************************************************/

void MGPIO_voidDirectSetReset (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8SetResetState );





/*******************************************************************************************************/
/*                                      08- MGPIO_voidSetPortVal                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->  Sets Port Value At  ODR Register                                 */
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName  , u32 Copy_u32OutputVal                                         */
/* 3- Function Return      -> void                                                                     */
/*******************************************************************************************************/

void MGPIO_voidSetPortVal (u8 copy_u8PortName , u32 Copy_u32OutputVal);


/*******************************************************************************************************/
/*                                      09- MGPIO_voidPinLock                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Lock At pin :                                                   */
/*                               1 - Set PIN                                                           */
/*                               2 - Set PIN 16                                                        */
/*                               3 - Clr PIN 16                                                        */
/*                               4 - Set PIN 16                                                        */
/*                               5 - wait bit 16 = High                                                */
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum                                        */
/* 3- Function Return      -> void                                                                     */
/*******************************************************************************************************/

void MGPIO_voidPinLock (u8 copy_u8PortName , u8 copy_u8PinNum ); // TODO





/*******************************************************************************************************/
/*                                      10- MGPIO_voidSetPinAltFun                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description ->  Sets pin Alternative :                                           */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8AltFun                       */
/* 3- Function Return      -> void
 * 4- options              ->   MGPIO_ALTFN_0 etc..                                                                */
/*******************************************************************************************************/

void MGPIO_voidSetAltFun (u8 copy_u8PortName , u8 copy_u8PinNum , u8 Copy_u8AltFun );




/*
 **************************************************************************************************************************
 ***************************************** 11 - MGPIO_voidSetPortMode  ****************************************************

	1-  function Description ->   Sets the mode of the Port
    2-  Options : (A) MGPIO_OUTPUT_MODE
				  (B) MGPIO_INPUT_MODE
				  (C) MGPIO_ALT_FUNCTION_MODE
				  (D) MGPIO_ANALOG_MODE

	3- Function Arguments : (A)  Copy_u8PortName  : The port
							(B)  u32 Copy_u32Mode      : The Mode

	4- Function Return   ->  void

 **************************************************************************************************************************
 **************************************************************************************************************************
 */


void MGPIO_voidSetPortMode (u8 Copy_u8PortName , u32 Copy_u32Mode);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
