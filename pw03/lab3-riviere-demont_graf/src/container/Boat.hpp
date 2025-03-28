/**
 * @file Boat.hpp
 * @brief Declaration of the Boat class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_BOAT_HPP
#define RIVER_BOAT_HPP

#include "Container.hpp"
#include "Bank.hpp"

/**
 * @brief Class representing a boat.
 * @details Boat is a type of container that can move between banks.
 */
class Boat : public Container {
private:
    const Bank* currentBank;

    const size_t maxCapacity = 2;

    const static std::string BOAT_FULL;

public:
    /**
     * @brief Construct a new Boat object.
     * @param name The name of the Boat.
     * @param currentBank The current bank of the Boat.
     */
    Boat(const std::string &name, const Bank &currentBank);

    /**
     * @brief Move the Boat to a new bank.
     * @param to The bank to move the Boat to.
     */
    void move(const Bank &to);

    /**
     * @brief Add a person to the Boat.
     * @param person The person to add.
     * @throws std::runtime_error if the Boat is full.
     */
    void addPerson(const Person *person) override;

    /**
     * @brief Check if the Boat has a driver.
     * @return True if the Boat has a driver, false otherwise.
     */
    bool hasDriver() const;

    /**
     * @brief Get the current bank of the Boat.
     * @return The current bank of the Boat.
     */
    [[nodiscard]] const Bank* getCurrentBank() const;

    /**
     * @brief Set the bank of the Boat.
     * @param bank
     */
    void setBank(const Bank *bank);

    /**
    * @brief Add a person to the Boat.
    * @param person The person to add.
    */
    std::string toString() const override;

	 /**
	  * @brief Clone the Boat.
	  * @return A new Boat object.
	  */
    [[nodiscard]] Container* clone() const override;
};


#endif //RIVER_BOAT_HPP
