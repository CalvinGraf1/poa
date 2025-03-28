/**
 * @file Boat.cpp
 * @brief Definition of the Boat class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include <algorithm>
#include "Boat.hpp"

const std::string Boat::BOAT_FULL = "Le bateau est plein.";

Boat::Boat(const std::string &name, const Bank &currentBank) : Container(name),
	currentBank(&currentBank) {}

void Boat::move(const Bank& to) { currentBank = &to; }

void Boat::addPerson(const Person *person) {
    if (getPeople().size() >= maxCapacity) throw std::runtime_error(BOAT_FULL);
    Container::addPerson(person);
}

bool Boat::hasDriver() const {
		return std::any_of(getPeople().begin(), getPeople().end(),
				[](const Person* person) { return person->canDrive();});
}

const Bank* Boat::getCurrentBank() const {
    return currentBank;
}

void Boat::setBank(const Bank *bank) {
    currentBank = bank;
}

std::string Boat::toString() const {
	std::string display = getName() + ": < ";
	if (isEmpty()) display += ">";
	else display += peopleToString() + " >";
	return display;
}

Container *Boat::clone() const {
    return new Boat(*this);
}

