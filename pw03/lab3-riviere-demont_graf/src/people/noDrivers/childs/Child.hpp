/**
 * @file Child.hpp
 * @brief Declaration of the Child class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_CHILD_HPP
#define RIVER_CHILD_HPP

#include "../NoDriver.hpp"
#include "../../drivers/Parent.hpp"

/**
 * @brief Class representing a child.
 * @details A child has a mother and a father.
 */
class Child : public NoDriver {
    const Parent* mother;
    const Parent* father;

protected:

	 /**
	  * @brief Constructor of the Child class.
	  * @param name Name of the child.
	  * @param mother Mother of the child.
	  * @param father Father of the child.
	  */
    Child(const std::string & name, const Parent &  mother, const Parent &  father);

    /**
     * @brief Getter for the mother of the child.
     * @return The mother of the child.
     */
    [[nodiscard]] const Parent* getMother() const;

    /**
     * @brief Getter for the father of the child.
     * @return The father of the child.
     */
    [[nodiscard]] const Parent* getFather() const;
};


#endif //RIVER_CHILD_HPP
