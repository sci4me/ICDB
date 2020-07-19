#include <pic18fregs.h>
#include <delay.h>
#include <signal.h>


#include "types.h"
#include "config.c"
#include "uart.c"
// #include "interrupts.c"
#include "iface.c"



void main(void) {
	while(!OSCCONbits.IOFS); // Wait for the oscillator to be stable!
	OSCCON = 0x72;			 // 8 MHz, Internal Oscillator
	while(!OSCCONbits.IOFS); // Just in case; not sure if needed.


	// TODO: Clean this stuff up.
	INTCON 					= 0x00;	// No Interrupts
	PIE1					= 0x00; // No Peripheral Interrupts
	ADCON0 					= 0x00; // No ADC
	ADCON1  				= 0x0F; // Digital I/O
	CMCON 					= 0x07; // No Comparators
	CCP1CON 				= 0; 	// No PWMs
	SPPCON 					= 0; 	// No SPP


	uart_init();
	iface_init();
	

	uart_puts("Hello?!\n");


	// $EA on the data bus
	CPU_D0 = 0;
	CPU_D1 = 1;
	CPU_D2 = 0;
	CPU_D3 = 1;
	CPU_D4 = 0;
	CPU_D5 = 1;
	CPU_D6 = 1;
	CPU_D7 = 1;


	CPU_RST = 0;
	delay1ktcy(50);
	CPU_RST = 1;


	while(1) {
		delay10ktcy(2);
		CPU_CLK = 1;
		delay10ktcy(2);
		CPU_CLK = 0;
	}
}