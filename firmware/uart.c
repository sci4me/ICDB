void uart_init(void) {
	// TODO: Clean this stuff up.
	TRISC |= 0xC0;
	TXSTA = 0x24;
	RCSTA = 0x90;
	BAUDCON = 0x00;
	SPBRG = 12; // Roughly 38400 bps at 8 MHz
	SPBRGH = 0;
}

void uart_putc(u8 x) {
	while(!TXSTAbits.TRMT);
	TXREG = x;
}

void uart_puts(u8 *s) {
	u8 c;
	while(c = *s++) {
		uart_putc(c);
	}
}

u8 uart_getc(void) {
	while(!PIR1bits.RCIF) {
		if(RCSTAbits.OERR) {
			RCSTAbits.OERR = 0;
			RCSTAbits.CREN = 0;
			RCSTAbits.CREN = 1;
		}
	}
	return RCREG;
}