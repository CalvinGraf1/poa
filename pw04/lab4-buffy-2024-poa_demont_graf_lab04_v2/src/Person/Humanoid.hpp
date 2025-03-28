/**
 * @file Humanoid.hpp
 * @brief Definition of the Humanoid class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LAB4_HUMANOIDE_HPP
#define LAB4_HUMANOIDE_HPP

#include "../Utils/Position.hpp"
#include "../Action/Action.hpp"

class Field;

/**
 * @brief Class representing a humanoid on the field.
 */
class Humanoid {
	Position position;
	bool alive;
	Action* action;

	public:
	/**
	 * @brief Constructor of the Humanoid class.
	 * @param pos The position of the humanoid.
	 */
	explicit Humanoid(const Position& pos);

	// Delete copy constructor and assignment operator of the humanoid class
	Humanoid(const Humanoid&) = delete;
	Humanoid& operator=(const Humanoid&) = delete;

	/**
	 * @brief Destructor of the Humanoid class.
	 */
	virtual ~Humanoid();

	/**
	 * @brief Getter for the position of the humanoid.
	 * @return The position of the humanoid.
	 */
	const Position& getPosition() const;

	/**
	 * @brief Setter for the position of the humanoid.
	 * @param pos The new position of the humanoid.
	 */
	void setPosition(Position pos);

	/**
	 * @brief Check if the humanoid is alive.
	 * @return True if the humanoid is alive, false otherwise.
	 */
	bool isAlive() const;

	/**
	 * @brief Kill the humanoid.
	 * @param field The field on which the humanoid is.
	 */
	virtual void die(Field& field);

	/**
	 * @brief Set the action of the humanoid.
	 * @param field The field on which the humanoid is.
	 */
	void setAction(Field& field);

	/**
	 * @brief Execute the action of the humanoid on the field.
	 * @param field The field on which the action will be executed.
	 */
	void executeAction(Field& field);

	/**
	 * @brief Get the next action of the humanoid.
	 * @param field The field on which the humanoid is.
	 * @return The next action of the humanoid.
	 */
	virtual Action* getNextAction(const Field& field) = 0;

	/**
	 * @brief Display the humanoid on the field.
	 * @return The character representing the humanoid on the field.
	 */
	virtual char display() const = 0;
};

#endif //LAB4_HUMANOIDE_HPP
