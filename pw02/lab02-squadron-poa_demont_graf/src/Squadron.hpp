/**
 * @file Squadron.hpp
 * @brief Declaration of the Squadron class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LABSQUADRON_SQUADRON_HPP
#define LABSQUADRON_SQUADRON_HPP

#include <string>
#include "ships/Ship.hpp"

class Squadron;

/*!
 * \brief Output flow operator for displaying the squadron.
 * \param os Output flow
 * \param squadron Squadron to display
 * \return A reference on the modified output flow.
 */
std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

/*!
 * @author Demont Killian & Graf Calvin
 */
class Squadron {

private:

 	// region Attribut
	std::string name;
	Ship* leader;

	struct Members;
	Members* head;
	size_t size;

	// endregion

	// region Méthode privée

	/*!
	 * @brief Copies all the ships in a squadron to another squadron
	 * @param squadron Squadron to copy
	 */
	void copyAllShips(const Squadron &squadron);

	/*!
	 * @brief Releases the entire squadron's memory
	 */
	void freeMemory();

	/*!
	 * @brief Initializes the basic parameters of the squadron
	 * @param name Name of the squadron
	 * @param leader Leader of the squadron
	 */
	void init(std::string name, Ship* leader);

	/*!
	* Deletes all the squadron's current data and copies the new one
	* @param other Squadron to copy
	*/
	void copyOfSquadron(const Squadron &other);

	// endregion

public:

	// region Constructeur / Destructeur

	/*!
	 * @brief Constructor of the class Squadron
	 * @param name Name of the squadron
	 */
	explicit Squadron(std::string name) noexcept;

	/*!
	 * @brief Constructor by copy of the class Squadron
	 * @param other Squadron to copy
	 */
	Squadron(const Squadron& other) noexcept;

	/*!
	 * @brief Constructor by move of the class Squadron
	 * @param other Squadron to move
	 */
	Squadron(Squadron&& other) noexcept;

	/*!
	 * @brief Destructor of the class Squadron
	 */
	~Squadron() noexcept;

	// endregion

	// region Méthode public

	/*!
	 * @brief Getter of the name of the Squadron
	 * @return the name of the Squadron
	 */
	std::string getName() const;

	/*!
	 * @brief Setter of the name of the Squadron
	 * @param name
	 */
	void setName(const std::string &name);

	/*!
	 * @brief Add a ship to the squadron
	 * @param ship Ship to add
	 * @return The instance of the squadron with the new ship
	 */
	Squadron& addShip(Ship &ship);

	/*!
	* @brief Add a ship to the squadron
 	* @param ship Ship to add
 	* @return The new instance of the squadron with the new ship
 	*/
	[[nodiscard]] Squadron addShipCopy(Ship &ship) const;

	/*!
	 * @brief Remove a ship from the squadron
	 * @param ship Ship to remove
	 * @return The instance of the Squadron without the ship
	 */
	Squadron& removeShip(Ship &ship);

	/*!
 	* @brief Remove a ship from the squadron
 	* @param ship Ship to remove
 	* @return The new instance of the Squadron without the ship
 	*/
	[[nodiscard]] Squadron removeShipCopy(Ship &ship) const;

	/*!
	 * @brief Get a ship with an index
	 * @param index Index of the ship
	 * @return The ship at this index
	 */
	Ship& getShip(int index) const;

	/*!
	 * @brief Set the leader of the squadron
	 * @param leader The new leader
	 */
	void setLeader(Ship& leader);

	/*!
	 * @brief Remove the leader of the squadron
	 */
	void removeLeader();

	/*!
	 * Calculate fuel consumption for the squadron based on distance and speed
	 * @param distance Distance to travel
	 * @param speed Desired speed
	 * @return Fuel consumption
	 * @throws std::invalid_argument if the distance or max speed is invalid
	 */
	double computeConsumption(double distance, size_t speed) const;

	/*!
 	* Overloaded stream insertion operator to print Squadron details.
 	* @param os Output stream
 	* @return Reference to the output stream.
	*/
	std::ostream& toStream(std::ostream& os) const;


	// endregion

	// region Opérateur

	/*!
	 * @brief Add a ship to the squadron
	 * @param ship Ship to add
	 * @return A new instance of the squadron with the ship
	 */
	Squadron operator+(Ship &ship);

	/*!
	 * @brief Remove a ship to the squadron
	 * @param ship Ship to remove
	 * @return A new instance of the squadron without the ship
	 */
	Squadron operator-(Ship &ship);

	/*!
	 * @brief Add a ship to the squadron
	 * @param ship Ship to add
	 * @return The instance of the squadron with the ship
	 */
	Squadron& operator+=(Ship& ship);

	/*!
	 * @brief Remove a ship to the squadron
	 * @param ship Ship to remove
	 * @return The instance of the squadron without the ship
	 */
	Squadron& operator-=(Ship& ship);

	/*!
	* @brief Copy a squadron
	* @param other Squadron to copy
	* @return A reference on the modified squadron
	*/
	Squadron& operator=(const Squadron& other);

	/*!
	 * @brief Move a squadron in a new one
	 * @param other Squadron to move
	 * @return A reference on the modified squadron
	 */
	Squadron& operator=(Squadron&& other) noexcept;

	/*!
	 * Get a ship with an index
	 * @param index Index of the ship
	 * @return The ship at this index
	 */
	Ship& operator[](size_t index) const;

	// endregion
};

#endif //LABSQUADRON_SQUADRON_HPP
