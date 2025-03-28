/**
 * @file Son.cpp
 * @brief Definition of the Son class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Son.hpp"
#include "../../../container/Container.hpp"

const std::string Son::ERROR_MESSAGE = "Un fils ne peut pas rester avec sa mere "
													"sans son pere";

Son::Son(const std::string &name, const Parent &mother,
         const Parent &father) : Child(name, mother, father) {}

Validation Son::isValid(const Container &container) const {
    if (container.contains(*getMother()) &&
          !container.contains(*getFather())) {
        return Validation::invalid(ERROR_MESSAGE);
    }

    return Validation::valid();
}
