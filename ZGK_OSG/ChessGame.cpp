#include "ChessGame.h"
#include "Board.h"
#include "Player.h"

ChessGame::ChessGame(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;
	this->board = new Board();
	this->player1->board = this->board;
	this->player2->board = this->board;
}