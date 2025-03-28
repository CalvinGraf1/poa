/**
 * @file Human.hpp
 * @brief Definition of the Human class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LAB4_HUMAIN_HPP
#define LAB4_HUMAIN_HPP

#include "Humanoid.hpp"

/**
 * @brief Class representing a human.
 * @details A human can only move
 */
class Human : public Humanoid {
	static constexpr size_t MOVE_RANGE = 1;
public:
	/**
	 * @brief Constructor of the Human class.
	 * @param position The position of the human.
	 */
	Human(const Position& position);

	/**
	 * @brief Get the move range of the human.
	 * @return The move range of the human.
	 */
	static size_t getMoveRange();

	Action* getNextAction(const Field& field) override;

	char display() const override;

	void die(Field& field) override;
};

#endif //LAB4_HUMAIN_HPP
