 #include <msp430g2553.h>
#include "game.h"
#include "../LCD-1/LCD.h"

unsigned char initPlayer()
{
	return 0x80;
}

void printPlayer(unsigned char player)
{
	writeCommandByte(player);
	writeDataByte('*');
}

void clearPlayer(unsigned char player)
{
	writeCommandByte(player);
	writeDataByte(' ');
}

#define ROW_MASK 0x40

unsigned char movePlayer(unsigned char player, unsigned char direction)
{
	switch (direction) {
		case RIGHT:
			if ((player & 0x0f) < 7)
				player += 1;
			break;
		case LEFT:
			if ((player & 0x0f) > 0)
				player -= 1;
			break;
		case UP:
			player &= ~ROW_MASK;
			break;
		case DOWN:
			player |= ROW_MASK;
			break;
	}

	return player;
}

char didPlayerWin(unsigned char player)
{
	return player == 0xC7;
}
