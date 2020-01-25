#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include "Colours.h"
#include "Board.h"
#include <osg/ShapeDrawable>
#include <osg/Group>
#include <osg/ref_ptr>

class Board;

class Figure {
	friend class Player;
public:
	virtual std::string toString() = 0;
	virtual osg::ref_ptr<osg::Group> getOBJ(Colours colour);
	virtual bool canMove(Board* board, int fromX, int fromY, int toX, int toY);
	Colours getColour();
protected:
	Colours colour = Colours::BLACK;
};

#endif