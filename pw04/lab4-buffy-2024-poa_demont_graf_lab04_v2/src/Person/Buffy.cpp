/**
 * @file Buffy.cpp
 * @brief Declaration of the Buffy class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include <iostream>
#include "Buffy.hpp"
#include "Human.hpp"

Buffy::Buffy(const Position& position) : Humanoid(position) {}

Action* Buffy::getNextAction(const Field& field) {
	if(field.getNbVampire() == 0) return new Move(Human::getMoveRange(),
																 *this);

	Humanoid* target = field.findClosest<Vampire>(*this);
	if(target->getPosition().distance(this->getPosition()) <= KILL_RANGE)
		return new Kill(*target);
	return new Move(MOVE_RANGE, *this, target);
}

char Buffy::display() const {
	return 'B';
}
