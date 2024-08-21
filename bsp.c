#include "bsp.h"

volatile char receivedChar; // Global variable to store received character


void UART_init(){ 
	SYSCTL->RCGCUART |= 0x01; 
	UART0->CTL = 0; /* 16MHz/16=1MHz, 1MHz/9600=104  0.166 x 64 + 0.5 = 11 */ 
	UART0->IBRD = 104; 
	UART0->FBRD = 11; 
	UART0->CC = UART0->LCRH = 0x60; 
	UART0->CTL = 0x301;
	UART0->IM |= 0x10; // Enable UART0 receive interrupt
	NVIC->ICPR[0] |= (1 << 5); // Clear pending flag for UART0 interrupt
	NVIC->ISER[0] |= (1 << 5); // Enable UART0 interrupt

  //NVIC->ISER[0] |= 0x20; // Enable interrupt 5 in NVIC (UART0)
  __enable_irq(); // Enable global interrupts
	
} 

char uart0_receive() {
    while ((UART0->FR & 0x10) != 0); // Wait until the receive FIFO is not empty
    return (char)(UART0->DR & 0xFF); // Read the received data
}

char uart0_receive_mod() {
    if ((UART0->FR & 0x10) == 0){
		    return (char)(UART0->DR & 0xFF); // Read the received data
		}			// Wait until the receive FIFO is not empty
		return 0;
}


void PORTA_init(){
	SYSCTL->RCGCGPIO |= 0x01;
	for (volatile int i = 0; i < 2; i++);
	GPIOA->DEN = GPIOA->AFSEL = 0x03;
	GPIOA->PCTL = 0x00000011;
}

void uart0_putchar(char data){
	while ((UART0->FR & 0x20) != 0);
	UART0->DR = data;
}

void PORTF_init(){
	SYSCTL->RCGCGPIO |= 0x20;
	for (volatile int i = 0; i < 2; i++);
	GPIOF->DIR = GPIOF->DEN = 0x03;
}

void UART0_Handler() {
		UART0->DR = receivedChar;
    if (UART0->MIS & 0x10) { // Check if receive interrupt
        receivedChar = (char)(UART0->DR & 0xFF); // Read the received data
				
        // Handle the received character (e.g., store it, process it, etc.)
        UART0->ICR = 0x10; // Clear the receive interrupt
    }
}