#define CPU_CLK 	PORTDbits.RD4
#define CPU_RST  	PORTAbits.RA6
#define CPU_RW		0x10 // God damnit, SDCC...
#define CPU_IRQ 	0x08

#define CPU_D0 		PORTBbits.RB4
#define CPU_D1 		PORTBbits.RB3 
#define CPU_D2 		PORTBbits.RB2
#define CPU_D3 		PORTBbits.RB1
#define CPU_D4 		PORTBbits.RB0
#define CPU_D5 		PORTDbits.RD7
#define CPU_D6 		PORTDbits.RD6
#define CPU_D7 		PORTDbits.RD5

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


typedef union {
	struct {
		unsigned b0 : 1;
		unsigned b1 : 1;
		unsigned b2 : 1;
		unsigned b3 : 1;
		unsigned b4 : 1;
		unsigned b5 : 1;
		unsigned b6 : 1;
		unsigned b7 : 1;
	};
	u8 value;
} U8bits;

typedef union {
	struct {
		unsigned b0 : 1;
		unsigned b1 : 1;
		unsigned b2 : 1;
		unsigned b3 : 1;
		unsigned b4 : 1;
		unsigned b5 : 1;
		unsigned b6 : 1;
		unsigned b7 : 1;
		unsigned b8 : 1;
		unsigned b9 : 1;
		unsigned b10 : 1;
		unsigned b11 : 1;
		unsigned b12 : 1;
		unsigned b13 : 1;
		unsigned b14 : 1;
		unsigned b15 : 1;
	};
	struct {
		U8bits lo;
		U8bits hi;
	};
	u16 value;
} U16bits;


void set_data_bus(u8 value) {
	U8bits data;
	data.value = value;
	CPU_D0 = data.b0;
	CPU_D1 = data.b1;
	CPU_D2 = data.b2;
	CPU_D3 = data.b3;
	CPU_D4 = data.b4;
	CPU_D5 = data.b5;
	CPU_D6 = data.b6;
	CPU_D7 = data.b7;
}

void set_address_bus(u16 value) {
	U16bits addr;
	addr.value = value;
	CPU_A0	= addr.b0;
	CPU_A1	= addr.b1;
	CPU_A2	= addr.b2;
	CPU_A3	= addr.b3;
	CPU_A4	= addr.b4;
	CPU_A5	= addr.b5;
	CPU_A6	= addr.b6;
	CPU_A7	= addr.b7;
	CPU_A8	= addr.b8;
	CPU_A9	= addr.b9;
	CPU_A10	= addr.b10;
	CPU_A11	= addr.b11;
	CPU_A12	= addr.b12;
	CPU_A13	= addr.b13;
	CPU_A14	= addr.b14;
	CPU_A15	= addr.b15;
}

u8 get_data_bus(void) {
	U8bits data;
	data.b0 = CPU_D0;
	data.b1 = CPU_D1;
	data.b2 = CPU_D2;
	data.b3 = CPU_D3;
	data.b4 = CPU_D4;
	data.b5 = CPU_D5;
	data.b6 = CPU_D6;
	data.b7 = CPU_D7;
	return data.value;
}

u16 get_address_bus(void) {
	U16bits addr;
	addr.b0 = CPU_A0;
	addr.b1 = CPU_A1;
	addr.b2 = CPU_A2;
	addr.b3 = CPU_A3;
	addr.b4 = CPU_A4;
	addr.b5 = CPU_A5;
	addr.b6 = CPU_A6;
	addr.b7 = CPU_A7;
	addr.b8 = CPU_A8;
	addr.b9 = CPU_A9;
	addr.b10 = CPU_A10;
	addr.b11 = CPU_A11;
	addr.b12 = CPU_A12;
	addr.b13 = CPU_A13;
	addr.b14 = CPU_A14;
	addr.b15 = CPU_A15;
	return addr.value;
}

void set_data_bus_mode(u8 mode) {
	TRISBbits.TRISB4 = mode;
	TRISBbits.TRISB3 = mode;
	TRISBbits.TRISB2 = mode;
	TRISBbits.TRISB1 = mode;
	TRISBbits.TRISB0 = mode;
	TRISDbits.TRISD7 = mode;
	TRISDbits.TRISD6 = mode;
	TRISDbits.TRISD5 = mode;
}

void set_address_bus_mode(u8 mode) {
	TRISAbits.TRISA0 = mode;
	TRISAbits.TRISA1 = mode;
	TRISAbits.TRISA2 = mode;
	TRISAbits.TRISA3 = mode;
	TRISAbits.TRISA4 = mode;
	TRISAbits.TRISA5 = mode;
	TRISEbits.TRISE0 = mode;
	TRISEbits.TRISE1 = mode;
	TRISEbits.TRISE2 = mode;
	TRISCbits.TRISC0 = mode;
	TRISCbits.TRISC1 = mode;
	TRISCbits.TRISC2 = mode;
	TRISDbits.TRISD0 = mode;
	TRISDbits.TRISD1 = mode;
	TRISDbits.TRISD2 = mode;
	TRISDbits.TRISD3 = mode;
}

void set_clk(u8 value) {
	CPU_CLK = value;
}

void set_rst(u8 value) {
	CPU_RST = value;
}

u8 get_rw(void) {
	return PORTC & CPU_RW != 0;
}

u8 get_irq(void) {
	return PORTC & CPU_IRQ != 0;
}

void iface_init(void) {
	// TODO: Clean this stuff up.
	TRISDbits.TRISD4 = OUTPUT; 	// CPU_CLK = OUTPUT
	TRISAbits.TRISA6 = OUTPUT; 	// CPU_RST = OUTPUT
	TRISC |= CPU_RW;			// CPU_RW = OUTPUT
	TRISC |= CPU_IRQ;			// CPU_IRQ = OUTPUT

	set_data_bus_mode(OUTPUT);
	set_address_bus_mode(OUTPUT);
}