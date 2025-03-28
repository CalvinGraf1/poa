/**
 * @file Parent.hpp
 * @brief Declaration of the Parent class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_PARENT_HPP
#define RIVER_PARENT_HPP

#include "Driver.hpp"

/**
 * @brief Class representing a parent.
 */
class Parent : public Driver {
public:
	/**
	 * @brief Construct a new Parent object.
	 * @param name The name of the parent.
	 */
    explicit Parent(const std::string & name);

    /**
     * @brief Check if the parent can be in the container.
     * @return A Validation object representing the result of the validation.
     * If the validation is successful, the Validation object is valid.
     * If the validation fails, the Validation object is invalid and contains an error message.
     */
    Validation isValid(const Container& container) const override;

};


#endif //RIVER_PARENT_HPP
