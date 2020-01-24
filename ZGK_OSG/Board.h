#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Figure.h"
#include "Colours.h"
#include <osg/Group>
#include <osg/ShapeDrawable>
#include <osg/ref_ptr>

class Figure;

class Board {
	friend class Player;
	friend class ChessGame;
	friend class BoardField;
protected:
	class BoardField {

	public:
		osg::ref_ptr<osg::ShapeDrawable> field_OBJ;
		osg::ref_ptr<osg::ShapeDrawable> figure_OBJ;
		BoardField(Colours colour, int i, int j, Board* board);
		void setFigure(Figure* figure);
		Colours colour;
		Figure* figure;
	private:
		void createOBJ(int i, int j);
		void setFigureOBJ(Colours colour);
		Board* board;
	};
private:
	double width_OBJ;
	double height_OBJ;
	double size_OBJ;
	double frame_OBJ;
	osg::ref_ptr<osg::Group> board_OBJ;
	osg::ref_ptr<osg::Group> figures_OBJ;

	BoardField *fields[8][8];
	void fillBoard();
	void createOBJ();
public:
	Board();
	void renderFiguresOBJ();
	void printColours();
	void printFigures();
};

#endif