#include "Figures.h"
#include "Figure.h"
#include "Colours.h"
#include <string>
#include <iostream>

using namespace std;

King::King(Colours color) {
	this->colour = colour;
}

string King::toString() {
	return string("King");
}

bool King::isSafe() {
	return false;
}

Queen::Queen(Colours colour) {
	this->colour = colour;
}

string Queen::toString() {
	return string("Queen");
}

Pawn::Pawn(Colours color) {
	this->colour = colour;
}

string Pawn::toString() {
	return string("Pawn");
}

void Pawn::upgrade() {
}

Rook::Rook(Colours color) {
	this->colour = colour;
}

string Rook::toString() {
	return string("Rook");
}

Bishop::Bishop(Colours color) {
	this->colour = colour;
}

string Bishop::toString() {
	return string("Bishop");
}

Knight::Knight(Colours color) {
	this->colour = colour;
}

string Knight::toString() {
	return string("Knight");
}
