<<<<<<< HEAD
# MSP430g2553 LCD Driver

## Methods

- `void initSPI();`
	- Initializes SPI subsystem to LCD specs
- `void LCDinit();`
	- Sends command sequence to initialize LCD
- `void LCDclear();`
	- Sends command to clear LCD
- `void cursorToLineTwo();`
	- Sends command to set cursor to first position on line two
- `void cursorToLineOne();`
	- Sends command to set cursor to first position on line one
- `void writeChar(char asciiChar);`
	- Writes a character to the current cursor position
- `void writeString(char * string);`
	- Writes a string to the current cursor position
- `void scrollString(char * string1, char * string2);`
	- Scrolls strings across top and bottom lines of the LCD

## LCD Setup

```c
#include "LCD.h"

int main()
{
	WDTCTL = WDTPW | WDTHOLD;

	initSPI();
	LCDinit();
	LCDclear();

	// your code
}
```
=======
Lab5
====
main.c is my code for a simple game using interrupts to handle button pushes

>>>>>>> 24ca612a06f34ab958b36e0b2c89757c0219d3ad
