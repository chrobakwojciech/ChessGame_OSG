#include "Figure.h"
#include "Colours.h"

#pragma once
using namespace std;

class King : public Figure {
public:
	King(Colours color);
	string toString();
	bool isSafe();
};


class Queen : public Figure {
public:
	Queen(Colours color);
	string toString();
};


class Rook : public Figure {
public:
	Rook(Colours color);
	string toString();
};


class Bishop : public Figure {
public:
	Bishop(Colours color);
	string toString();
};


class Knight : public Figure {
public:
	Knight(Colours color);
	string toString();
};


class Pawn : public Figure {
public:
	Pawn(Colours color);
	string toString();
	void upgrade();
};