/**
 * @file Ship.hpp
 * @brief Declaration of the Ship class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LABSQUADRON_SHIP_HPP
#define LABSQUADRON_SHIP_HPP

#include <ostream>
#include <string>

class Ship;

/**
 * @brief Overloaded stream insertion operator to print Ship details.
 * @param os Output stream.
 * @param ship Ship object to print.
 * @return Reference to the output stream.
 */
std::ostream &operator<<(std::ostream &os, const Ship &ship);

/**
 * @brief Overloaded equality operator to compare two Ship objects.
 * @param ship1 First Ship object.
 * @param ship2 Second Ship object.
 * @return True if the Ship objects are equal, false otherwise.
 */
bool operator==(const Ship &ship1, const Ship &ship2);

/**
 * @brief Overloaded inequality operator to compare two Ship objects.
 * @param ship1 First Ship object.
 * @param ship2 Second Ship object.
 * @return True if the Ship objects are not equal, false otherwise.
 */
bool operator!=(const Ship &ship1, const Ship &ship2);


/**
 * @brief Abstract base class representing a ship.
 * @details Provides functionalities for formatting ship details,
 * calculating fuel consumption, and comparing ships.
 */
class Ship {
public:
    /**
     * @brief Default virtual destructor for Ship class.
     */
    virtual ~Ship() = default;

    Ship(const Ship& other) = delete;

    Ship(Ship&& other) = delete;

    Ship& operator=(const Ship& other) = delete;

    Ship& operator=(Ship&& other) = delete;

    /**
     * @brief Virtual method to format Ship details to an output stream.
     * @param os Output stream.
     * @return Reference to the output stream.
     */
    virtual std::ostream &formatToStream(std::ostream &os) const noexcept;

    /**
     * @brief Calculate fuel consumption for the ship based on distance
     * and its max speed.
     * @param distance Distance to travel.
     * @return Fuel consumption.
     * @throws std::invalid_argument if the distance or max speed is
     * invalid.
     */
    double consumption(double distance) const;

    /**
     * @brief Calculate fuel consumption for the ship based on distance
     * and speed.
     * @param distance Distance to travel.
     * @param speed Speed of the ship.
     * @return Fuel consumption.
     * @throws std::invalid_argument if the distance or requested speed
     * is invalid.
     */
    double consumption(double distance, size_t speed) const;

    /**
     * @brief Get the model of the ship.
     * @return Model of the ship.
     */
    virtual std::string model() const = 0;

    /**
     * @brief Get the weight of the ship.
     * @return Weight of the ship.
     */
    virtual double weight() const = 0;

    /**
     * @brief Get the speed of the ship.
     * @return Speed of the ship.
     */
    virtual size_t speed() const = 0;

    /**
     * @brief Set the nickname of the ship.
     * @param nickname Nickname to set.
     */
    void setNickname(const std::string &nickname);

    /**
     * @brief Check if the ship is equal to another ship.
     * @param other Ship to compare.
     * @return True if the ships are equal, false otherwise.
     */
    bool isEqual(const Ship &other) const noexcept;

protected:
    /**
     * @brief Constructor for Ship class.
     * @param id Identifier of the ship.
     * @param nickname Nickname of the ship.
     */
    Ship(size_t id, const std::string &nickname);

private:
    /**
     * @brief Nickname of the ship.
     */
    std::string nickname;

    /**
     * @brief Identifier of the ship.
     */
    size_t id;
};

#endif //LABSQUADRON_SHIP_HPP
