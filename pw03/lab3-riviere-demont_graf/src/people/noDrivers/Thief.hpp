/**
 * @file Thief.hpp
 * @brief Declaration of the Thief class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_THIEF_HPP
#define RIVER_THIEF_HPP


#include "NoDriver.hpp"
#include "../drivers/Policeman.hpp"

/**
 * @brief Class representing a thief.
 */
class Thief : public NoDriver {
private:
    const Policeman *policeman;
    const static std::string ERROR_MESSAGE;
public:
	/**
	 * @brief Constructor of the Thief class.
	 * @param name Name of the person.
	 * @param policeman The policeman who has to watch the thief.
	 */
    Thief(const std::string & name, const Policeman & policeman);

    /**
    * @brief Check if the thief can be in the container.
    * @return A Validation object representing the result of the validation.
    * If the validation is successful, the Validation object is valid.
    * If the validation fails, the Validation object is invalid and contains an error message.
    */
    Validation isValid(const Container& container) const override;
};


#endif //RIVER_THIEF_HPP
