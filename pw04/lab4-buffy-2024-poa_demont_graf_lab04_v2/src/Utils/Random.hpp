/**
 * @file Random.hpp
 * @brief Definition of the Random class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef BUFFY_RANDOM_HPP
#define BUFFY_RANDOM_HPP

#include <random>

/**
 * @brief Class representing a random number generator.
 */
class Random {
	static std::mt19937 gen;
public:
	/**
	 * Generate a random integer between min (including) and max (not including)
	 * @param min the minimum value
	 * @param max the maximum value
	 * @return a random integer between min and max
	 */
	static int generateInt(int min, int max);

	/**
	 * Generate a random integer between 0 (including) and max (not including)
	 * @param max the maximum value
	 * @return a random integer between 0 and max
	 */
	static int generateInt(int max);

	/**
	 * Generate a random boolean
	 * @return a random boolean
	 */
	static bool generateBool();
};

#endif //BUFFY_RANDOM_HPP
