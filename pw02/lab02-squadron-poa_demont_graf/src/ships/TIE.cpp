/**
 * @file TIE.cpp
 * @brief Definition of the TIE class.
 * @authors Demont Kilian & Graf Calvin
 */

#include "TIE.hpp"

size_t TIE::lastTIEId = 0;

TIE::TIE(const std::string &nickname) :
        Ship(++lastTIEId, nickname) {}

std::string TIE::model() const noexcept {
    return "TIE/LN";
}

double TIE::weight() const noexcept {
    return 6.00;
}

size_t TIE::speed() const noexcept {
    return 100;
}