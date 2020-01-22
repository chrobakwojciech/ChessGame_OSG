#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include "Colours.h"
#include "Board.h"

class Board;

class Figure {
	friend class Player;
public:
	virtual std::string toString() = 0;
	virtual bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
	Colours getColour();
protected:
	Colours colour = Colours::BLACK;
};

#endif