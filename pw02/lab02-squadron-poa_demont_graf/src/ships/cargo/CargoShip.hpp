/**
 * @file CargoShip.hpp
 * @brief Declaration of the CargoShip abstract class.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LABSQUADRON_CARGOSHIP_HPP
#define LABSQUADRON_CARGOSHIP_HPP

#include "../Ship.hpp"

/**
 * @brief Abstract base class for cargo ships.
 * @details This class represents a cargo ship, which is a type of
 * ship capable of carrying cargo. It inherits from the Ship class
 * and provides functionality related to cargo handling.
 */
class CargoShip : public Ship {
public:
    /**
     * @brief Set the cargo amount for the ship.
     * @param cargo The amount of cargo to set.
     */
    void setCargo(double cargo);

    /**
     * @brief Get the current cargo amount of the ship.
     * @return The current cargo amount.
     */
    double getCargo() const noexcept;

    /**
     * @brief Format ship information to an output stream.
     * @param os The output stream to format the information to.
     * @return A reference to the output stream.
     */
    std::ostream& formatToStream(std::ostream& os) const noexcept override;

    /**
     * @brief Get the maximum cargo limit of the ship.
     * @return The maximum cargo limit.
     */
    virtual double cargoLimit() const = 0;

    /**
     * @brief Get the empty weight of the ship without cargo.
     * @return The empty weight of the ship.
     */
    virtual double emptyWeight() const = 0;

    /**
     * @brief Calculate the total weight of the ship including cargo.
     * @return The total weight of the ship.
     */
     double weight() const noexcept override;

protected:
    /**
     * @brief Constructor for the CargoShip class.
     * @param id The unique identifier of the ship.
     * @param max The maximum cargo limit of the ship.
     * @param nickname The nickname of the ship.
     * @param cargo The initial cargo amount of the ship.
     */
    CargoShip(size_t id, double max,
              const std::string& nickname, double cargo);

private:
    double cargo; ///< The current cargo amount of the ship.

    /**
     * @brief Check if the cargo amount is within the cargo limit.
     * @param cargo The cargo amount to check.
     * @param max The maximum cargo limit.
     * @throws std::invalid_argument if the cargo amount is negative
     * or exceeds the cargo limit.
     */
    void checkCargo(double cargo, double max) const;
};


#endif //LABSQUADRON_CARGOSHIP_HPP
