/**
 * @file NoDriver.cpp
 * @brief Definition of the NoDriver class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "NoDriver.hpp"

bool NoDriver::canDrive() const { return false; }

NoDriver::NoDriver(const std::string &name) : Person(name) {}
