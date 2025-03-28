/**
 * @file Interceptor.hpp
 * @brief Declaration of the Interceptor class.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LABSQUADRON_INTERCEPTOR_HPP
#define LABSQUADRON_INTERCEPTOR_HPP


#include "Ship.hpp"

/**
 * @brief Class representing an Interceptor ship.
 * @details Interceptor is a type of ship with specific characteristics.
 */
class Interceptor : public Ship {
public:
    /**
     * @brief Construct a new Interceptor object.
     * @param nickname The nickname of the Interceptor ship (default
     * is empty).
     */
    explicit Interceptor(const std::string& nickname = "");

    /**
     * @brief Get the model of the Interceptor ship.
     * @return The model of the Interceptor.
     */
    std::string model() const noexcept override;

    /**
     * @brief Get the weight of the Interceptor ship.
     * @return The weight of the Interceptor.
     */
    double weight() const noexcept override;

    /**
     * @brief Get the speed of the Interceptor ship.
     * @return The speed of the Interceptor.
     */
    size_t speed() const noexcept override;

private:
    static size_t lastInterceptorId; ///< Static member to keep track
                                     ///< of the last assigned Interceptor
                                     ///< ID.
};


#endif //LABSQUADRON_INTERCEPTOR_HPP
