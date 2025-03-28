/**
 * @file statisticsCalculator.cpp
 * @brief Declaration of the statisticsCalculator class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "statisticsCalculator.hpp"

double statisticsCalculator::simulate(size_t width, size_t height, size_t nbHuman,
												  size_t nbVampire, size_t nbSimulations) {
	if(nbSimulations == 0 || nbHuman == 0) return 0;
	if(nbVampire == 0) return 100;

	size_t success = 0;
	for (size_t i = 0; i < nbSimulations; ++i) {
		Field simulatingField(width, height, nbHuman, nbVampire);
		while (simulatingField.getNbVampire() > 0) simulatingField.nextTurn();
		if (simulatingField.getNbHuman() > 0) success++;
	}
	return static_cast<double>(success) / static_cast<double>(nbSimulations) * 100;
}