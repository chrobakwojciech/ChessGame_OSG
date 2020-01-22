#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Board.h"

class ChessGame {
public:
	ChessGame(Player *player1, Player *player2);
	Board* board;
private:
	Player* player1;
	Player* player2;
};
#endif