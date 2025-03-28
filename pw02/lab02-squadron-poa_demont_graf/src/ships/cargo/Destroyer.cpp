/**
 * @file Destroyer.cpp
 * @brief Definition of the Destroyer class.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Destroyer.hpp"

size_t Destroyer::lastDestroyerId = 0;

Destroyer::Destroyer(double cargo, const std::string &nickname) :
        CargoShip(++lastDestroyerId, cargoLimit(),
                  nickname, cargo) {}

std::string Destroyer::model() const noexcept {
    return "Super-class Star Destroyer";
}

double Destroyer::emptyWeight() const noexcept {
    return 9e+9;
}

size_t Destroyer::speed() const noexcept {
    return 40;
}

double Destroyer::cargoLimit() const noexcept {
    return 250e+3;
}
