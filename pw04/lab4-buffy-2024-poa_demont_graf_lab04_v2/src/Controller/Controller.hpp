/**
 * @file Controller.hpp
 * @brief Definition of the Controller class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef BUFFY_CONTROLLER_HPP
#define BUFFY_CONTROLLER_HPP

#include "../Field/Field.hpp"
#include "../Displayer/Display.hpp"

/**
 * @brief Class representing the controller of the game.
 */
class Controller {
	Field field;
	Display display;

	bool finished;
	static constexpr size_t NB_SIMULATIONS = 10000;

	/**
	 * @brief Quit the game.
	 */
	void quit();

	/**
	 * @brief Display Buffy's average win rate with current field status
	 */
	void statistics();

	/**
	 * @brief Handle the command entered by the user.
	 */
	void handleCommand();

	/**
	 * @brief Execute the next turn of the game.
	 */
	void nextTurn();

	public:
	/**
	 * @brief Constants representing the commands that can be entered by the user.
	 */
	static constexpr char QUIT = 'q',
		STATISTICS = 's',
		NEXT = 'n';

	/**
	 * @brief Constructor of the Controller class.
	 * @param width The width of the field.
	 * @param height The height of the field.
	 * @param nbHumans The number of humans in the field.
	 * @param nbVampires The number of vampires in the field.
	 */
	Controller(const size_t width, const size_t height, size_t nbHumans, size_t
	nbVampires);

	/**
	 * @brief Run the game.
	 */
	void run();
};

#endif //BUFFY_CONTROLLER_HPP
