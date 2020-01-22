#include "Figures.h"
#include "Figure.h"
#include "Colours.h"
#include <string>
#include <iostream>

using namespace std;

/* **********************************
                KING
********************************** */

King::King(Colours color) {
	this->colour = colour;
}

string King::toString() {
	return string("King");
}

bool King::isSafe() {
	return false;
}

bool King::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}



/* **********************************
				QUEEN
********************************** */

Queen::Queen(Colours colour) {
	this->colour = colour;
}

string Queen::toString() {
	return string("Queen");
}

bool Queen::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}



/* **********************************
				PAWN
********************************** */

Pawn::Pawn(Colours color) {
	this->colour = colour;
}

string Pawn::toString() {
	return string("Pawn");
}

void Pawn::upgrade() {
}

bool Pawn::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}



/* **********************************
				ROOK
********************************** */

Rook::Rook(Colours color) {
	this->colour = colour;
}

string Rook::toString() {
	return string("Rook");
}

bool Rook::canMove(Board* board, int fromX, int fromY, int toX, int toY) {
	return true;
}

/* **********************************
				BISHOP
********************************** */

Bishop::Bishop(Colours color) {
	this->colour = colour;
}

string Bishop::toString() {
	return string("Bishop");
}

bool Bishop::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}



/* **********************************
				KNIGHT
********************************** */

Knight::Knight(Colours color) {
	this->colour = colour;
}

string Knight::toString() {
	return string("Knight");
}

bool Knight::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}
