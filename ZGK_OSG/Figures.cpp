#include "Figures.h"
#include "Figure.h"
#include "Colours.h"
#include <string>
#include <iostream>

using namespace std;
using namespace osg;

/* **********************************
                KING
********************************** */

Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);
Vec4* black = new Vec4(0.0, 0.0, 0.0, 1.0);
Vec4* white = new Vec4(1.0, 1.0, 1.0, 1.0);

King::King(Colours colour) {
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


ref_ptr<ShapeDrawable> King::getOBJ(Colours colour) {
	return nullptr;
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


ref_ptr<ShapeDrawable> Queen::getOBJ(Colours colour) {
	return nullptr;
}



/* **********************************
				PAWN
********************************** */

Pawn::Pawn(Colours colour) {
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


ref_ptr<ShapeDrawable> Pawn::getOBJ(Colours colour) {
	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 0.0), 4.0, 12.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	return drw;
}



/* **********************************
				ROOK
********************************** */

Rook::Rook(Colours colour) {
	this->colour = colour;
}

string Rook::toString() {
	return string("Rook");
}

bool Rook::canMove(Board* board, int fromX, int fromY, int toX, int toY) {
	return true;
}


ref_ptr<ShapeDrawable> Rook::getOBJ(Colours colour) {
	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 0.0), 3.0, 18.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	return drw;
}


/* **********************************
				BISHOP
********************************** */

Bishop::Bishop(Colours colour) {
	this->colour = colour;
}

string Bishop::toString() {
	return string("Bishop");
}

bool Bishop::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}

ref_ptr<ShapeDrawable> Bishop::getOBJ(Colours colour) {
	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 0.0), 4.0, 16.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	return drw;
}


/* **********************************
				KNIGHT
********************************** */

Knight::Knight(Colours colour) {
	this->colour = colour;
}

string Knight::toString() {
	return string("Knight");
}

bool Knight::canMove(Board* board, int fromX, int fromY, int toX, int toY)
{
	return false;
}

ref_ptr<ShapeDrawable> Knight::getOBJ(Colours colour) {
	return nullptr;
}