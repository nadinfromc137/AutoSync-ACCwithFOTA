#include "LIB/BIT1_MATH.h"
#include "LIB/STD_LIB.h"

#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "MCAL/SYSTICK/SYSTICK_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "HAL/TFT/TFT_Interface.h"
#include "HAL/TFT/IMG.h"
#include "HAL/STP/STP_Interface.h"
#include "MCAL/FLASH_REG/FDI_Interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "SERVICE/PARSINGHEX_Interface.h"

//Global variables
 u8 TimeOut=0;
 u8 ReceiverBuffer[100];
 u8 ReceiverCounter=0;
 u8 WriteRequest=1;
 u8 Counter=1;

typedef void (*Call_Application) (void);
Call_Application Add_Call=0;
#define SCB_VTOR       *((volatile u32*) (0xE000ED08+0x08))
/*
 * @brief moves sector table to sector 1,sets startup code for application then jumps to application
 * @param None
 * @return void
 */
void App_voidTest(void){

	TimeOut=1;
	//Move Vector Table
	SCB_VTOR = 0x08004000 ; //Starting of Sector 1 [Application]
	//Set Address to call with Reset Handeler_ISR [startup code of Application]
	Add_Call = *(Call_Application*) 0x08004004;//startup code for APP
	Add_Call();//jump Reset handler [startup code]

}

int main(){

 u8 Receivestatus=0;
 //Enable RCC clock
 RCC_voidInit();
 //Enable GPIO periphral clock for portA & portB
 RCC_voidEnablePeripheral(AHP1_BUS,MGPIOB_PORT);
 RCC_voidEnablePeripheral(AHP1_BUS,MGPIOA_PORT);
 //Enable UART1
 RCC_voidEnablePeripheral(APB2_BUS,4);
 // Enable FDI peripheral clock
 RCC_voidEnablePeripheral(RCC_AHB1LP,RCC_EN_FDI);
 //testing
 MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN0,MGPIO_MODE_OUTPUT);
 MGPIO_voidSetOutputMode(MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_TYPE_PUSHPULL);
 MGPIO_voidSetOutputSpeed(MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_SPEED_LOW);
 // Set Pin Mode For Pins 6 , 7 -> Alternative Function
 MGPIO_voidSetPinMode(MGPIOB_PORT,MGPIO_PIN6,MGPIO_MODE_ALTF); //TX
 MGPIO_voidSetPinMode(MGPIOB_PORT,MGPIO_PIN7,MGPIO_MODE_ALTF); //RX
 MGPIO_voidSetALF(MGPIOB_PORT,MGPIO_PIN6,MGPIO_ALTFN7);
 MGPIO_voidSetALF(MGPIOB_PORT,MGPIO_PIN7,MGPIO_ALTFN7);
//MUSART Initialization
 UART_voidInit();
 //MUSART Enable
 UART_voidEnable();
 //Systick Initialization
 MSTK_voidInit();
 //waiting for bootloader request
 while(Counter){
    if(UART_u8ReceiveData()==4){
	break;
    }else if(UART_u8ReceiveData()!=4){
    	MSTK_voidBusyWait(20000000);
    	Counter++;
    	if(Counter==15){
    		App_voidTest();
    	}
    }
 }

 UART_voidSendByte((u8*)"k",1);

while(TimeOut==0){
	//Read the data from UART1
	Receivestatus=UART_voidReceiveSynch(&ReceiverBuffer[ReceiverCounter]);


	if(Receivestatus==1){
		//Stop Timer Because Application code in processing
		MSTK_voidStopInterval();
		//indicate the end of the one record
		if(ReceiverBuffer[ReceiverCounter] == '\n')
		{
		if(WriteRequest==1){ // enter only one time
			//Erase the Application Code
			MFDI_voidEraseApp();
			WriteRequest=0;
		}
		//Parse the Record and write it on the flash
		HEX_voidParseRecord(ReceiverBuffer);
		//send 'ok' as Acknowledgment
		UART_voidSendByte((u8*) "ok",2);
		//reset the counter of Buffer
		ReceiverCounter=0;
	} else {
		ReceiverCounter++;
	}
		//indicate the end of the File
		if(ReceiverBuffer[8]=='1'){
         //jumping into application
			App_voidTest();
		}
}
}

	return 0;
}

