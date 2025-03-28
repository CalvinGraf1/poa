/**
 * @file Action.hpp
 * @brief Definition of the Action class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LAB4_ACTION_HPP
#define LAB4_ACTION_HPP

class Field;
class Humanoid;

/**
 * @brief Class representing an action that a humanoid can execute on the field.
 */
class Action {
	Humanoid* humanoid;
public:
	/**
	 * @brief Constructor of the Action class.
	 * @param humanoid The humanoid that will execute the action.
	 */
	Action(Humanoid &humanoid);

	/**
	 * @brief Destructor of the Action class.
	 */
	virtual ~Action() = default;

	// Delete copy constructor and assignment operator of the action class
	Action(const Action&) = delete;
	Action& operator=(const Action&) = delete;

	/**
	 * @brief Getter for the humanoid of the action.
	 * @return The humanoid of the action.
	 */
	Humanoid* getHumanoid() const;

	/**
	 * @brief Execute the action of the humanoid on the field.
	 * @param f The field on which the action will be executed.
	 */
	virtual void execute(Field& f) = 0;
};


#endif //LAB4_ACTION_HPP


