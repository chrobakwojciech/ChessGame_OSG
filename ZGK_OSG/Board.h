#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Figure.h"
#include "Colours.h"

class Figure;

class Board {
	friend class Player;
protected:
	class BoardField {
	public:
		BoardField(Colours colour);
		void setFigure(Figure* figure);
		Colours colour;
		Figure* figure;
	};
private:
	BoardField *fields[8][8];
	void fillBoard();
public:
	Board();
	void printColours();
	void printFigures();
};
#endif