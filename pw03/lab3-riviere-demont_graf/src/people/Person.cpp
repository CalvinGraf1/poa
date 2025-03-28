/**
 * @file Person.cpp
 * @brief Definition of the Person class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Person.hpp"

Person::Person(const std::string &name) : name(name) {}

std::string Person::getName() const { return name; }
