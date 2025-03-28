/**
 * @file Validation.cpp
 * @brief Definition of the Validation class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Validation.hpp"

Validation::Validation(bool state, std::optional<std::string> error) : state(state), error(std::move(error)) {}

Validation Validation::valid() {
    return {true, {}};
}

Validation Validation::invalid(std::string error) {
    return {false, std::move(error)};
}

bool Validation::getState() const {
    return state;
}

std::string Validation::getErrorMessage() const {
    return error.value();
}
