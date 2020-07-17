#include <pic18fregs.h>
#include <delay.h>


#pragma config FOSC 	= ECPLLIO_EC		// 24 MHz External Clock
#pragma config PLLDIV 	= 6 				// 24 / 6 = 4 MHz PLL Input
#pragma config CPUDIV   = OSC1_PLL2 		// 96 / 2 = 48 MHz Core Clock
#pragma config USBDIV 	= 2					// 96 / 2 = 48 MHz USB Clock

#pragma config XINST	= OFF 				// No Extended ISA
#pragma config WDT 		= OFF 				// No Watchdog Timer
#pragma config LVP 		= OFF 				// No Low-Voltage Programming
#pragma config BOR 		= OFF				// No Brown-out-Reset
#pragma config MCLRE 	= ON  				// MCLR Reset
#pragma config FCMEN 	= OFF 				// No Failsafe Clock Monitor
#pragma config IESO 	= OFF 				// No Internal External Switchover
#pragma config PWRT 	= ON 				// Power-Up Timer
#pragma config VREGEN 	= OFF 				// No USB Voltage Regulation
#pragma config PBADEN 	= OFF 				// No PORTB ADC
#pragma config DEBUG 	= OFF 				// No debugging :(


#define INPUT 		1
#define OUTPUT 		0

#define LED_DIR 	TRISDbits.TRISD3
#define LED_OFF 	PORTDbits.RD3 = 0
#define LED_ON 		PORTDbits.RD3 = 1


/*
extern void _startup(void);
#pragma code _RESET_INTERRUPT_VECTOR = 0x000800
void _reset(void) {
    _asm goto _startup _endasm
}
#pragma code

#pragma code _HIGH_INTERRUPT_VECTOR = 0x000808
void _high_ISR(void) {
    ;
}

#pragma code _LOW_INTERRUPT_VECTOR = 0x000818
void _low_ISR(void) {
    ;
}
#pragma code
*/


void main(void) {
	// ADCON0 					= 0;
	// ADCON1  				= 0;
	// ADCON2 					= 0;

	INTCON 					= 0;	// Interrupts Off
	CMCON 					= 0x07; // Comparators Off
	ADCON1bits.PCFG 		= 0x0F; // Digital inputs!
	PORTEbits.RDPU 			= 0;  	// Disable pull ups
	CCP1CON 				= 0; 	// P1B, P1C, P1D assigned as port pins

	LED_DIR 				= OUTPUT;

	int x = 0b0011;

	while(1) {
		LED_ON;
		delay100ktcy(15);
		LED_OFF;
		delay100ktcy(15);
	}
}