/**
 * @file Vampire.hpp
 * @brief Definition of the Vampire class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LAB4_VAMPIRE_HPP
#define LAB4_VAMPIRE_HPP

#include "Humanoid.hpp"
#include "../Field/Field.hpp"

/**
 * @brief Class representing a vampire on the field.
 * @details A vampire can kill or transform a human if he is close enough,
 * 			otherwise he will move towards the closest human.
 */
class Vampire : public Humanoid {
	static constexpr size_t KILL_RANGE = 1;
	static constexpr size_t MOVE_RANGE = 1;
public:
	/**
	 * @brief Constructor of the Vampire class.
	 * @param position The position of the vampire.
	 */
	Vampire(const Position& position);

	Action* getNextAction(const Field& field) override;

	char display() const override;

	void die(Field& field) override;
};

#endif //LAB4_VAMPIRE_HPP
