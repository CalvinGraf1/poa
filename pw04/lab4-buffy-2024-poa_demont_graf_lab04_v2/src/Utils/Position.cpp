/**
 * @file Position.cpp
 * @brief Declaration of the Position class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include <cmath>
#include "Position.hpp"
#include "Random.hpp"

const Position Position::UP = Position(0, -1);
const Position Position::UP_RIGHT = Position(1, -1);
const Position Position::RIGHT = Position(1, 0);
const Position Position::DOWN_RIGHT = Position(1, 1);
const Position Position::DOWN = Position(0, 1);
const Position Position::DOWN_LEFT = Position(-1, 1);
const Position Position::LEFT = Position(-1, 0);
const Position Position::UP_LEFT = Position(-1, -1);

Position::Position() : x(0), y(0) {}

Position::Position(size_t x, size_t y) : x(x), y(y) {}

size_t Position::getX() const {
	return x;
}

size_t Position::getY() const {
	return y;
}

size_t Position::distance(const Position & pos) const {
	return (size_t)round(hypot(abs((x - pos.x)), abs((y - pos.y))));
}

Position Position::random(size_t width, size_t height) {
	return Position(Random::generateInt(width),
						 Random::generateInt(height));
}

Position Position::getDirection(const Position &pos) const {
	 int dx = pos.getX() - x;
	 int dy = pos.getY() - y;
	 return Position(dx == 0 ? 0 : dx / abs(dx),
						  dy == 0 ? 0 : dy / abs(dy));
}

void Position::move(const Position &direction) {
	x += direction.getX();
	y += direction.getY();
}
