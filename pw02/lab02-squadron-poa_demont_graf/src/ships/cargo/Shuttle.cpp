/**
 * @file Shuttle.cpp
 * @brief Definition of the Shuttle class.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Shuttle.hpp"

size_t Shuttle::lastShuttleId = 0;

Shuttle::Shuttle(double cargo, const std::string &nickname) :
        CargoShip(++lastShuttleId, cargoLimit(),
                  nickname, cargo) {}

std::string Shuttle::model() const noexcept {
    return "Lambda-class shuttle";
}

double Shuttle::emptyWeight() const noexcept {
    return 360.0;
}

size_t Shuttle::speed() const noexcept {
    return 54;
}

double Shuttle::cargoLimit() const noexcept {
    return 80.0;
}
