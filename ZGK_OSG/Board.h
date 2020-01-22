#include "Colours.h"
#include "Figure.h"
#include <iostream>

#pragma once
using namespace std;

class Board {
protected:
	class BoardField {
	public:
		BoardField(Colours colour);
		void setFigure(Figure* figure);
		Colours colour;
		Figure *figure;
	};
private:
	BoardField *fields[8][8];
	void fillBoard();
public:
	Board();
	void printColours();
	void printFigures();
};
