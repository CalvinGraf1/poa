/**
 * @file Destroyer.hpp
 * @brief Declaration of the Destroyer class.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LABSQUADRON_DESTROYER_HPP
#define LABSQUADRON_DESTROYER_HPP

#include "CargoShip.hpp"

/**
 * @brief Class representing a Destroyer ship.
 * @details Destroyer is a type of cargo ship known for its heavy
 * firepower and large cargo capacity.
 */
class Destroyer : public CargoShip {
public:
    /**
     * @brief Construct a new Destroyer object.
     * @param cargo The initial cargo of the Destroyer ship.
     * @param nickname The nickname of the Destroyer ship (default
     * is empty).
     */
    explicit Destroyer(double cargo,
                       const std::string &nickname = "");

    /**
     * @brief Get the model of the Destroyer ship.
     * @return The model of the Destroyer.
     */
    std::string model() const noexcept override;

    /**
     * @brief Get the empty weight of the Destroyer ship.
     * @return The empty weight of the Destroyer.
     */
    double emptyWeight() const noexcept override;

    /**
     * @brief Get the speed of the Destroyer ship.
     * @return The speed of the Destroyer.
     */
    size_t speed() const noexcept override;

    /**
     * @brief Get the cargo limit of the Destroyer ship.
     * @return The cargo limit of the Destroyer.
     */
    double cargoLimit() const noexcept override;

private:
    static size_t lastDestroyerId; ///< Static member to keep track
                                   ///< of the last assigned Destroyer
                                   ///< ID.
};

#endif //LABSQUADRON_DESTROYER_HPP
