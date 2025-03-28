/**
 * @file Driver.hpp
 * @brief Declaration of the Driver class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_DRIVER_HPP
#define RIVER_DRIVER_HPP


#include "../Person.hpp"

/**
 * @brief Class representing a driver.
 * @details Provides functionalities for checking if a person can drive.
 */
class Driver : public Person {
protected:
	 /**
 	 * @brief Construct a new Driver object.
 	 * @param name The name of the driver.
	 */
    explicit Driver(const std::string & name);

public:
	 /**
	 * @brief Check if the driver can drive.
	 * @return true
	 */
    bool canDrive() const override;
};


#endif //RIVER_DRIVER_HPP
