/**
 * @file Validation.hpp
 * @brief Declaration of the Validation class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_VALIDATION_HPP
#define RIVER_VALIDATION_HPP

#include <string>
#include <optional>

/**
 * @brief Class representing a validation.
 * @details A validation can be valid or invalid.
 */
class Validation {
private:
    bool state;

    std::optional<std::string> error;

    /**
     * @brief Construct a new Validation object.
     * @param state The state of the validation.
     * @param error The optional error message of the validation.
     */
    Validation(bool state, std::optional<std::string> error);

public:
    /**
     * @brief Construct a new Validation object representing a valid state.
     */
    static Validation valid();

    /**
     * @brief Construct a new Validation object representing an invalid state.
     * @param error The error message of the validation.
     */
    static Validation invalid(std::string error);

    /**
     * @brief Get the state of the validation.
     * @return true if the validation is valid, false otherwise.
     */
    bool getState() const;

    /**
     * @brief Get the error message of the validation.
     * @return The error message of the validation.
     */
    std::string getErrorMessage() const;
};

#endif //RIVER_VALIDATION_HPP
