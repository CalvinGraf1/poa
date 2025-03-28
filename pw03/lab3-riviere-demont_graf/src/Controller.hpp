/**
 * @file Controller.hpp
 * @brief Declaration of the Controller class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_CONTROLLER_HPP
#define RIVER_CONTROLLER_HPP

#include "people/Person.hpp"
#include "container/Bank.hpp"
#include "container/Boat.hpp"

/**
 * @brief Class representing the controller of the game.
 * @details The controller manages the game's state and interactions
 * between the player and the game's elements.
 */
class Controller {
private:

	// region Attributs
	int turn = 0;
	const int LENGTH_DISPLAY = 58;

	std::list<const Person*> people;

	Bank* left = nullptr;
	Bank* right = nullptr;
	Boat* boat = nullptr;

	static const char DISPLAY, EMBARK, DISEMBARK, MOVE, RESET, QUIT, MENU;

	static const std::string MSG_EMBARK_MSG_DISEMBARK, MSG_NOT_ON_BOAT_BANK, MSG_NOT_IN_GAME,
	MSG_WIN, DISPLAY_DEF, EMBARK_DEF, DISEMBARK_DEF, MOVE_DEF, RESET_DEF, QUIT_DEF,
	MENU_DEF, INVALID_CMD;
	// endregion

	// region Méthodes privées

    /**
     * @brief Display the game's menu.
     */
	void showMenu() const;

    /**
     * @brief Reset the game to its initial state.
     */
	void reset();

    /**
     * @brief Fill the display with the content of a bank.
     * @param bank The bank to display.
     */
	void fill(const Bank* bank) const;

    /**
     * @brief Display error in a good format.
     */
	void displayError(const std::string& error) const;

    /**
     * @brief Check if the game is over.
     * @return True if the game is over, false otherwise.
     */
	bool checkWin() const;

    /**
     * @brief Check if the game is over.
     * @return True if the game is over, false otherwise.
     */
   void embark(const Person * person);

   /**
    * @brief Disembark a person from the boat.
    * @param person
    */
   void disembark(const Person * person);

   /**
    * @brief Move the boat to the other bank.
    * @param to
    */
   void moveBoat(Bank * to);

   /**
    * @brief Find a person by name from the list of people in the game.
    * @param name The name of the person to find.
    * @return The person if found, nullptr otherwise.
    */
   [[nodiscard]] const Person* findPerson(const std::string& name) const;

   /**
    * @brief Move a person from a container to another.
    * @param person
    * @param from
    * @param to
    * @throws std::runtime_error if the person is not in the from container.
    * @throws std::runtime_error if the to container is full.
    */
   void movePerson(const Person* person, Container* from, Container* to);

    /**
     * @brief Process a move of a person from a container to another.
     * @param person The person to move.
     * @param from The container to move the person from.
     * @param to The container to move the person to.
     * @throws std::runtime_error if the person is not in the from container.
     * @throws std::runtime_error if the to container is full.
     */
   void processMove(const Person *person, Container *from, Container *to);

    /**
    * @brief Validate the container after a person has been removed.
    * @param person The person that has been removed.
    * @param container The container to validate.
    * @return True if the container is valid, false otherwise.
    * @throws std::runtime_error if the person is not in the container.
    */
   bool validateContainerAfterRemoval(const Person *person, Container *container);

    /**
    * @brief Validate the container after a person has been added.
    * @param person The person that has been added.
    * @param container The container to validate.
    * @return True if the container is valid, false otherwise.
    * @throws std::runtime_error if the container is full.
    */
   bool validateContainerAfterAdding(const Person *person, Container *container);

    /**
    * @brief Validate the container.
    * @param person The person to validate.
    * @param container The container to validate.
    * @return True if the container is valid, false otherwise.
    */
   bool validateContainer(const Person *person, Container *container);

	/**
	 * @brief Proceed the next turn.
	 */
	void nextTurn();

	/**
	 * @brief Check if a person can embark or disembark from the boat.
	 * @param iss The input stream to read the person's name from.
	 * @return The person if they can embark or disembark, nullptr otherwise.
	 */
    [[nodiscard]] const Person* canEmbarkDisembark(std::istringstream& iss) const;

	// endregion

public:
	/**
	 * @brief Construct a new Controller object.
	 * @param people The list of people to manage in the game.
	 */
   Controller(std::initializer_list<const Person*> people);

	/**
	 * @brief Destroy the Controller object.
	 */
   ~Controller();

	Controller(const Controller&) = delete;
	Controller& operator=(const Controller&) = delete;

    /**
     * @brief Run the game.
     */
	void run();

    /**
     * @brief Display the game's state.
     */
	void display();
};


#endif //RIVER_CONTROLLER_HPP
