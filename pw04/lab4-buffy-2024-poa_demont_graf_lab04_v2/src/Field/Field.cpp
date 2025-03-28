/**
 * @file Field.cpp
 * @brief Declaration of the Field class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Field.hpp"

Field::Field(const size_t width, const size_t height, size_t nbHumans,
				 size_t nbVampires): width(width), height(height), nbHumans(nbHumans),
				 nbVampires(nbVampires), turn(0)
{
	 for (size_t i = 0; i < nbHumans; i++) {
		 humanoids.emplace_back(
			 new Human(Position(Position::random(width, height))));
	 }
	 for (size_t i = 0; i < nbVampires; i++) {
		 humanoids.emplace_back(
			 new Vampire(Position(Position::random(width, height))));
	 }
	 humanoids.emplace_back(new Buffy(Position::random(width, height)));
}

int Field::nextTurn() {
	// Déterminer les prochaines actions
	for (std::list<Humanoid *>::iterator it = humanoids.begin();
		  it != humanoids.end(); it++)
		(*it)->setAction(*this);
	// Executer les actions
	for (std::list<Humanoid *>::iterator it = humanoids.begin();
		  it != humanoids.end(); it++)
		(*it)->executeAction(*this);
	// Enlever les humanoides tués
	for (std::list<Humanoid *>::iterator it = humanoids.begin();
		  it != humanoids.end();) {
		if (!(*it)->isAlive()) {
			Humanoid *toDelete = *it;
			it = humanoids.erase(it); // suppression de l’élément dans la liste
			delete toDelete; // destruction de l’humanoide référencé
		} else
			++it;
	}
	return turn++;
}

size_t Field::getNbHuman() const {
	return nbHumans;
}

size_t Field::getNbVampire() const {
	return nbVampires;
}

std::list<Humanoid*> Field::getHumanoids() const {
	return humanoids;
}

size_t Field::getWidth() const {
	return width;
}

size_t Field::getHeight() const {
	return height;
}

int Field::getTurn() const {
	return turn;
}

void Field::vampireDie() {
	if(nbVampires) --nbVampires;
}

void Field::humanDie() {
	if(nbHumans) --nbHumans;
}

void Field::vampireBorn() {
	++nbVampires;
}

void Field::addHumanoid(Humanoid* humanoid) {
	for(auto it = humanoids.begin(); it != humanoids.end(); it++)
		if(*it == humanoid) return;
 	humanoids.emplace_back(humanoid);
}


