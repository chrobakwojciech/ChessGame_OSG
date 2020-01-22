#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include "Colours.h"

class Figure {
	friend class Player;
public:
	virtual std::string toString() = 0;
	Colours getColour();
protected:
	Colours colour = Colours::BLACK;
};

#endif