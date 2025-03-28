/**
 * @file Policeman.cpp
 * @brief Definition of the Policeman class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Policeman.hpp"

Policeman::Policeman(const std::string &name) : Driver(name) {}

Validation Policeman::isValid(const Container &container) const {
    return Validation::valid();
}


