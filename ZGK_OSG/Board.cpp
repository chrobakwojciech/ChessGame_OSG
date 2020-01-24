#include "Board.h"
#include <iostream>
#include "Figures.h"
#include <iomanip>

#include <osg/Group>
#include <osg/ShapeDrawable>
#include <osg/Geode>
#include <osg/ref_ptr>

using namespace std;
using namespace osg;

Board::BoardField::BoardField(Colours colour) {
	this->colour = colour;
	this->figure = nullptr;
	this->field_OBJ = nullptr;
}

void Board::BoardField::setFigure(Figure* figure) {
	this->figure = figure;
}

void Board::fillBoard() {
	// wypelniamy od lewego gornego rogu 
	// gora to czarni, dol to biali
	// zaczynamy od bialego pola (lewy gorny)

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					this->fields[i][j] = new BoardField(Colours::WHITE);
				}
				else {
					this->fields[i][j] = new BoardField(Colours::BLACK);
				}
			}
			else {
				if (j % 2 == 0) {
					this->fields[i][j] = new BoardField(Colours::BLACK);
				}
				else {
					this->fields[i][j] = new BoardField(Colours::WHITE);
				}
			}
		}
	}

	// BLACK - TOP
	this->fields[0][0]->setFigure(new Rook(Colours::BLACK));
	this->fields[0][1]->setFigure(new Knight(Colours::BLACK));
	this->fields[0][2]->setFigure(new Bishop(Colours::BLACK));
	this->fields[0][3]->setFigure(new Queen(Colours::BLACK));
	this->fields[0][4]->setFigure(new King(Colours::BLACK));
	this->fields[0][5]->setFigure(new Bishop(Colours::BLACK));
	this->fields[0][6]->setFigure(new Knight(Colours::BLACK));
	this->fields[0][7]->setFigure(new Rook(Colours::BLACK));

	for (int i = 0; i < 8; i++) {
		this->fields[1][i]->setFigure(new Pawn(Colours::BLACK));
	}

	// WHITE - BOTTOM
	this->fields[7][0]->setFigure(new Rook(Colours::WHITE));
	this->fields[7][1]->setFigure(new Knight(Colours::WHITE));
	this->fields[7][2]->setFigure(new Bishop(Colours::WHITE));
	this->fields[7][3]->setFigure(new Queen(Colours::WHITE));
	this->fields[7][4]->setFigure(new King(Colours::WHITE));
	this->fields[7][5]->setFigure(new Bishop(Colours::WHITE));
	this->fields[7][6]->setFigure(new Knight(Colours::WHITE));
	this->fields[7][7]->setFigure(new Rook(Colours::WHITE));

	for (int i = 0; i < 8; i++) {
		this->fields[6][i]->setFigure(new Pawn(Colours::WHITE));
	}
}

void Board::createOBJ() {
	this->width_OBJ = 100.0;
	this->height_OBJ = 100.0;
	this->size_OBJ = 10.0;
	this->frame_OBJ = 20.0;

	Vec4* dark = new Vec4(0.05, 0.05, 0.05, 1.0);
	Vec4* black = new Vec4(0.0, 0.0, 0.0, 1.0);
	Vec4* white = new Vec4(1.0, 1.0, 1.0, 1.0);
	Vec4* red = new Vec4(1.0, 0.0, 0.0, 1.0);


	this->board_OBJ = new Group;
	ref_ptr<Geode> geom_node = new Geode;

	ShapeDrawable* drw = new ShapeDrawable();
	drw->setShape(new Box(Vec3(0.0, 0.0, 0.0), this->width_OBJ + this->frame_OBJ * 2, this->height_OBJ + this->frame_OBJ * 2, this->size_OBJ));
	drw->setColor(*dark);
	geom_node->addDrawable(drw);

	drw = new ShapeDrawable();
	drw->setShape(new Box(Vec3(0.0, 0.0, this->size_OBJ / 2.0), this->width_OBJ + 2.0, this->height_OBJ + 2.0, 0.04));
	drw->setColor(*white);
	geom_node->addDrawable(drw);

	ShapeDrawable* temp = nullptr;
	ShapeDrawable* temp2 = nullptr;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			drw = new ShapeDrawable();
			Vec3* center = new Vec3(-this->width_OBJ / 2.0 + j * 12.5 + 12.5 / 2.0, -this->height_OBJ / 2.0 + i * 12.5 + 12.5 / 2.0, this->size_OBJ / 2.0);
			drw->setShape(new Box(*center, 12.5, 12.5, 0.05));
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					drw->setColor(*white);
				}
				else {
					drw->setColor(*black);
				}
			}
			else {
				if (j % 2 == 0) {
					drw->setColor(*black);
				}
				else {
					drw->setColor(*white);
				}
			}
			if (i == 2 && j == 2) {
				temp = drw;
			}
			if (i == 3 && j == 2) {
				temp2 = drw;
			}
			geom_node->addDrawable(drw);

		}
	}

	if (temp != nullptr) {
		temp->setColor(Vec4(191.0 / 255.0, 255.0 / 255.0, 191.0 / 255.0, 1.0));
	}
	if (temp2 != nullptr) {
		temp2->setColor(Vec4(7.0 / 255.0, 69.0 / 255.0, 6.0 / 255.0, 1.0));
	}

	this->board_OBJ.get()->addChild(geom_node);
}

Board::Board() {
	this->fillBoard();
	this->createOBJ();	
}

void Board::printColours() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			switch (this->fields[i][j]->colour) {
				case Colours::BLACK:
					cout << "[B] ";
					break;
				case Colours::WHITE:
					cout << "[W] ";
					break;
			}
		}
		cout << endl;
	}
}

void Board::printFigures() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->fields[i][j]->figure == nullptr) {
				cout << setw(11) << " ";
			}
			else {
				string color;
				switch (this->fields[i][j]->colour) {
					case Colours::BLACK:
						color = "[B]";
						break;
					case Colours::WHITE:
						color = "[W]";
						break;
				}

				cout << color << " " << setw(7) << left << this->fields[i][j]->figure->toString();
			}
		}
		cout << endl;
	}
}

