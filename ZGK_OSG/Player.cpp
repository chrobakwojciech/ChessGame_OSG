#include "Player.h"
#include <iostream>

Player::Player(Colours colour) {
	this->colour = colour;
	this->board = nullptr;
}

bool Player::move(int fromX, int fromY, int toX, int toY) {
	Figure* activeFigure = this->board->fields[fromX][fromY]->figure;
	//if (activeFigure != nullptr) {
	//	if (activeFigure->canMove(this->board, fromX, fromY, toX, toY)) {
	//		this->board->fields[fromX][fromY]->figure = nullptr;
	//		this->board->fields[toX][toY]->figure = activeFigure;
	//		return true;
	//	}
	//	else {
	//		cout << "Nie mozesz przesunac tam figury" << endl;
	//		return false;
	//	}

	//}
	//else {
	//	cout << "Nie wybrales zadnej figury" << endl;
	//	return false;
	//}
	return false;
}
