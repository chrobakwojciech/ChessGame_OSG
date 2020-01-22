#include <iostream>
#include "Player.h"
#include "ChessGame.h"

using namespace std;

int main(int argc, char* argv[]) {
	Player *player1 = new Player(Colours::BLACK);
	Player *player2 = new Player(Colours::WHITE);

	ChessGame* game = new ChessGame(player1, player2);
	game->board->printFigures();

	player1->move(0, 0, 4, 4);
	cout << endl;
	game->board->printFigures();

	return 0;
}
