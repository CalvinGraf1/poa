/**
 * @file Display.cpp
 * @brief Declaration of the Display class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include <iostream>
#include <iomanip>
#include "Display.hpp"
#include "../Controller/Controller.hpp"

Display::Display(const Field& field) : field(field), gameBoard(field.getHeight(),
   		       std::vector<const Humanoid*>(field.getWidth(),nullptr))
{}

void Display::print() {
	const Humanoid** toDisplay = nullptr;
	for(Humanoid* h : field.getHumanoids()) {
		gameBoard.at(h->getPosition().getY())
					.at(h->getPosition().getX()) = h;
	}
	printHorizontalBorder(field);

	for(size_t y = 0; y < field.getHeight(); y++) {
		std::cout << VERTICAL_BORDER;
		for(size_t x = 0; x < field.getWidth(); x++) {
			toDisplay = &gameBoard.at(y).at(x);
			if(*toDisplay) std::cout << (*(*toDisplay)).display();
			else std::cout << EMPTY;
		}
		std::cout << VERTICAL_BORDER << std::endl;
	}
	printHorizontalBorder(field);
	clearGameBoard();
}
/*
void Display::clear() const {
#ifdef _WIN32
	system("cls");
#elif __unix__
	system("clear");
#endif
}
*/

void Display::clearGameBoard() {
	for(auto& line : gameBoard) {
		for(auto& cell : line) cell = nullptr;
	}
}

void Display::printHorizontalBorder(const Field& field) const {
	std::cout << CORNER << std::setfill(HORIZONTAL_BORDER)
		  << std::setw((size_t)field.getWidth() + 1) << CORNER << std::endl;
}

void Display::printPrompt() const {
	std::cout << "[" << field.getTurn() << "] "
		<< Controller::QUIT << ">uit "
		<< Controller::STATISTICS << ">tatistics "
		<< Controller::NEXT << ">ext: ";
}