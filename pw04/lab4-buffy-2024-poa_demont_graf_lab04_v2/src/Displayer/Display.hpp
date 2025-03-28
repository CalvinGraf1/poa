/**
 * @file Display.hpp
 * @brief Definition of the Display class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef BUFFY_DISPLAY_HPP
#define BUFFY_DISPLAY_HPP

#include "../Field/Field.hpp"
#include <vector>

/**
 * @brief Class representing the display of the game.
 */
class Display {
	std::vector<std::vector<const Humanoid*>> gameBoard;
	const Field& field;
	static constexpr char CORNER = '+',
							    HORIZONTAL_BORDER = '-',
			    				 VERTICAL_BORDER = '|',
								 EMPTY = ' ';

	/**
	 * @brief Print the horizontal border of the game board.
	 * @param field The field to print the border of.
	 */
	void printHorizontalBorder(const Field& field) const;
public:
	/**
	 * @brief Constructor of the Display class.
	 * @param field The field to display.
	 */
	Display(const Field& field);

	/**
	 * @brief Print the game board.
	 */
	void print();

	/**
	 * @brief Print the prompt with commands available.
	 */
	void printPrompt() const;

	/*
	/**
	 * @brief Clear the console.
	 */
	/*
	void clear() const;
	*/

	/**
	 * @brief Clear the vector representing the game board
	 */
	void clearGameBoard();
};

#endif //BUFFY_DISPLAY_HPP
