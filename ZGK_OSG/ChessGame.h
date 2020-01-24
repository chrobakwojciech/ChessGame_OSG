#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Board.h"
#include <osgViewer/Viewer>

class ChessGame {
public:
	ChessGame(Player *player1, Player *player2);
	void run();
	void printBoard();
private:
	Board* board;
	Player* player1;
	Player* player2;
	osgViewer::Viewer viewer;
	osg::ref_ptr<osg::Group> root;
	void createViever();
};
#endif