#include "Board.h"
#include <iostream>
#include "Figures.h"
#include <iomanip>


using namespace std;

Board::BoardField::BoardField(Colours colour) {
	this->colour = colour;
	this->figure = nullptr;
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

Board::Board() {
	this->fillBoard();
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

