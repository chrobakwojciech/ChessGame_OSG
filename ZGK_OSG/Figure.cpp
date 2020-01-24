#include "Figure.h"
#include "Colours.h"
#include <string>
#include "Board.h"

using namespace std;

osg::ref_ptr<osg::ShapeDrawable> Figure::getOBJ(Colours colour)
{
	return nullptr;
}

bool Figure::canMove(Board* board, int fromX, int fromY, int toX, int toY) {
	return false;
}

Colours Figure::getColour() {
	return this->colour;
}

