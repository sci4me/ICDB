#pragma config FOSC 	= ECPLLIO_EC		// 24 MHz External Clock
#pragma config PLLDIV 	= 6 				// 24 / 6 = 4 MHz PLL Input
#pragma config CPUDIV   = OSC1_PLL2 		// 96 / 2 = 48 MHz Core Clock
#pragma config USBDIV 	= 2					// 96 / 2 = 48 MHz USB Clock

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