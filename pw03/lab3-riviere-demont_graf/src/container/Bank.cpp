/**
 * @file Bank.cpp
 * @brief Definition of the Bank class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */


#include "Bank.hpp"

#include <utility>

Bank::Bank(const std::string & name) : Container(name) {}

Bank::Bank(const std::string & name, std::list<const Person *> people) :
	Container(name, people) {}

Container *Bank::clone() const {
    return new Bank(*this);
}
