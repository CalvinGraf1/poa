/**
 * @file Humanoid.cpp
 * @brief Declaration of the Humanoid class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Humanoid.hpp"

Humanoid::Humanoid(const Position& position) : position(position), alive(true),
action(nullptr) {}

Humanoid::~Humanoid() {
	delete action;
}

const Position& Humanoid::getPosition() const {
	return position;
}

void Humanoid::setPosition(Position pos) {
	this->position = pos;
}

bool Humanoid::isAlive() const {
	return alive;
}

void Humanoid::die(Field& field) {
	if(action != nullptr) {
		delete action;
		action = nullptr;
	}
	alive = false;
}

void Humanoid::setAction(Field& field) {
	this->action = getNextAction(field);
}

void Humanoid::executeAction(Field& field) {
		if (action != nullptr) {
			action->execute(field);
			delete action;
			action = nullptr;
		}
}