# Neils Makefile for Ardiuno Uno

#Specify a target file name
TARGET=avrMash
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -Wall
# Specify a Compiler 
CC=avr-gcc

#make target is ${TARGET}.hex
all: ${TARGET}.hex

# .hex relies on creating a .out
${TARGET}.hex: ${TARGET}.out
	avr-objcopy -O ihex -R .eeprom ${TARGET}.out ${TARGET}.hex

# .out relies on the object files 
${TARGET}.out: ${TARGET}.o lcd.o interrupts.o
	${CC} -mmcu=atmega328p ${TARGET}.o lcd.o interrupts.o -o ${TARGET}.out

# compile the C into object files.
${TARGET}.o:
	${CC} ${CFLAGS}	-o ${TARGET}.o ${TARGET}.c

lcd.o:
	${CC} ${CFLAGS}	-o lcd.o lcd.c

interrupts.o:
	${CC} ${CFLAGS}	-o interrupts.o interrupts.c


upload: 
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:${TARGET}.hex
clean:
	rm -rf *.out *.o *.hex ${TARGET}


