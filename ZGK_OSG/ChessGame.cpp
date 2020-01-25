#include "ChessGame.h"
#include "Board.h"
#include "Player.h"

#include <osg/Group>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osg/ref_ptr>
#include <osgGA/GUIEventHandler>

using namespace osg;
using namespace osgViewer;
using namespace osgGA;
using namespace std;


const Matrix camera_positions[4] = {
	// Matrix::lookAt(eye, center, up)
	Matrix::lookAt(Vec3(0, 200, 200), Vec3(0, 0, 0), Vec3(0, 0, 1)),
    Matrix::lookAt(Vec3(0, -200, 200), Vec3(00, 0, 0), Vec3(0, 0, 1))
};

Matrix ChessGame::PointOfViewHandler::getCameraPos() {
    if (this->currentPlayerColor == Colours::BLACK) {
        return Matrix::lookAt(Vec3(0, -(this->currCamerPos), 200), Vec3(00, 0, 0), Vec3(0, 0, 1));
    }
    else {
        return Matrix::lookAt(Vec3(0, this->currCamerPos, 200), Vec3(00, 0, 0), Vec3(0, 0, 1));
    }
    
}

Matrix ChessGame::PointOfViewHandler::upCameraPos() {
    this->currCamerPos += 1.0;
    return getCameraPos();
}

Matrix ChessGame::PointOfViewHandler::downCameraPos() {
    this->currCamerPos -= 1.0;
    return getCameraPos();
}


bool ChessGame::PointOfViewHandler::handle(
    const GUIEventAdapter& ea, GUIActionAdapter& aa)
{
    if (ea.getEventType() != GUIEventAdapter::KEYDOWN) {
        return false;
    }

    ref_ptr<Viewer> p;
    _viewer.lock(p);
    Matrix cam_pos;
    switch (ea.getUnmodifiedKey()) {
    case GUIEventAdapter::KEY_1:
    case GUIEventAdapter::KEY_A:
        this->currentPlayerColor = Colours::WHITE;
        cam_pos = getCameraPos();
        break;
    case GUIEventAdapter::KEY_2:
    case GUIEventAdapter::KEY_B:
        this->currentPlayerColor = Colours::BLACK;
        cam_pos = getCameraPos();
        break;
    case GUIEventAdapter::KEY_Up:
        cam_pos = this->upCameraPos();
        break;
    case GUIEventAdapter::KEY_Down:
        cam_pos = this->downCameraPos();
        break;
    case GUIEventAdapter::KEY_5:
        cam_pos = getCameraPos();
        this->game->player1->move(7, 1, 5, 2);
        this->game->render();
        break;
    case GUIEventAdapter::KEY_6:
        cam_pos = getCameraPos();
        this->game->player1->move(6, 3, 5, 3);
        this->game->render();
        break;
    case GUIEventAdapter::KEY_7:
        cam_pos = getCameraPos();
        this->game->player1->move(7, 2, 3, 6);
        this->game->render();
        break;
    default:
        return false;
    }
    if (p) {
        p->getCamera()->setViewMatrix(cam_pos);
    }

    //this->game->board->figures_OBJ = nullptr;
    
    this->game->board->renderFiguresOBJ();
    
    p.get()->setSceneData(this->game->root);
    aa.requestRedraw();

    return true;
}

ChessGame::PointOfViewHandler::PointOfViewHandler(const ref_ptr<Viewer>& viewer, ChessGame* game) {
    this->_viewer = viewer;
    this->currCamerPos = 200.0;
    this->currentPlayerColor = Colours::WHITE;
    this->game = game;

}


ChessGame::ChessGame(Player* player1, Player* player2) {
	this->player1 = player1;
	this->player2 = player2;
	this->board = new Board();
	this->player1->board = this->board;
	this->player2->board = this->board;
}

void ChessGame::createViever() {
    this->viewer = new Viewer();
	//this->viewer->setUpViewInWindow(100, 100, 1920 * 0.8, 1080 * 0.8);
	this->viewer->setUpViewOnSingleScreen(1);
	this->viewer->setSceneData(this->root);
    this->viewer->getCamera()->setAllowEventFocus(false);
    ref_ptr<PointOfViewHandler> povh = new PointOfViewHandler(this->viewer, this);
    this->viewer->addEventHandler(povh.get());
    this->viewer->getCamera()->setViewMatrix(camera_positions[0]);
	//this->viewer.setCameraManipulator(new TrackballManipulator);
}

void ChessGame::render() {
    this->root = new Group;
    this->root.get()->addChild(this->board->board_OBJ);
    this->root.get()->addChild(this->board->figures_OBJ);
}

void ChessGame::run() {
    this->render();

	this->createViever();
    this->viewer->run();
	//this->viewer.realize();
	//while (!this->viewer.done()) {
		//this->viewer.frame();
	//}
}

void ChessGame::printBoard() {	
	this->board->printFigures();
   
}

