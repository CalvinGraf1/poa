/**
 * @file Kill.hpp
 * @brief Definition of the Kill class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef BUFFY_KILL_HPP
#define BUFFY_KILL_HPP

#include "Action.hpp"

/**
 * @brief Class representing the action of killing a humanoid.
 */
class Kill : public Action {
public:
	/**
	 * @brief Constructor of the Kill class.
	 * @param humanoid The humanoid that will execute the action.
	 */
	explicit Kill(Humanoid& humanoid);

	void execute(Field& f) override;
};

#endif //BUFFY_KILL_HPP
