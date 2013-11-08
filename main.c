#include <msp430.h>
#include "game_shell/game.h"
#include "buttons/button.h"
#include "LCD-1/LCD.h"

unsigned char player;
int TIMER = 0;
int WIN = 0;
int reset;
int newGame;

void init_timer();
void init_buttons();

void clearTimer() {
	TIMER = 0;
	TACTL |= TACLR;
}

void main(void) {
	WDTCTL = (WDTPW | WDTHOLD);

	initSPI();

	LCDinit();

	LCDclear();

	//unsigned char player = initPlayer();

	init_timer();
	init_buttons();

	LCDclear();
	player = initPlayer();
	clearTimer();
	WIN = 0;
	printPlayer(player);

	__enable_interrupt();
	while (1) {



		if (didPlayerWin(player) == 1) {

			LCDclear();
			writeString("You");
			cursorToLineTwo();
			writeString("Win");

			reset = 0;
			while(reset == 0){

			}
			LCDclear();
			player = initPlayer();
			clearTimer();
			WIN = 0;
			printPlayer(player);
		} else if (WIN == 1) {

			LCDclear();
			writeString("Game");
			cursorToLineTwo();
			writeString("Over");

			reset = 0;
			while(reset == 0){

			}
			LCDclear();
			player = initPlayer();
			clearTimer();
			WIN = 0;
			printPlayer(player);
		}



	}

}

void testAndRespondToButtonPush(char buttonToTest) {
	if (buttonToTest & P1IFG) {
		if (buttonToTest & P1IES) {
			clearPlayer(player);
			player = movePlayer(player, buttonToTest);
			printPlayer(player);
			clearTimer();
			reset = 1;

		} else {
			debounce();
		}

		P1IES ^= buttonToTest;
		P1IFG &= ~buttonToTest;
	}
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1_ISR(void) {
	testAndRespondToButtonPush(BIT1);
	testAndRespondToButtonPush(BIT2);
	testAndRespondToButtonPush(BIT3);
	testAndRespondToButtonPush(BIT4);
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


	TACTL &= ~(MC1 | MC0);        // stop timer

	TACTL |= TACLR;             // clear TAR

	TACTL |= TASSEL1;   // configure for SMCLK - what's the frequency (roughly)?

	TACTL |= ID1 | ID0; // divide clock by 8 - what's the frequency of interrupt?

	TACTL &= ~TAIFG;            // clear interrupt flag

	TACTL |= MC1;               // set count mode to continuous

	TACTL |= TAIE;              // enable interrupt

}

void init_buttons() {
	configureP1PinAsButton(BIT1 | BIT2 | BIT3 | BIT4);
	P1IES |= BIT1 | BIT2 | BIT3 | BIT4;
	P1IFG &= ~(BIT1 | BIT2 | BIT3 | BIT4);
	P1IE |= BIT1 | BIT2 | BIT3 | BIT4;
	// do button initialization work
}
