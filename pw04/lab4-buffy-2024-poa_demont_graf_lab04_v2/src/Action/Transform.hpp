/**
 * @file Transform.hpp
 * @brief Definition of the Transform class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef BUFFY_TRANSFORM_HPP
#define BUFFY_TRANSFORM_HPP

#include "Action.hpp"

/**
 * @brief Class representing the transformation of a human into a vampire.
 */
class Transform : public Action {
public:
	/**
	 * @brief Constructor of the Transform class.
	 * @param humanoid Humanoid to transform.
	 */
	explicit Transform(Humanoid& humanoid);

	void execute(Field& f) override;
};

#endif //BUFFY_TRANSFORM_HPP
