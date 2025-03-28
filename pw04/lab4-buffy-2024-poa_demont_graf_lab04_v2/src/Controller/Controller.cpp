/**
 * @file Controller.cpp
 * @brief Declaration of the Controller class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include <iostream>
#include "Controller.hpp"
#include "../Statistics/statisticsCalculator.hpp"

Controller::Controller(const size_t width, const size_t height, size_t nbHumans,
							  size_t nbVampires) : field(width, height, nbHumans,
							  nbVampires), display(field), finished(false)
{}

void Controller::run() {
	display.print();
	display.printPrompt();
	while(!finished) handleCommand();
}

void Controller::handleCommand() {
	char command;
	std::cin >> command;
	switch(command) {
		case Controller::QUIT:
			quit();
			break;
		case Controller::STATISTICS:
			statistics();
			break;
		case Controller::NEXT:
			nextTurn();
			break;
		default:
			std::cout << "Invalid command" << std::endl;
			break;
	}
	if(!finished) display.printPrompt();
}

void Controller::nextTurn() {
	field.nextTurn();
	display.print();
	//display.clear();
}

void Controller::quit() {
	finished = true;
}

void Controller::statistics() {
	std::cout << NB_SIMULATIONS << " simulations in progress..." << std::endl;
	double res = statisticsCalculator::simulate(field.getWidth(),
					 field.getHeight(),field.getNbHuman(),
					 field.getNbVampire(), NB_SIMULATIONS);
	std::cout << "Buffy's win rate: " << res << "%" << std::endl;
}
