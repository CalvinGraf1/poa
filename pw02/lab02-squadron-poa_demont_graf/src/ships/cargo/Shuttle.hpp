/**
 * @file Shuttle.hpp
 * @brief Declaration of the Shuttle class.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LABSQUADRON_SHUTTLE_HPP
#define LABSQUADRON_SHUTTLE_HPP

#include "CargoShip.hpp"

/**
 * @brief Class representing a Shuttle ship.
 * @details Shuttle is a type of cargo ship primarily used for
 * transporting passengers or cargo between locations.
 */
class Shuttle : public CargoShip {
public:
    /**
     * @brief Construct a new Shuttle object.
     * @param cargo The initial cargo of the Shuttle ship (default is 0).
     * @param nickname The nickname of the Shuttle ship (default is
     * empty).
     */
    explicit Shuttle(double cargo = 0, const std::string& nickname = "");

    /**
     * @brief Get the model of the Shuttle ship.
     * @return The model of the Shuttle.
     */
    std::string model() const noexcept override;

    /**
     * @brief Get the empty weight of the Shuttle ship.
     * @return The empty weight of the Shuttle.
     */
    double emptyWeight() const noexcept override;

    /**
     * @brief Get the speed of the Shuttle ship.
     * @return The speed of the Shuttle.
     */
    size_t speed() const noexcept override;

    /**
     * @brief Get the cargo limit of the Shuttle ship.
     * @return The cargo limit of the Shuttle.
     */
    double cargoLimit() const noexcept override;

private:
    static size_t lastShuttleId; ///< Static member to keep track of
                                 ///< the last assigned Shuttle ID.
};

#endif //LABSQUADRON_SHUTTLE_HPP
