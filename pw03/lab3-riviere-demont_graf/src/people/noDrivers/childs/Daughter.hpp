/**
 * @file Daughter.hpp
 * @brief Declaration of the Daughter class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_DAUGHTER_HPP
#define RIVER_DAUGHTER_HPP

#include "Child.hpp"

/**
 * @brief Class representing a daughter.
 */
class Daughter : public Child {
private:
    const static std::string ERROR_MESSAGE;

public:
    /**
     * @brief Constructor of the Daughter class.
     * @param name Name of the daughter.
     * @param mother Mother of the daughter.
     * @param father Father of the daughter.
     */
    Daughter(const std::string &name, const Parent &mother,
             const Parent &father);

    /**
    * @brief Check if the daughter can be in the container.
    * @return A Validation object representing the result of the validation.
    * If the validation is successful, the Validation object is valid.
    * If the validation fails, the Validation object is invalid and contains an error message.
    */
    Validation isValid(const Container &container) const override;
};


#endif //RIVER_DAUGHTER_HPP
