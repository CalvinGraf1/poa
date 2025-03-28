/**
 * @file Move.cpp
 * @brief Declaration of the Move class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Move.hpp"
#include "../Person/Humanoid.hpp"
#include "../Field/Field.hpp"
#include "../Utils/Random.hpp"

Move::Move(const size_t range, Humanoid& humanoid, const Humanoid* target)
	: range(range), Action(humanoid), target(target) {}

void Move::execute(Field& field) {
	Position direction;
	Position newPosition = getHumanoid()->getPosition();

	for (size_t i = 0; i < range; ++i) {
		if (target) direction = newPosition.getDirection(target->getPosition());
		else {
			std::vector<const Position *> directions =
				getDirectionsPossible(newPosition, field);
			if (directions.empty()) return;
			direction = *directions.at(Random::generateInt(directions.size()));
		}
		newPosition.move(direction);
	}
	getHumanoid()->setPosition(newPosition);
}

std::vector<const Position*> Move::getDirectionsPossible(const Position& pos,
													                  const Field& field) const {
	std::vector<const Position*> directionsPossible;
	size_t x = pos.getX();
	size_t y = pos.getY();

	const Position* directions[] = {
		&Position::UP,
		&Position::UP_RIGHT,
		&Position::RIGHT,
		&Position::DOWN_RIGHT,
		&Position::DOWN,
		&Position::DOWN_LEFT,
		&Position::LEFT,
		&Position::UP_LEFT
	};

	for (const Position* direction : directions) {
		size_t newX = x + direction->getX();
		size_t newY = y + direction->getY();
		size_t width = field.getWidth();
		size_t height = field.getHeight();
		if (newX >= 0 && newX < width && newY >= 0 && newY < height)
			directionsPossible.emplace_back(direction);
	}
	return directionsPossible;
}
