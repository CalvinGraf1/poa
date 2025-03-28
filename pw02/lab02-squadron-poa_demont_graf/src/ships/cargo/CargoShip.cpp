/**
 * @file CargoShip.cpp
 * @brief Definition of the CargoShip abstract class.
 * @authors Demont Kilian & Graf Calvin
 */

#include <iomanip>
#include "../../Constants.hpp"
#include "CargoShip.hpp"

void CargoShip::setCargo(double cargo) {
    checkCargo(cargo, cargoLimit());
    this->cargo = cargo;
}

double CargoShip::getCargo() const noexcept {
    return this->cargo;
}

CargoShip::CargoShip(size_t id, double max,
                     const std::string &nickname, double cargo) :
        Ship(id, nickname), cargo(cargo) {
    checkCargo(cargo, max);
}

double CargoShip::weight() const noexcept{
    return emptyWeight() + cargo;
}

std::ostream &CargoShip::formatToStream(std::ostream &os) const noexcept {
    return Ship::formatToStream(os)
            << std::fixed << std::setprecision(1)
            << "\ncargo : " << cargo << " " << WEIGHT_UNIT
            << " (max : " << cargoLimit() << ")";
}

void CargoShip::checkCargo(double cargo, double max) const {
    if (cargo < 0)
        throw std::invalid_argument("Cargo cannot be negative");

    if (cargo > max)
        throw std::invalid_argument("Cargo exceeds cargo limit");
}

