#include <pic18fregs.h>
#include <delay.h>


#include "types.h"
#include "config.c"
#include "uart.c"


#define INPUT 		1
#define OUTPUT 		0

#define LED_DIR 	TRISDbits.TRISD3
#define LED_OFF 	PORTDbits.RD3 = 0
#define LED_ON 		PORTDbits.RD3 = 1


void main(void) {
	// TODO: Clean this stuff up.
	INTCON 					= 0x00;	// No Interrupts
	PIE1					= 0x00; // No Peripheral Interrupts
	ADCON0 					= 0x00; // No ADC
	ADCON1  				= 0x0F; // Digital I/O
	CMCON 					= 0x07; // No Comparators
	CCP1CON 				= 0; 	// No PWMs

	// TODO: Why did we ever add this?
	PORTEbits.RDPU 			= 0;  	// Disable PORTD pull ups

	
	uart_init();


	uart_puts("Hello, World!\n");
	uart_puts("Send '0' to turn LED off; send '1' to turn LED on.\n");


	LED_DIR 				= OUTPUT;


	while(1) {
		u8 x = uart_getc();
		if(x == '0') {
			LED_OFF;
			uart_puts("LED off!\n");
		} else if(x == '1') {
			LED_ON;
			uart_puts("LED on!\n");
		} else {
			uart_puts("Unknown command: '");
			uart_putc(x);
			uart_puts("'\n");
		}

		// LED_ON;
		// delay100ktcy(15);
		// LED_OFF;
		// delay100ktcy(15);
	}
}