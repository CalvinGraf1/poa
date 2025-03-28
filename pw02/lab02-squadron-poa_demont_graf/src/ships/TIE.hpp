/**
 * @file TIE.hpp
 * @brief Declaration of the TIE class.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LABSQUADRON_TIE_HPP
#define LABSQUADRON_TIE_HPP

#include "Ship.hpp"

/**
 * @brief Class representing a TIE fighter ship.
 * @details TIE is a type of ship known for its agility and speed.
 */
class TIE : public Ship {
public:
    /**
     * @brief Construct a new TIE object.
     * @param nickname The nickname of the TIE fighter ship (default
     * is empty).
     */
    explicit TIE(const std::string &nickname = "");

    /**
     * @brief Get the model of the TIE fighter ship.
     * @return The model of the TIE fighter.
     */
    std::string model() const noexcept override;

    /**
     * @brief Get the weight of the TIE fighter ship.
     * @return The weight of the TIE fighter.
     */
    double weight() const noexcept override;

    /**
     * @brief Get the speed of the TIE fighter ship.
     * @return The speed of the TIE fighter.
     */
    size_t speed() const noexcept override;

private:
    static size_t lastTIEId; ///< Static member to keep track of the
                             ///< last assigned TIE fighter ID.
};

#endif //LABSQUADRON_TIE_HPP
