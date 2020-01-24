#include "ChessGame.h"
#include "Board.h"
#include "Player.h"

#include <osg/Group>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osg/ref_ptr>

using namespace osg;
using namespace osgViewer;
using namespace osgGA;

ChessGame::ChessGame(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;
	this->board = new Board();
	this->player1->board = this->board;
	this->player2->board = this->board;
}

void ChessGame::createViever() {
	//this->viewer.setUpViewInWindow(100, 100, 1920 * 0.8, 1080 * 0.8);
	this->viewer.setUpViewOnSingleScreen(1);
	this->viewer.setSceneData(this->root);
	this->viewer.setCameraManipulator(new TrackballManipulator);
}

void ChessGame::run() {
	this->root = new Group;
	this->root.get()->addChild(this->board->board_OBJ);
	this->root.get()->addChild(this->board->figures_OBJ);

	this->createViever();
	this->viewer.realize();
	while (!this->viewer.done()) {
		this->viewer.frame();
	}
}

void ChessGame::printBoard() {
	
	this->board->printFigures();
}

