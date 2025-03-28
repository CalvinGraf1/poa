/**
 * @file Action.cpp
 * @brief Declaration of the Action class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Action.hpp"

Action::Action(Humanoid &humanoid) : humanoid(&humanoid) {}

Humanoid* Action::getHumanoid() const {
	return humanoid;
}