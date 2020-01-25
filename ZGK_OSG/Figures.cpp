#include "Figures.h"
#include "Figure.h"
#include "Colours.h"
#include <string>
#include <iostream>

#include <osg/MatrixTransform>
#include <osg/Geode>

using namespace std;
using namespace osg;

/* **********************************
                KING
********************************** */

Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);
Vec4* black = new Vec4(0.1, 0.1, 0.1, 1.0);
Vec4* white = new Vec4(0.9, 0.9, 0.9, 1.0);
Vec4* gold = new Vec4(0.85, 0.64, 0.12, 1.0);

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
	return true;
}

ref_ptr<Group> King::getOBJ(Colours colour) {
	ref_ptr<Group> g = new Group;

	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 0.0), 4.0, 2.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 1.0), 3.85, 3.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 1.0), 2.85, 15.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	ref_ptr<Cone> cone = new Cone(Vec3(0.0, 0.0, 10.0), 2.5, 15.0);
	cone.get()->setRotation(Quat(PI, X_AXIS));
	drw->setShape(cone);
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 4.0), 1.6, 0.24));
	drw->setColor(*gold);
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 5.0), 1.5, 5.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 7.5), 1.6, 0.24));
	drw->setColor(*gold);
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Sphere(Vec3(0.0, 0.0, 13.5), 1.5));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Box(Vec3(0.0, 0.0, 15.5), 0.4, 0.4, 3.0));
	drw->setColor(*gold);
	g.get()->addChild(drw);

	drw = new ShapeDrawable;
	drw->setShape(new Box(Vec3(0.0, 0.0, 16.0), 2.0, 0.4, 0.4));
	drw->setColor(*gold);
	g.get()->addChild(drw);


	return g;
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
	return true;
}

ref_ptr<Group> Queen::getOBJ(Colours colour) {
	ref_ptr<Group> g = new Group;

	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 0.0), 4.0, 2.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 1.0), 3.85, 3.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 1.0), 2.85, 15.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	ref_ptr<Cone> cone = new Cone(Vec3(0.0, 0.0, 10.0), 2.5, 15.0);
	cone.get()->setRotation(Quat(PI, X_AXIS));
	drw->setShape(cone);
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 6.0), 1.5, 0.24));
	drw->setColor(*gold);
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Sphere(Vec3(0.0, 0.0, 13.5), 1.5));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Sphere(Vec3(0.0, 0.0, 15.5), 0.5));
	drw->setColor(*gold);
	g.get()->addChild(drw);


	return g;
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
	return true;
}

ref_ptr<Group> Pawn::getOBJ(Colours colour) {
	ref_ptr<Group> g = new Group;

	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 0.0), 4.0, 2.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 2.0), 3.75, 10.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 5.0), 2.0, 2.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Sphere(Vec3(0.0, 0.0, 9.0), 1.5));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);

	return g;
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

ref_ptr<Group> Rook::getOBJ(Colours colour) {
	ref_ptr<Group> g = new Group;

	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 0.0), 4.0, 2.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 2.0), 3.75, 15.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 6.0), 2.3, 15.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);

	drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 13.0), 2.6, 1.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);

	drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 14.0), 3.0, 2.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);

	return g;
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
	return true;
}

ref_ptr<Group> Bishop::getOBJ(Colours colour) {
	ref_ptr<Group> g = new Group;

	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 0.0), 4.0, 2.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	drw->setShape(new Cone(Vec3(0.0, 0.0, 2.0), 3.75, 15.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	ref_ptr<MatrixTransform> sph_t = new MatrixTransform;
	sph_t.get()->setMatrix(Matrix::scale(1.0, 1.0, 2.2));
	ref_ptr<Sphere> sphere = new Sphere(Vec3(0.0, 0.0, 4.0), 2.5);
	

	drw->setShape(sphere);
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	sph_t.get()->addChild(drw);

	g.get()->addChild(sph_t);



	drw = new ShapeDrawable;
	drw->setShape(new Sphere(Vec3(0.0, 0.0, 14.5), 0.5));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);

	
	return g;
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
	return true;
}

ref_ptr<Group> Knight::getOBJ(Colours colour) {
	ref_ptr<Group> g = new Group;

	ref_ptr<ShapeDrawable> drw = new ShapeDrawable;
	drw->setShape(new Cylinder(Vec3(0.0, 0.0, 0.0), 4.0, 2.0));
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	ref_ptr<MatrixTransform> sph_t = new MatrixTransform;
	ref_ptr<Sphere> sphere = new Sphere(Vec3(0.0, 0.0, 3.0), 3.0);
	drw->setShape(sphere);
	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
	}
	else {
		drw->setColor(*white);
	}
	sph_t.get()->addChild(drw);

	sph_t.get()->setMatrix(Matrix::scale(1.0, 1.0, 0.3));
	g.get()->addChild(sph_t);



	drw = new ShapeDrawable;
	ref_ptr<Capsule> cap = new Capsule(Vec3(0.0, 0.0, 5.0), 2.0, 10.0);

	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
		cap.get()->setRotation(Quat(PI_2 / 4.0, X_AXIS));
		cap.get()->setCenter(Vec3(0.0, -1.0, 5.0));
	}
	else {
		drw->setColor(*white);
		cap.get()->setRotation(Quat(-PI_2 / 4.0, X_AXIS));
		cap.get()->setCenter(Vec3(0.0, 1.0, 5.0));
	}
	drw->setShape(cap);
	g.get()->addChild(drw);


	drw = new ShapeDrawable;
	ref_ptr<Cone> cone = new Cone(Vec3(0.0, 0.0, 7.5), 2.0, 7.0);

	if (this->colour == Colours::BLACK) {
		drw->setColor(*black);
		cone.get()->setRotation(Quat(-PI * 0.65, X_AXIS));
		cone.get()->setCenter(Vec3(0.0, -1.0, 7.5));
	}
	else {
		drw->setColor(*white);
		cone.get()->setRotation(Quat(PI * 0.65, X_AXIS));
		cone.get()->setCenter(Vec3(0.0, 1.0, 7.5));
	}

	drw->setShape(cone);
	g.get()->addChild(drw);
	






	return g;
}
