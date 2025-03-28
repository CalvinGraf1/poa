/**
 * @file Random.cpp
 * @brief Declaration of the Random class and related operators.
 * @authors Demont Kilian & Graf Calvin
*/

#include <stdexcept>
#include "Random.hpp"

std::mt19937 Random::gen = std::mt19937(std::random_device()());

int Random::generateInt(int max) {
	return generateInt(0, max);
}

int Random::generateInt(int min, int max) {
	if(max <= min) throw std::invalid_argument("Max must be greater or equal than "
															 "min");
	std::uniform_int_distribution<int> dist(min, max - 1);
	return dist(gen);
}

bool Random::generateBool() {
	// Generate a random integer between 0 and 1 (generateInt not including max)
	return generateInt(0, 2);
}
