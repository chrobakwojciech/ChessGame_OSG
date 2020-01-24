#ifndef FIGURES_H
#define FIGURES_H

#include "Colours.h"
#include "Figure.h"
#include "Board.h"

#include <osg/ShapeDrawable>
#include <osg/ref_ptr>

class King : public Figure {
public:
	King(Colours color);
	std::string toString();
	bool isSafe();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
	osg::ref_ptr<osg::ShapeDrawable> getOBJ(Colours colour);
};


class Queen : public Figure {
public:
	Queen(Colours color);
	std::string toString();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
	osg::ref_ptr<osg::ShapeDrawable> getOBJ(Colours colour);
};


class Rook : public Figure {
public:
	Rook(Colours color);
	std::string toString();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
	osg::ref_ptr<osg::ShapeDrawable> getOBJ(Colours colour);
};


class Bishop : public Figure {
public:
	Bishop(Colours color);
	std::string toString();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
	osg::ref_ptr<osg::ShapeDrawable> getOBJ(Colours colour);
};


class Knight : public Figure {
public:
	Knight(Colours color);
	std::string toString();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
	osg::ref_ptr<osg::ShapeDrawable> getOBJ(Colours colour);
};


class Pawn : public Figure {
public:
	Pawn(Colours color);
	std::string toString();
	void upgrade();
	bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
	osg::ref_ptr<osg::ShapeDrawable> getOBJ(Colours colour);
};

#endif
