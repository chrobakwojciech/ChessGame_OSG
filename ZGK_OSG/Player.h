#ifndef PLAYER_H
#define PLAYER_H

#include "Colours.h"
#include "Board.h"

class Player {
	friend class ChessGame;
public:
	Player(Colours colour);
	bool move(int fromX, int fromY, int toX, int toY);
private:
	Colours colour;
	Board* board;
};

#endif