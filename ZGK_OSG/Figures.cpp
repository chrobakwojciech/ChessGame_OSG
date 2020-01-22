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

bool King::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}

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

bool Bishop::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}

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


bool Rook::canMove(Board* board, int fromX, int fromY, int toX, int toY) {
	return true;
}