#include "Player.h"
#include "Board.h"
#pragma once

class ChessGame {
public:
	ChessGame(Player *player1, Player *player2);
	Board* board;
private:
	Player* player1;
	Player* player2;
};

