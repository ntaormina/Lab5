<<<<<<< HEAD
# button
Library for working with buttons on the MSP430.
Example code included in main.c.

## General Notes
Assumes buttons are active low.  Configures with internal pull-up resistor if button open state is floating.

## Functions
- `void configureP1PinAsButton(char pin)`
    - Configures pin as input with internal pull-up resistor
    - Pin settings
        - P1DIR = 0 (input)
        - P1REN = 1 (enable internal pull-up/pull-down networks)
        - P1OUT = 1 (configure as pull-up)
    - Usage:
        - `configureP1PinAsButton(BIT3);`
            - Configures Port 1, Pin 3 as button
        - `configureP1PinAsButton(BIT0|BIT1|BIT2);`
            - Configures Port 1, Pins 0, 1, and 2 as button
- `char isP1ButtonReleased(char pin)`
    - Returns one if pin is high, zero if pin is low
    - Usage:
        - `isP1ButtonReleased(BIT3);`
            - Returns 1 if released
            - Returns 0 if pressed
- `void waitForP1ButtonRelease(char pin)`
    - Blocks until detects pin going high
    - Debounces after detection
    - Usage:
        - `waitForP1ButtonRelease(BIT3);`
            - Blocks until pin 3 is high, debounces
- `char isP1ButtonPressed(char pin)`
    - Returns one if pin is low, zero if pin is high.
    - Usage:
        - `isP1ButtonPressed(BIT3);`
            - Returns 1 if pressed
            - Returns 0 if released
- `char pollP1Buttons(char buttonsToPoll[], char numberOfButtonsToPoll)`
    - Blocks until button is pushed, returns bit mask of pressed button
    - Usage:
        - Blocks until one of buttons is pushed
        - `pressedButton` is set to mask of pushed button

```
char buttons[] = {BIT1, BIT2, BIT3};
char pressedButton = pollP1Buttons(buttons, 3);
```
- `char checkP1Buttons(char buttonsToCheck[], char numberOfButtonsToCheck);`
	- Checks set of buttons for press, returns bit mask of pressed button
	- Do this if you don't want to block
- `void debounce()`
    - Delays for 1000 clock cycles.
    - Time length depends on clock speed, but 1ms with 1MHz clock.
    - Usage:
        - `debounce();`

## License
Anyone is free to use and modify this for any purpose, provided they document it.
=======
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
>>>>>>> 77507ce071cfc2a195d826485f3c1d1ef900d512
