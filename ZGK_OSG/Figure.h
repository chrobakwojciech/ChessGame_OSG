#include "Colours.h"
#include <string>

#pragma once
using namespace std;

class Figure {
public:
	virtual string toString() = 0;
	Colours getColour();
protected:
	Colours colour = Colours::BLACK;
};

