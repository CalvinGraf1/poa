/**
 * @file statisticsCalculator.hpp
 * @brief Definition of the statisticsCalculator class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef BUFFY_STATISTICSCALCULATOR_HPP
#define BUFFY_STATISTICSCALCULATOR_HPP

#include "../Field/Field.hpp"

/**
 * @brief Struct representing a statistics calculator.
 */
struct statisticsCalculator {

	/**
	 * @brief Simulate the game with the given parameters.
	 * @param width The width of the field.
	 * @param height The height of the field.
	 * @param nbHuman The number of humans on the field.
	 * @param nbVampire The number of vampires on the field.
	 * @param nbSimulations The number of simulations to run.
	 * @return Buffy's average win rate percentage in simulations.
	 */
	static double simulate(size_t width, size_t height, size_t nbHuman,
								  size_t nbVampire, size_t nbSimulations);
};

#endif //BUFFY_STATISTICSCALCULATOR_HPP
