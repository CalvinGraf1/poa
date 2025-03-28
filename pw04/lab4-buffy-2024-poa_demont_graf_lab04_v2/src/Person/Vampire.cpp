/**
 * @file Vampire.cpp
 * @brief Declaration of the Vampire class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Vampire.hpp"
#include "../Utils/Random.hpp"
#include "../Action/Transform.hpp"

Vampire::Vampire(const Position& position) : Humanoid(position) {}

Action* Vampire::getNextAction(const Field& field) {
	 if(field.getNbHuman() == 0) return nullptr;

	 Human* target = field.findClosest<Human>(*this);

	 if(target->getPosition().distance(this->getPosition()) <= KILL_RANGE) {
		if(Random::generateBool()) return new Kill(*target);
		else return new Transform(*target);
	}
	 return new Move(MOVE_RANGE, *this, target);
}

char Vampire::display() const {
	return 'V';
}

void Vampire::die(Field& field) {
	Humanoid::die(field);
	field.vampireDie();
}
