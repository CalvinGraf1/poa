/**
 * @file Interceptor.cpp
 * @brief Definition of the Interceptor class.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Interceptor.hpp"

size_t Interceptor::lastInterceptorId = 0;

Interceptor::Interceptor(const std::string &nickname) :
        Ship(++lastInterceptorId, nickname) {}

std::string Interceptor::model() const noexcept {
    return "TIE/IN";
}

double Interceptor::weight() const noexcept {
    return 5.00;
}

size_t Interceptor::speed() const noexcept {
    return 110;
}