/**
 * @file Transform.cpp
 * @brief Declaration of the Transform class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Transform.hpp"
#include "../Person/Vampire.hpp"

Transform::Transform(Humanoid& humanoid) : Action(humanoid) {}

void Transform::execute(Field& f) {
	if (getHumanoid()->isAlive()) {
		getHumanoid()->die(f);
		f.addHumanoid(new Vampire(getHumanoid()->getPosition()));
		f.vampireBorn();
	}
}