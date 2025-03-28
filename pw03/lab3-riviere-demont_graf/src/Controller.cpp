/**
 * @file Controller.cpp
 * @brief Definition of the Controller class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "Controller.hpp"

// region Constants
const std::string Controller::MSG_EMBARK_MSG_DISEMBARK = "Veuillez specifier le nom de la "
														  "personne a embarquer / debarquer.";
const std::string Controller::MSG_NOT_ON_BOAT_BANK = "La personne n'est pas sur la"
																	  " meme rive que le bateau.";
const std::string Controller::MSG_NOT_IN_GAME = "La personne ne fait pas partie du jeu.";
const std::string Controller::MSG_WIN = "Bravo, vous avez gagne !";
const std::string Controller::DISPLAY_DEF = " : afficher";
const std::string Controller::EMBARK_DEF = " <nom> : embarquer <nom>";
const std::string Controller::DISEMBARK_DEF = " <nom> : debarquer <nom>";
const std::string Controller::MOVE_DEF = " : deplacer bateau";
const std::string Controller::RESET_DEF = " : reinitialiser";
const std::string Controller::QUIT_DEF = " : quitter";
const std::string Controller::MENU_DEF = " : menu";
const std::string Controller::INVALID_CMD = "Commande invalide.";

const char Controller::DISPLAY = 'p';
const char Controller::EMBARK = 'e';
const char Controller::DISEMBARK = 'd';
const char Controller::MOVE = 'm';
const char Controller::RESET = 'r';
const char Controller::QUIT = 'q';
const char Controller::MENU = 'h';
// endregion

// region Méthodes privées

void Controller::showMenu() const {
	std::cout << DISPLAY << DISPLAY_DEF << std::endl;
	std::cout << EMBARK << EMBARK_DEF << std::endl;
	std::cout << DISEMBARK << DISEMBARK_DEF << std::endl;
	std::cout << MOVE << MOVE_DEF << std::endl;
	std::cout << RESET << RESET_DEF << std::endl;
	std::cout << QUIT << QUIT_DEF << std::endl;
	std::cout << MENU << MENU_DEF << std::endl;
}

void Controller::reset() {
	left->clear();
	right->clear();
   boat->clear();
   boat->setBank(left);
	turn = 0;
	for(auto person : people) left->addPerson(person);
    display();
}

void Controller::fill(const Bank* bank) const {
	std::cout << std::setfill('-') << std::setw(LENGTH_DISPLAY) << "-"
				 << std::endl;
	std::cout << bank->toString() << std::endl;
	std::cout << std::setfill('-') << std::setw(LENGTH_DISPLAY) << "-"
				 << std::endl;
}

void Controller::displayError(const std::string& error) const {
	std::cout << "### " << error << std::endl;
}

bool Controller::checkWin() const {
	return left->isEmpty() && boat->isEmpty();
}

void Controller::embark(const Person *person) {
	if (!boat->getCurrentBank()->contains(*person)) {
		displayError( MSG_NOT_ON_BOAT_BANK);
		return;
	}

	try {
		processMove(person, (Container *) boat->getCurrentBank(), boat);
	} catch (const std::runtime_error& e) {
		displayError(e.what());
	}
}

void Controller::disembark(const Person *person) {
	try {
		processMove(person, boat, (Container *) boat->getCurrentBank());
	} catch (const std::runtime_error& e) {
		displayError(e.what());
	}
}

void Controller::moveBoat(Bank * to) {
	if (boat->hasDriver()) {
		boat->move(*to);
		display();
	}
	else displayError("Le bateau ne peut pas bouger sans conducteur.");
}

const Person* Controller::findPerson(const std::string& name) const {
	auto iterator = std::find_if(people.begin(), people.end(),
										  [&name](const Person* p) { return p->getName() == name; });
	return iterator != people.end() ? *iterator : nullptr;
}

void Controller::movePerson(const Person *person, Container *from, Container *to) {
	from->removePerson(person);
	to->addPerson(person);
}

void Controller::processMove(const Person *person, Container *from, Container *to) {
	if (!validateContainerAfterRemoval(person, from) ||
		 !validateContainerAfterAdding(person, to)) {
		return;
	}

	movePerson(person, from, to);
	display();
}

bool Controller::validateContainerAfterRemoval(const Person *person, Container *container) {
    Container* containerCopy = container->clone();
    containerCopy->removePerson(person);

    return validateContainer(person, containerCopy);
}

bool Controller::validateContainerAfterAdding(const Person *person, Container *container) {
    Container* containerCopy = container->clone();;
    containerCopy->addPerson(person);

    return validateContainer(person, containerCopy);
}


bool Controller::validateContainer(const Person *person, Container *container){
	for (auto p : container->getPeople()) {
		Validation state = p->isValid(*container);
		if (!state.getState()) {
			displayError(state.getErrorMessage());
			return false;
		}
	}
	return true;
}

void Controller::nextTurn() {
	++turn;
}

const Person* Controller::canEmbarkDisembark(std::istringstream& iss) const {
	std::string personName;
	if (iss >> personName) {
		const Person* person = findPerson(personName);
		if (person == nullptr) {
			displayError(MSG_NOT_IN_GAME);
			return nullptr;
		}
		return person;
	}
	else {
		displayError(MSG_EMBARK_MSG_DISEMBARK);
		return nullptr;
	}
}

// endregion

// region Constructeur / Destructeur

Controller::Controller(std::initializer_list<const Person *> people) {
	this->people = people;
	left = new Bank("Gauche", this->people);
	right = new Bank("Droite");
	boat = new Boat("Bateau", *this->left);
}

Controller::~Controller() {
	delete left;
	delete right;
	delete boat;
}

// endregion

// region Méthodes publics

void Controller::run() {
	std::string inputLine, command;
	showMenu();
	display();

	while(!checkWin()) {
		command = "";
		std::cout << turn << "> " << std::flush;

		std::getline(std::cin, inputLine); // Lire toute la ligne d'entrée
		std::istringstream iss(inputLine);

		iss >> command; // Lire la commande principale (premier mot)

		if (command.empty()) {
            displayError(INVALID_CMD);
            continue;
        }

		switch (command[0]) {
			case DISPLAY:
				display();
				break;
			case EMBARK: {
				const Person* person = canEmbarkDisembark(iss);
				if (person != nullptr) embark(person);
				nextTurn();
				break;
			}
			case DISEMBARK: {
				const Person* person = canEmbarkDisembark(iss);
				if (person != nullptr) disembark(person);
				nextTurn();
				break;
			}
			case MOVE:;
				moveBoat(boat->getCurrentBank() == left ? right : left);
				nextTurn();
				break;
			case RESET:
				reset();
				break;
			case QUIT:
				return;
			case MENU:
				showMenu();
				break;
            default:
                displayError(INVALID_CMD);
                break;
		}
	}
	std::cout << MSG_WIN << std::endl;
}

void Controller::display() {
	fill(left);

	if(boat->getCurrentBank() == right)
		std::cout << std::setfill('=') << std::setw(LENGTH_DISPLAY) << "="
					 << std::endl;
	std::cout << boat->toString() << std::endl;
	if(boat->getCurrentBank() == left)
		std::cout << std::setfill('=') << std::setw(LENGTH_DISPLAY) << "="
					 << std::endl;

	fill(right);
}

// endregion


