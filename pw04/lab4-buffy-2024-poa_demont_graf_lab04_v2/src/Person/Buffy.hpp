/**
 * @file Buffy.hpp
 * @brief Definition of the Buffy class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LAB4_BUFFY_HPP
#define LAB4_BUFFY_HPP

#include "Humanoid.hpp"
#include "Vampire.hpp"
#include "../Action/Kill.hpp"
#include "../Action/Move.hpp"

/**
 * @brief Class representing a Buffy.
 * @details A Buffy is a humanoid that can kill vampires.
 */
class Buffy : public Humanoid {
	static constexpr size_t KILL_RANGE = 1;
	static constexpr size_t MOVE_RANGE = 2;

public:
	/**
	 * @brief Constructor of the Buffy class.
	 * @param position The position of the Buffy.
	 */
	Buffy(const Position& position);

	char display() const override;

	Action* getNextAction(const Field& field) override;
};

#endif //LAB4_BUFFY_HPP
