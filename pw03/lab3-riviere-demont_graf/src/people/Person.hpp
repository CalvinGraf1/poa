/**
 * @file Person.hpp
 * @brief Declaration of the Person class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_PERSON_HPP
#define RIVER_PERSON_HPP


#include <string>
#include "../Validation.hpp"
#include "../container/Container.hpp"

//class Container;

/**
 * @brief Abstract base class representing a person.
 */
class Person {
private:
    const std::string name;
protected:
	/**
	  * @brief Constructor of the Person class.
	  * @param name Name of the person.
	  */
    explicit Person(const std::string & name);
public:
    virtual ~Person() noexcept = default;

	/**
	 * @brief Check if the person can drive.
	 * @return True if the person can drive, false otherwise.
	 */
    virtual bool canDrive() const = 0;

    /**
     * @brief Check if the person can be in the container.
     * @return A Validation object representing the result of the validation.
     * If the validation is successful, the Validation object is valid.
     * If the validation fails, the Validation object is invalid and contains an error message.
     */
    virtual Validation isValid(const Container& container) const = 0;

	 /**
	  * @brief Get the name of the person.
	  * @return Name of the person.
	  */
    std:: string getName() const;
};


#endif //RIVER_PERSON_HPP
