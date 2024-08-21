#include "UART.h" 


void printall(unsigned n)
{ 
	int count = 0; 
	printf("DEC: ");
	count = printf("%d", n);
	printf("COUNT: ");
	printf("%d", count);
	printf("HEX: ");
	printf("%x", n);
	printf("BIN: ");
	printf("%b", n);
}



void print(const char *str){
	for (unsigned int i = 0; i < strlen(str); i++){
		// uart_0putchar(*(str + i)); 
	}
}
