/**
 * @file Human.cpp
 * @brief Declaration of the Human class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include <iostream>
#include "Human.hpp"
#include "../Action/Move.hpp"
#include "../Field/Field.hpp"

Human::Human(const Position& position)
	: Humanoid(position) {}

Action* Human::getNextAction(const Field& field) {
	return new Move(MOVE_RANGE, *this);
}

char Human::display() const {
	return 'h';
}

size_t Human::getMoveRange() {
	return MOVE_RANGE;
}

void Human::die(Field& field) {
	Humanoid::die(field);
	field.humanDie();
}
