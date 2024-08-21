// UART.h
#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdbool.h>
#include "TM4C123/systick.h"
#include "TM4C123/gpio.h"
#include "TM4C123/CMSIS_TM4C123/Device/TM4C123GH6PM.h"
#include "TM4C123/coretick.h"
#include "tm4c123gh6pm.h"

// initialization of the UART
void UART_init();
void UART0_Handler(); // Interrupt handler for UART0
// operations
void uart0_putchar(char data);
char uart0_receive();
char uart0_receive_mod();

// initialization of the ports
void PORTF_init();
void PORTA_init();

#endif // UART_H
