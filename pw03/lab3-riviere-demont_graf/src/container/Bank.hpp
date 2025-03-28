/**
 * @file Bank.hpp
 * @brief Declaration of the Bank class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_BANK_HPP
#define RIVER_BANK_HPP

#include "Container.hpp"

/**
 * @brief Class representing a bank.
 * @details Provides functionalities for adding, removing, and displaying
 * people on the bank.
 */
class Bank : public Container {

public:
	/**
	* @brief Construct a new Bank object.
	* @param name The name of the Bank.
	*/
	explicit Bank(const std::string & name);

	/**
	* @brief Construct a new Bank object.
	* @param name The name of the Bank.
	* @param people The people on the Bank.
	*/
   Bank(const std::string & name, std::list<const Person*> people);

   [[nodiscard]] Container* clone() const override;

};


#endif //RIVER_BANK_HPP
