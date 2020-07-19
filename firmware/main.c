#include <pic18fregs.h>
#include <delay.h>
#include <signal.h>


#include "types.h"
#include "config.c"
#include "uart.c"
// #include "interrupts.c"
#include "iface.c"


void print_state(void) {
	u8 data;
	if(read_rw()) {
		data = get_data_bus();
	} else {
		data = read_data_bus();
	}

	u16 addr = read_address_bus();


	if(CPU_CLK) 	uart_puts("CLK: 1");
	else			uart_puts("CLK: 0");

	uart_puts(" | ");

	if(read_irq()) 	uart_puts("IRQ: 1");
	else			uart_puts("IRQ: 0");

	uart_puts(" | ");

	if(read_rw()) 	uart_puts("RW: 1");
	else 			uart_puts("RW: 0");

	uart_puts(" | ");

	uart_puts("ADDR: ");
	uart_put_hex_byte((addr >> 8) & 0xFF);
	uart_put_hex_byte(addr & 0xFF);

	uart_puts(" | ");

	uart_puts("DATA: ");
	uart_put_hex_byte(data);

	uart_putc(10);
}


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
	UCONbits.SUSPND 		= 0; 	// 17.2: SUSPND must be clear before clearing USBEN
	UCONbits.USBEN			= 0;	// No USB
	UCFGbits.UPUEN 			= 0;	// No USB pull-ups
	UCFGbits.UTRDIS 		= 1;	// No On-Chip Tranciever



	delay10ktcy(2);


	uart_init();
	iface_init();


	reset_cpu();


	print_state();


	while(1) {
		delay10ktcy(2);
		CPU_CLK = 0;

		
		delay10ktcy(2);
		CPU_CLK = 1;


		print_state();
	}
}