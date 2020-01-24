#include <iostream>
#include "Player.h"
#include "ChessGame.h"
#include "ChessOSG.h"
#include "Colours.h"
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osg/ref_ptr>

using namespace std;

int main(int argc, char* argv[]) {
	Player* player1 = new Player(Colours::BLACK);
	Player* player2 = new Player(Colours::WHITE);

	ChessGame* game = new ChessGame(player1, player2);
	game->run();

	return 0;
}
