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


ref_ptr<ShapeDrawable> King::getOBJ(Colours colour) {

	Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);
	Vec4* black = new Vec4(0.0, 0.0, 0.0, 1.0);
	Vec4* white = new Vec4(1.0, 1.0, 1.0, 1.0);

	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Capsule(Vec3(12.5 / 2.0, 12.5 / 2.0, 0.0), 5.0, 18.0));
	if (colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	return drw;
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
	Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);
	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 100.0 / 2.0 + 7.0), 7.0, 21.0));
	drw->setColor(*red);
	return drw;
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


ref_ptr<ShapeDrawable> Pawn::getOBJ(Colours colour) {
	Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);
	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 100.0 / 2.0 + 7.0), 7.0, 21.0));
	drw->setColor(*red);
	return drw;
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


ref_ptr<ShapeDrawable> Rook::getOBJ(Colours colour) {
	Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);
	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 100.0 / 2.0 + 7.0), 7.0, 21.0));
	drw->setColor(*red);
	return drw;
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

ref_ptr<ShapeDrawable> Bishop::getOBJ(Colours colour) {
	Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);
	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 100.0 / 2.0 + 7.0), 7.0, 21.0));
	drw->setColor(*red);
	return drw;
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

ref_ptr<ShapeDrawable> Knight::getOBJ(Colours colour) {
	Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);
	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 100.0 / 2.0 + 7.0), 7.0, 21.0));
	drw->setColor(*red);
	return drw;
}