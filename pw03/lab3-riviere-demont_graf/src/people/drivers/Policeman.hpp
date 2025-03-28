/**
 * @file Policeman.hpp
 * @brief Declaration of the Policeman class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_POLICEMAN_HPP
#define RIVER_POLICEMAN_HPP

#include "Driver.hpp"
#include "../../container/Container.hpp"

/**
 * @brief Class representing a policeman.
 */
class Policeman : public Driver {
private:

public:
	 /**
	  * @brief Construct a new Policeman object.
	  * @param name The name of the policeman.
	  */
    explicit Policeman(const std::string & name);

    /**
     * @brief Check if the policeman can be in the container.
     * @return A Validation object representing the result of the validation.
     * If the validation is successful, the Validation object is valid.
     * If the validation fails, the Validation object is invalid and contains an error message.
     */
    Validation isValid(const Container& container) const override;

};


#endif //RIVER_POLICEMAN_HPP
