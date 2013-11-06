#include <msp430.h>
#include "game.h"
#include "button.h"
#include "LCD.h"

void init_timer();
void init_buttons();

int main(void) {
	WDTCTL = (WDTPW | WDTHOLD);

	unsigned char player = initPlayer();

	init_timer();
	init_buttons();
	__enable_interrupt();

	while (1) {

		while (didPlayerWin == 0) {

			printPlayer(player);

			configureP1PinAsButton(BIT1 | BIT2 | BIT3 | BIT4); // configure pins 1, 2, and 3 as buttons

			P1DIR |= BIT0 | BIT6;                // set launchpad LEDs to output

			char buttons[] = { BIT1, BIT2, BIT3, BIT4 };
			char pressedButton = pollP1Buttons(buttons, 4);
			char direction = 0;

			switch (pressedButton) {
			case BIT1:
				direction = 1;
				break;
			case BIT2:
				direction = 2;
				break;
			case BIT3:
				direction = 3;
				break;
			case BIT4:
				direction = 4;
				break;
				P1OUT ^= BIT0 | BIT6;
				waitForP1ButtonRelease(BIT3);
				break;

			}

//		  		check if button is pushed (you don't want to block here, so don't poll!)
//		  		if button is pushed:
			if (direction != 0) {
				clearPlayer(player);
				movePlayer(player, direction);
				printPlayer(player);
				clear two second timer
				//		  			wait for button release (you can poll here)

			}
//		  			clear current player marker
//		  			update player position based on direction
//		  			print new player
//
		}

		if(didPlayerWin == 1){

		}else{

		}
//		  print game over or you won, depending on game result
//
//		  wait for button press to begin new game (you can poll here)
//		  wait for release before starting again

	}

	return 0;
}

//
// YOUR TIMER A ISR GOES HERE
//

void init_timer() {
	// do timer initialization work
	TACTC = ACLK|1|00|1|1;
}

void init_buttons() {
	// do button initialization work
}
