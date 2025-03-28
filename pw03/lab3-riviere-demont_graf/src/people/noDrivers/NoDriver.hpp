/**
 * @file NoDriver.hpp
 * @brief Declaration of the NoDriver class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_NODRIVER_HPP
#define RIVER_NODRIVER_HPP

#include "../Person.hpp"

/**
 * @brief Class representing a person who can't drive.
 * @details Provides functionalities for checking if a person can drive.
 */
class NoDriver : public Person {
protected:
	/**
	 * @brief Constructor of the NoDriver class.
	 * @param name Name of the person.
	 */
    explicit NoDriver(const std::string& name);
public:
	/**
	 * @brief Check if the driver can drive.
	 * @return false
	 */
    bool canDrive() const override;
};


#endif //RIVER_NODRIVER_HPP
