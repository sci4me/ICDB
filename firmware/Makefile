CC=sdcc
FAMILY=pic16
PROC=18f4550
P=PIC18F4550


.PHONY: all clean compile program


all: clean compile

clean:
	rm -f *.o
	rm -f *.hex
	rm -f $(SRC:.c=.asm) $(SRC:.c=.cod) $(SRC:.c=.hex) $(SRC:.c=.lst) $(SRC:.c=.o)

compile:
	$(CC) --use-non-free --use-crt=crt0.o -m$(FAMILY) -p$(PROC) main.c
	rm -f *.asm
	rm -f *.cod
	rm -f *.lst

program: clean compile
	pk2cmd -P $(P) -F main.hex -X -M -R -T