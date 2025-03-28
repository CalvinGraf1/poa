/**
 * @file Son.hpp
 * @brief Declaration of the Son class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_SON_HPP
#define RIVER_SON_HPP

#include "Child.hpp"

/**
 * @brief Class representing a son.
 */
class Son : public Child {
private:
    const static std::string ERROR_MESSAGE;
public:
    /**
     * @brief Constructor of the Son class.
     * @param name Name of the son.
     * @param mother Mother of the son.
     * @param father Father of the son.
     */
    Son(const std::string &name, const Parent &mother,
        const Parent &father);

    /**
    * @brief Check if the son can be in the container.
    * @return A Validation object representing the result of the validation.
    * If the validation is successful, the Validation object is valid.
    * If the validation fails, the Validation object is invalid and contains an error message.
    */
    Validation isValid(const Container &container) const override;
};


#endif //RIVER_SON_HPP
