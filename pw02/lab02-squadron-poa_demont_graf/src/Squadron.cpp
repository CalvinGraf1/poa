/**
 * @file Squadron.cpp
 * @brief Definition of the Squadron class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include <iomanip>
#include <limits>
#include "Squadron.hpp"
#include "Constants.hpp"

struct Squadron::Members {
	Ship* ship;
	Members* next;
};

// region Constructors

Squadron::Squadron(std::string name) noexcept : name(name) {
	init(name, nullptr);
}

Squadron::Squadron(const Squadron &other) noexcept : name(other.name) {
	copyOfSquadron(other);
}

Squadron::Squadron(Squadron &&other) noexcept : name(std::move(other.name)) {
	*this = std::move(other);
}

Squadron::~Squadron() {
	freeMemory();
}

// endregion

// region Méthode privée

void Squadron::init(std::string name, Ship* leader) {
	setName(name);
	this->leader = leader;
	this->head = nullptr;
	this->size = 0;
}

void Squadron::freeMemory() {
	Members *currentHead = head;
	while(currentHead) {
		Members *temp = currentHead->next;
		delete currentHead;
		currentHead = temp;
	}
	head = nullptr;
}

void Squadron::copyAllShips(const Squadron &squadron) {
	Members *currentHead = squadron.head;
	while(currentHead) {
		addShip(*currentHead->ship);
		currentHead = currentHead->next;
	}
}

void Squadron::copyOfSquadron(const Squadron &other) {
	init(other.name, other.leader);
	copyAllShips(other);
}

// endregion

// region Méthode public

std::string Squadron::getName() const {
	return name;
}

void Squadron::setName(const std::string &name) {
	this->name = name;
}

Squadron& Squadron::addShip(Ship& ship) {
	if(head) {
			Members* currentHead = head;
			while(currentHead && currentHead->next) {
				// Avoid to add two times the same ship
				if(*currentHead->ship == ship) return *this;
				currentHead = currentHead->next;
			}
			currentHead->next = new Members{&ship, nullptr};
	}
	else head = new Members{&ship, nullptr};
	++size;
	return *this;
}

Squadron Squadron::addShipCopy(Ship &ship) const {
	return Squadron(*this).addShip(ship);
}

Squadron& Squadron::removeShip(Ship& ship) {
	if (head) {
		Members* currentHead = head;
		Members* previous = nullptr;
		while (currentHead) {
			if (currentHead->ship == &ship) {
				if(currentHead->ship == leader) removeLeader();

				if(previous) previous->next = currentHead->next;
				else head = currentHead->next;

				delete currentHead;
				--size;
				break;
			}
			previous = currentHead;
			currentHead = currentHead->next;
		}
	}
	return *this;
}

Squadron Squadron::removeShipCopy(Ship &ship) const {
	return Squadron(*this).removeShip(ship);
}

Ship& Squadron::getShip(int index) const {
	if(index >= size)
		throw std::out_of_range("The requested index is out of range");

	Members *currentHead = head;
	for (int i = 0; i != index; ++i) currentHead = currentHead->next;
	return *currentHead->ship;
}

void Squadron::setLeader(Ship& leader) {
	this->leader = &leader;
}

void Squadron::removeLeader() {
	leader = nullptr;
}

double Squadron::computeConsumption(double distance, size_t speed) const {
	if(!size) return 0;

	double consumption = 0;
	Members *currentHead = head;
	while(currentHead) {
		consumption += currentHead->ship->consumption(distance, speed);
		currentHead = currentHead->next;
	}
	return consumption;
}

std::ostream& Squadron::toStream(std::ostream& os) const {
	std::stringstream squadron;
	std::stringstream member;
	size_t maxSpeed = head ? std::numeric_limits<size_t>::max() : 0;
	double totalWeight = 0;

	squadron << "Squadron: " << name << std::endl;
	member << "-- Leader: " << std::endl;
	if(leader) member << *leader << std::endl;
	else member << "No leader"<< std::endl;

	member << "-- Members:" << std::endl;
	if(size) {
		Members* currentHead = head;
		while (currentHead != nullptr) {
			if(currentHead->ship != leader) member << *currentHead->ship << std::endl;
			maxSpeed = std::min(currentHead->ship->speed(), maxSpeed);
			totalWeight += currentHead->ship->weight();
			currentHead = currentHead->next;
		}
	}
	else member << "No member";

	squadron << std::fixed << std::setprecision(0) << "max speed: "
				<< maxSpeed << " " << SPEED_UNIT << std::endl
				<< std::setprecision(2) << "total weight: " << totalWeight
				<< " " << WEIGHT_UNIT << std::endl;

	return os << squadron.str() << member.str();
}

// endregion

// region Operators

Squadron Squadron::operator+(Ship &ship) {
	return addShipCopy(ship);
}

Squadron Squadron::operator-(Ship &ship) {
	return removeShipCopy(ship);
}

Squadron& Squadron::operator+=(Ship& ship) {
	return addShip(ship);
}

Squadron& Squadron::operator-=(Ship& ship) {
	return removeShip(ship);
}

Squadron& Squadron::operator=(const Squadron& other) {
	if(this != &other) {
		freeMemory();
		copyOfSquadron(other);
	}
	return *this;
}

Squadron& Squadron::operator=(Squadron&& other) noexcept {
	if(this == &other) return *this;

	freeMemory();
	copyOfSquadron(other);

	// Réinitialise l'objet source (other)
	other.head = nullptr;
	other.size = 0;

	return *this;
}

Ship& Squadron::operator[](size_t index) const {
	return getShip(index);
}

/*!
 * \brief Output flow operator for displaying the squadron.
 * \param os Output flow
 * \param squadron Squadron to display
 * \return A reference on the modified output flow.
 */
std::ostream& operator<<(std::ostream& os, const Squadron& squadron) {
    return squadron.toStream(os);
}

// endregion