#pragma config FOSC 	= INTOSCIO_EC		// 8 MHz Internal Clock
#pragma config PLLDIV 	= 1 				// Unused
#pragma config CPUDIV   = OSC1_PLL2 		// Unused
#pragma config USBDIV 	= 2					// Unused

#pragma config XINST	= OFF 				// No Extended ISA
#pragma config WDT 		= OFF 				// No Watchdog Timer
#pragma config LVP 		= ON 				// Low-Voltage Programming
#pragma config BOR 		= OFF				// No Brown-out-Reset
#pragma config MCLRE 	= ON  				// MCLR Reset
#pragma config FCMEN 	= OFF 				// No Failsafe Clock Monitor
#pragma config IESO 	= OFF 				// No Internal External Switchover
#pragma config PWRT 	= ON 				// Power-Up Timer
#pragma config VREGEN 	= OFF 				// No USB Voltage Regulation
#pragma config PBADEN 	= OFF 				// No PORTB ADC
#pragma config DEBUG 	= OFF 				// No debugging :(
#pragma config ICPRT	= OFF				// No dedicated ICPRT