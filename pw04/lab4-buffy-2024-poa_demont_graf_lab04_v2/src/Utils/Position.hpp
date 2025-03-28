/**
 * @file Position.hpp
 * @brief Definition of the Position class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LAB4_POSITION_HPP
#define LAB4_POSITION_HPP

#include <cstddef>

/**
 * @brief Class representing a position
 */
class Position {
	size_t x, y;

public:
	/**
	 * @brief Static positions representing the 8 directions.
	 */
	static const Position
		UP,
		UP_RIGHT,
		RIGHT,
		DOWN_RIGHT,
		DOWN,
		DOWN_LEFT,
		LEFT,
		UP_LEFT;

	/**
	 * @brief Default constructor of the Position class.
	 */
	Position();

	/**
	 * @brief Constructor of the Position class.
	 * @param x The x coordinate of the position.
	 * @param y The y coordinate of the position.
	 */
	Position(size_t x, size_t y);

	/**
	 * @brief Getter for the x coordinate of the position.
	 * @return The x coordinate of the position.
	 */
	size_t getX() const;

	/**
	 * @brief Getter for the y coordinate of the position.
	 * @return The y coordinate of the position.
	 */
	size_t getY() const;

	/**
	 * @brief Compute the distance between two positions.
	 * @param pos The position to which the distance will be computed.
	 * @return The distance between the two positions.
	 */
	size_t distance(const Position & pos) const;

	/**
	 * @brief Get the direction to go to reach a position.
	 * @param pos The current position.
	 * @return The position to go to reach the given position.
	 */
	Position getDirection(const Position& pos) const;

	/**
	 * @brief Move the position in a given direction.
	 * @param direction The direction in which the position will be moved.
	 */
	void move(const Position& direction);

	/**
	 * @brief Generate a random position in a given width and height.
	 * @param width The width of the field.
	 * @param height The height of the field.
	 * @return A random position in the field.
	 */
	static Position random(size_t width, size_t height);
};




#endif //LAB4_POSITION_HPP
