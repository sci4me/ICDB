#include <pic18fregs.h>
#include <delay.h>
#include <signal.h>


#include "types.h"
#include "config.c"
#include "uart.c"
// #include "interrupts.c"


#define INPUT 		1
#define OUTPUT 		0


#define CPU_D0 		PORTBbits.RB4
#define CPU_D1 		PORTBbits.RB3 
#define CPU_D2 		PORTBbits.RB2
#define CPU_D3 		PORTBbits.RB1
#define CPU_D4 		PORTBbits.RB0
#define CPU_D5 		PORTDbits.RD7
#define CPU_D6 		PORTDbits.RD6
#define CPU_D7 		PORTDbits.RD5
#define CPU_CLK 	PORTDbits.RD4
#define CPU_RST  	PORTAbits.RA6
#define CPU_RW		0x10 // God damnit, SDCC...
#define CPU_IRQ 	0x08
#define CPU_A0 		PORTAbits.RA0
#define CPU_A1 		PORTAbits.RA1
#define CPU_A2 		PORTAbits.RA2
#define CPU_A3 		PORTAbits.RA3
#define CPU_A4 		PORTAbits.RA4
#define CPU_A5 		PORTAbits.RA5
#define CPU_A6 		PORTEbits.RE0
#define CPU_A7 		PORTEbits.RE1
#define CPU_A8 		PORTEbits.RE2
#define CPU_A9		PORTCbits.RC0
#define CPU_A10 	PORTCbits.RC1
#define CPU_A11 	PORTCbits.RC2
#define CPU_A12 	PORTDbits.RD0
#define CPU_A13 	PORTDbits.RD1
#define CPU_A14 	PORTDbits.RD2
#define CPU_A15 	PORTDbits.RD3


void main(void) {
	// TODO: Clean this stuff up.
	INTCON 					= 0x00;	// No Interrupts
	PIE1					= 0x00; // No Peripheral Interrupts
	ADCON0 					= 0x00; // No ADC
	ADCON1  				= 0x0F; // Digital I/O
	CMCON 					= 0x07; // No Comparators
	CCP1CON 				= 0; 	// No PWMs
	SPPCON 					= 0; 	// No SPP


	// TODO: Clean this stuff up.
	TRISBbits.TRISB4 = OUTPUT;
	TRISBbits.TRISB3 = OUTPUT;
	TRISBbits.TRISB2 = OUTPUT;
	TRISBbits.TRISB1 = OUTPUT;
	TRISBbits.TRISB0 = OUTPUT;
	TRISDbits.TRISD7 = OUTPUT;
	TRISDbits.TRISD6 = OUTPUT;
	TRISDbits.TRISD5 = OUTPUT;
	TRISDbits.TRISD4 = OUTPUT;
	TRISAbits.TRISA6 = OUTPUT;
	TRISC |= CPU_RW;
	TRISC |= CPU_IRQ;
	TRISAbits.TRISA0 = INPUT;
	TRISAbits.TRISA1 = INPUT;
	TRISAbits.TRISA2 = INPUT;
	TRISAbits.TRISA3 = INPUT;
	TRISAbits.TRISA4 = INPUT;
	TRISAbits.TRISA5 = INPUT;
	TRISEbits.TRISE0 = INPUT;
	TRISEbits.TRISE1 = INPUT;
	TRISEbits.TRISE2 = INPUT;
	TRISCbits.TRISC0 = INPUT;
	TRISCbits.TRISC1 = INPUT;
	TRISCbits.TRISC2 = INPUT;
	TRISDbits.TRISD0 = INPUT;
	TRISDbits.TRISD1 = INPUT;
	TRISDbits.TRISD2 = INPUT;
	TRISDbits.TRISD3 = INPUT;

	
	//uart_init();


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