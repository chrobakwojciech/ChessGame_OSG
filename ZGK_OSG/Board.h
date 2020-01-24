#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Figure.h"
#include "Colours.h"
#include <osg/Group>
#include <osg/ref_ptr>

class Figure;

class Board {
	friend class Player;
	friend class ChessGame;
protected:
	class BoardField {
	public:
		osg::ref_ptr<osg::Group> field_OBJ;
		BoardField(Colours colour);
		void setFigure(Figure* figure);
		Colours colour;
		Figure* figure;
	};
private:
	double width_OBJ;
	double height_OBJ;
	double size_OBJ;
	double frame_OBJ;
	osg::ref_ptr<osg::Group> board_OBJ;

	BoardField *fields[8][8];
	void fillBoard();
	void createOBJ();
public:
	Board();
	void printColours();
	void printFigures();
};

#endif