<<<<<<< HEAD
#include <msp430.h>
#include "game.h"
#include "button/buttons.h"
#include "LCD/LCD.h"

void init_timer();
void init_buttons();

int main(void)
{
	WDTCTL = (WDTPW|WDTHOLD);

	unsigned char player = initPlayer();

	init_timer();
	init_buttons();
	__enable_interrupt();

	while(1)
	{
		/*
		 * while (game is on)
		 * {
		 * 		check if button is pushed (you don't want to block here, so don't poll!)
		 * 		if button is pushed:
		 * 			clear current player marker
		 * 			update player position based on direction
		 * 			print new player
		 * 			clear two second timer
		 * 			wait for button release (you can poll here)
		 * }
		 *
		 * print game over or you won, depending on game result
		 *
		 * wait for button press to begin new game (you can poll here)
		 * wait for release before starting again
		 */
	}

	return 0;
}

// 
// YOUR TIMER A ISR GOES HERE
//

void init_timer()
{
	// do timer initialization work
}

void init_buttons()
{
	// do button initialization work
=======
//
// Example program demonstrating the use of button.h
// Toggles Launchpad LEDs on each button push
//

#include <msp430g2553.h>
#include "button.h"

int exampleMain()
{

    WDTCTL = WDTPW|WDTHOLD;

    configureP1PinAsButton(BIT1|BIT2|BIT3);         // configure pins 1, 2, and 3 as buttons

    P1DIR |= BIT0|BIT6;                             // set launchpad LEDs to output

    while (1) {
        char buttons[] = {BIT1, BIT2, BIT3};
        char pressedButton = pollP1Buttons(buttons, 3);
        
        switch (pressedButton) {
            case BIT1:
                // do something in response 
                break;
            case BIT2:
                // do something in response
                break;
            case BIT3:
                // toggle LEDs and wait for release
                P1OUT ^= BIT0|BIT6;
                waitForP1ButtonRelease(BIT3);
                break;
        }
    }

    return 0;
>>>>>>> bbba415b639a52d81b0f7af4a14935801070d31a
}
