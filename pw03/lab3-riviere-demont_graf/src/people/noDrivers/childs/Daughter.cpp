/**
 * @file Daughter.cpp
 * @brief Definition of the Daughter class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Daughter.hpp"
#include "../../../container/Container.hpp"

const std::string Daughter::ERROR_MESSAGE = "Une fille ne peut pas rester avec son "
														  "pere sans sa mere";

Daughter::Daughter(const std::string &name, const Parent &mother,
                   const Parent &father) : Child(name, mother, father) {}

Validation Daughter::isValid(const Container &container) const {
    if (container.contains(*getFather()) &&
          !container.contains(*getMother())) {
        return Validation::invalid(ERROR_MESSAGE);
    }
    return Validation::valid();
}
