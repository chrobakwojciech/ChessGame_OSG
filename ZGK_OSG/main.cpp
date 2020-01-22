#include <iostream>
#include "Figure.h"
#include "Figures.h"
#include "Colours.h"
#include "Board.h"
#include "Player.h"
#include "ChessGame.h"

using namespace std;

int main(int argc, char* argv[]) {
	Player *player1 = new Player(Colours::BLACK);
	Player *player2 = new Player(Colours::WHITE);

	ChessGame* game = new ChessGame(player1, player2);
	game->board->printFigures();
	return 0;
}
