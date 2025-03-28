/**
 * @file Container.cpp
 * @brief Definition of the Container class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#include "Container.hpp"
#include <algorithm>
#include <sstream>

const std::string Container::PERSON_NOT_FOUND = "Personne non présente dans le container.";


Container::Container(const std::string & name) : name(name) {}

Container::Container(const std::string & name, std::list<const Person *> people) :
	name(name), people(std::move(people)) {}

void Container::addPerson(const Person* person) { people.push_back(person); }

void Container::removePerson(const Person* person) {
	auto it = std::find(people.begin(), people.end(), person);
	if(it != people.end()) people.erase(it);
	else throw std::runtime_error(PERSON_NOT_FOUND);
}

std::string Container::toString() const {
	std::string display = name + ": " + peopleToString();
	return display;
}

size_t Container::size() const { return people.size(); }

bool Container::isEmpty() const { return people.empty(); }

void Container::clear() { people.clear(); }

bool Container::contains(const Person& person) const {
	if(std::find(people.begin(), people.end(), &person) != people.end())
		return true;
	return false;
}

const std::list<const Person*>& Container::getPeople() const { return people; }

const std::string Container::peopleToString() const {
	std::string people = "";
	for (const auto& person : Container::getPeople())
		people += person->getName() + " ";
	if(!people.empty()) people.pop_back();
	return people;
}

std::string Container::getName() const { return name; }