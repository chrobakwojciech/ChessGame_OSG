#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Board.h"
#include <osgViewer/Viewer>
#include <osgGA/GUIEventHandler>
#include <osg/ref_ptr>
#include "Colours.h"
#include "Player.h"

class ChessGame {
public:
	ChessGame(Player *player1, Player *player2);
	void run();
	void printBoard();
	void render();
private:
	class PointOfViewHandler : public osgGA::GUIEventHandler {
		
	public:
		osg::observer_ptr<osgViewer::Viewer> _viewer;
		virtual bool handle(const osgGA::GUIEventAdapter&, osgGA::GUIActionAdapter&);
		PointOfViewHandler(const osg::ref_ptr<osgViewer::Viewer>& viewer, ChessGame* game);
		/*PointOfViewHandler(const ref_ptr<Viewer>& viewer)
			: _viewer(viewer)
		{ }*/

		osg::Matrix upCameraPos();
		osg::Matrix downCameraPos();
		osg::Matrix getCameraPos();
		Colours currentPlayerColor;
		double currCamerPos;

	protected:
		ChessGame* game;
		virtual ~PointOfViewHandler()
		{ }
	};

	Board* board;
	Player* player1;
	Player* player2;
	osg::ref_ptr<osgViewer::Viewer> viewer;
	osg::ref_ptr<osg::Group> root;
	void createViever();
};
#endif