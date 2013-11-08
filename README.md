<<<<<<< HEAD
# Lab 5 Game Shell

This code provides functions that may prove useful in implementing the Lab 5 game

## Basic Idea

The player is represented by an unsigned char containing a position on the board.  Relies on an LCD library - included as `LCD/LCD.h`.

`example.c` gives you a program skeleton and pseudocode that may be helpful in achieving required functionality.

## Code

- `unsigned char initPlayer();`
	- returns the address of the first position in the game
	- this can be called to place the player at the starting position
- `void printPlayer(unsigned char player);`
	- prints the player symbol to the passed in location
- `void clearPlayer(unsigned char player);`
	- clears the passed in location by printing a space
- `unsigned char movePlayer(unsigned char player, unsigned char direction);`
	- returns an updated position based on an input position and direction of movement
	- constants for `UP`, `DOWN`, `LEFT`, and `RIGHT` are included in the header
- `char didPlayerWin(unsigned char player);`
	- returns 1 if the player is at the winning position, 0 otherwise

Also provides prototypes of functions that may prove useful in achieving higher levels of functionality.
=======
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
>>>>>>> bbba415b639a52d81b0f7af4a14935801070d31a
