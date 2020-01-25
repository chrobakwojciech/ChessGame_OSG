#include "Player.h"
#include <iostream>
#include <osg/Group>
#include <osg/ref_ptr>

using namespace std;
using namespace osg;

Player::Player(Colours colour) {
	this->colour = colour;
	this->board = nullptr;
}

bool Player::move(int fromX, int fromY, int toX, int toY) {
	Figure* activeFigure = this->board->fields[fromX][fromY]->figure;
	ref_ptr<Group> tempObj = this->board->fields[fromX][fromY]->figure_OBJ;

	if (activeFigure != nullptr) {
		if (activeFigure->canMove(this->board, fromX, fromY, toX, toY)) {
			cout << "PRZESUNALES" << endl;
			this->board->fields[fromX][fromY]->figure = nullptr;
			this->board->fields[toX][toY]->figure = activeFigure;
			this->board->fields[toX][toY]->figure_OBJ = tempObj;
			this->board->fields[fromX][fromY]->figure_OBJ = nullptr;
			this->board->renderFiguresOBJ();
			return true;
		}
		else {
			cout << "Nie mozesz przesunac tam figury" << endl;
			return false;
		}

	}
	else {
		cout << "Nie wybrales zadnej figury" << endl;
		return false;
	}
	return false;
}
