/**
 * @file Kill.cpp
 * @brief Declaration of the Kill class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Kill.hpp"
#include "../Person/Humanoid.hpp"

Kill::Kill(Humanoid& humanoid) : Action(humanoid) {}

void Kill::execute(Field& f) {
	if(getHumanoid()->isAlive()) getHumanoid()->die(f);
}