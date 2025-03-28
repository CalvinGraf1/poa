/**
 * @file Child.cpp
 * @brief Definition of the Child class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Child.hpp"

Child::Child(const std::string & name, const Parent &  mother,
             const Parent & father) : NoDriver(name), mother(&mother),
             father(&father) {}

const Parent *Child::getMother() const {
    return mother;
}

const Parent *Child::getFather() const {
    return father;
}


