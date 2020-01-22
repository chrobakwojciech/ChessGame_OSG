#ifndef FIGURES_H
#define FIGURES_H

#include "Colours.h"
#include "Figure.h"
#include "Board.h"

class King : public Figure {
public:
	King(Colours color);
	std::string toString();
	bool isSafe();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
};


class Queen : public Figure {
public:
	Queen(Colours color);
	std::string toString();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
};


class Rook : public Figure {
public:
	Rook(Colours color);
	std::string toString();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
};


class Bishop : public Figure {
public:
	Bishop(Colours color);
	std::string toString();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
};


class Knight : public Figure {
public:
	Knight(Colours color);
	std::string toString();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
};


class Pawn : public Figure {
public:
	Pawn(Colours color);
	std::string toString();
	void upgrade();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
};

#endif
