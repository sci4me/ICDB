#include <pic18fregs.h>
#include <delay.h>


#pragma config XINST	= OFF
#pragma config FOSC 	= INTOSCIO_EC
#pragma config WDT 		= OFF
#pragma config LVP 		= OFF // TODO: check this
#pragma config BOR 		= ON
#pragma config MCLRE 	= OFF // TODO: check this
#pragma config PLLDIV 	= 2
#pragma config CPUDIV   = OSC1_PLL2
#pragma config FCMEN 	= OFF
#pragma config IESO 	= OFF
#pragma config PWRT 	= OFF // TODO: check this
#pragma config BORV 	= 0
#pragma config VREGEN 	= OFF // ?
#pragma config PBADEN 	= OFF // ? 	


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
	INTCON 					= 0;	// Interrupts Off
	CMCON 					= 0x07; // Comparators Off
	ADCON1 					= 0x06; // Port as Digital IO (TODO: port?)
	PORTEbits.RDPU 			= 0;  	// Disable pull ups (TODO: which ones?)
	CCP1CON 				= 0; 	// P1B, P1C, P1D assigned as port pins

	LED_DIR 				= OUTPUT;

	while(1) {
		LED_ON;
		delay10ktcy(5);
		// delay(5000);
		LED_OFF;
		delay10ktcy(5);
		// delay(5000);
	}
}