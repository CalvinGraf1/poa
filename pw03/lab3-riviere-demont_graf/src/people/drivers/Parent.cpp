/**
 * @file Parent.cpp
 * @brief Definition of the Parent class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Parent.hpp"

Parent::Parent(const std::string &name) : Driver(name) {}

Validation Parent::isValid(const Container &container) const {
    return Validation::valid();
}
