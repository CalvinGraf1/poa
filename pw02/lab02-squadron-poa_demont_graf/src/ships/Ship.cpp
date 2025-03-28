/**
 * @file Ship.cpp
 * @brief Definition of the Ship class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Ship.hpp"
#include "../Constants.hpp"
#include <cmath>
#include <iomanip>


std::ostream &operator<<(std::ostream &os, const Ship &ship) {
    return ship.formatToStream(os);
}

bool operator==(const Ship &ship1, const Ship &ship2) {
    return ship1.isEqual(ship2);
}

bool operator!=(const Ship &ship1, const Ship &ship2) {
    return !ship1.isEqual(ship2);
}

void Ship::setNickname(const std::string &nickname) {
    this->nickname = nickname;
}

Ship::Ship(size_t id, const std::string &nickname) :
        id(id), nickname(nickname) {}

std::ostream &Ship::formatToStream(std::ostream &os) const noexcept {
    if (!nickname.empty())
        os << nickname << " ";

    os << "[" << model() << " #" << id << "]\nweight : "
       << std::fixed << std::setprecision(2)
       << weight() << " " << WEIGHT_UNIT << "\n"
       << "max speed : " << speed() << " " << SPEED_UNIT;

    return os;
}

double Ship::consumption(double distance) const {
    return consumption(distance, speed());
}

double Ship::consumption(double distance, size_t speedAsked) const {
    if (distance < 0)
        throw std::invalid_argument("Distance cannot be negative");

    if (speedAsked == 0)
        throw std::invalid_argument("Speed must be greater than 0");

    if (speedAsked > speed())
        throw std::invalid_argument("Speed must be positive and less "
                                    "or equal to max speed");

    return cbrt(weight()) / 2.0 *
           log10(weight() * static_cast<double>(speedAsked)) *
           log10(distance + 1);
}

bool Ship::isEqual(const Ship &other) const noexcept {
    return id == other.id && typeid(*this) == typeid(other);
}

