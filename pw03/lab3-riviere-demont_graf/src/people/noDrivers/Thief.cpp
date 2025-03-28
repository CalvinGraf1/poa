/**
 * @file Thief.cpp
 * @brief Definition of the Thief class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Thief.hpp"

const std::string Thief::ERROR_MESSAGE = "Un voleur ne peut pas rester avec "
											"d'autres personnes sans la presence d'un policier";

Thief::Thief(const std::string &name, const Policeman &policeman)
        : NoDriver(name), policeman(&policeman) {}

Validation Thief::isValid(const Container &container) const {
    if (!((container.size() == 1 && container.contains(*(this))) ||
        container.contains(*policeman))) {
        return Validation::invalid(ERROR_MESSAGE);
    }

    return Validation::valid();
}