#include <msp430.h>
#include "game_shell/game.h"
#include "buttons/button.h"
#include "LCD-1/LCD.h"

void init_timer();
void init_buttons();

int TIMER = 0;
int WIN = 0;


void main(void) {
	WDTCTL = (WDTPW | WDTHOLD);

	initSPI();

	LCDinit();

	LCDclear();

	//unsigned char player = initPlayer();

	init_timer();
	init_buttons();
	__enable_interrupt();

	while (1) {

		LCDclear();
		unsigned char player = initPlayer();
		TIMER = 0;
		WIN = 0;
		printPlayer(player);

		while ((didPlayerWin(player) != 1) && (WIN == 0)) {

			char buttons[4] = { BIT1, BIT2, BIT3, BIT4 };
			char pressedButton = checkP1Buttons(buttons, 4);
//
			if (pressedButton != FALSE) {
				clearPlayer(player);
				player = movePlayer(player, pressedButton);
				printPlayer(player);
				TIMER = 0;
				TACTL |= TACLR;
				waitForP1ButtonRelease(pressedButton);
				debounce();
				pressedButton = 0;
			}
//
		}

		if (didPlayerWin(player) == 1) {
			LCDclear();
			writeString("You");
			cursorToLineTwo();
			writeString("Win");
		} else {
			LCDclear();
			writeString("Game");
			cursorToLineTwo();
			writeString("Over");
		}

		char buttonsToPoll[4] = { BIT1, BIT2, BIT3, BIT4 };
		while (!pollP1Buttons(buttonsToPoll, 4)) {

		}
//		char pressedButtonSecond = checkP1Buttons(buttonsToPoll, 4);
//		waitForP1ButtonRelease(pressedButtonSecond);
//		debounce();

	}

}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR() {
	TACTL &= ~TAIFG;            // clear interrupt flag
	TIMER += 1;
	if (TIMER == 4) {
		WIN = 1;
	}
}

void init_timer() {
	// do timer initialization work
	//TACTL = 01 | 1 | 11 | 1 | 1;

	TACTL &= ~(MC1|MC0);        // stop timer

	TACTL |= TACLR;             // clear TAR

	TACTL |= TASSEL1;           // configure for SMCLK - what's the frequency (roughly)?

	TACTL |= ID1|ID0;           // divide clock by 8 - what's the frequency of interrupt?

	TACTL &= ~TAIFG;            // clear interrupt flag

	TACTL |= MC1;               // set count mode to continuous

	TACTL |= TAIE;              // enable interrupt

}

void init_buttons() {
	configureP1PinAsButton(BIT1 | BIT2 | BIT3 | BIT4);
	// do button initialization work
}
