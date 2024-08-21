#include <stdint.h>
#include <stdbool.h>
/* #include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_uart.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h" */
#include "bsp.h"
// #include "UART.h"
//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif



extern volatile char receivedChar;

void Delay(unsigned long counter){
	volatile unsigned long i = 0;
	for (i = 0; i < counter; i++);
}

int main(){
	UART_init();

	//PORTA_init();
	// PORTF_init();
	char received, send;
	while(1){
		received = uart0_receive_mod();
		// if nothing is received, will not enter the condition
		if (received){
			if (received >= 0x61 && received <= 0x7a){ // check that is lower case
				send = received - 0x20;   // if it is lower case, send thr upper version
				uart0_putchar((char)send);
			}else if (received >= 0x41 && received <= 0x5a){
				send = received + 1;
				uart0_putchar((char)send);
			}
			received = 0;
		}
		Delay(5000);
	}
	
	
	/*while(1){
		if (receivedChar) { // Check if a character has been received
            //printf("Received: %c\n", receivedChar);
            receivedChar = 0; // Reset the received character
		}
	}*/
}




