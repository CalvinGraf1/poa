/**
 * @file Move.hpp
 * @brief Definition of the Move class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef BUFFY_MOVE_HPP
#define BUFFY_MOVE_HPP

#include "Action.hpp"
#include <vector>
#include "../Utils/Position.hpp"

class Humanoid;

/**
 * @brief Class representing the action of moving a humanoid.
 */
class Move : public Action {
	size_t range;
	const Humanoid* target;
public:
	/**
	 * @brief Constructor of the Move class.
	 * @param range The range of the move.
	 * @param humanoid The humanoid that will execute the move.
	 * @param target The target of the move.
	 */
	explicit Move(const size_t range, Humanoid& humanoid,
		           const Humanoid* target = nullptr);

	/**
	 * @brief Execute the move of the humanoid on the field.
	 * @param field The field on which the move will be executed.
	 */
	std::vector<const Position*> getDirectionsPossible(const Position& pos,
																 const Field& field) const;

	void execute(Field& field) override;
};

#endif //BUFFY_MOVE_HPP
