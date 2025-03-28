/**
 * @file Field.hpp
 * @brief Definition of the Field class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef LAB4_FIELD_HPP
#define LAB4_FIELD_HPP

#include <list>
#include <limits>
#include "../Person/Humanoid.hpp"
#include "../Person/Human.hpp"
#include "../Person/Vampire.hpp"
#include "../Person/Buffy.hpp"

class Humanoid;

class Human;

class Vampire;

/**
 * @brief Class representing a field.
 * @details A field has a width, a height, a number of humans and a number
 * of vampires.
 */
class Field {
	std::list<Humanoid *> humanoids;
	int turn = 0;
	const size_t width, height;
	size_t nbHumans, nbVampires;

public:

	/**
	 * @brief Constructor of the Field class.
	 * @param width Width of the field.
	 * @param height Height of the field.
	 * @param nbHumans Number of humans on the field.
	 * @param nbVampires Number of vampires on the field.
	 */
	Field(const size_t width, const size_t height, size_t nbHumans,
			size_t nbVampires);


	/**
	 * @brief We prepare and execute the action of each humanoid, removing those
	 * that are dead and moving on to the next round.
	 */
	int nextTurn();

	/**
	 * @brief Find the closest humanoid of a specific type to a given humanoid.
	 * @tparam T The type of humanoid to find.
	 * @param h The humanoid from which to find the closest humanoid.
	 * @return The closest humanoid of the specified type.
	 */
	template<typename T>
	T *findClosest(const Humanoid &h) const {
		T *closest = nullptr;
		int minDist = std::numeric_limits<int>::max();
		T *specificType;

		for (Humanoid *humanoid: humanoids) {
			specificType = dynamic_cast<T *>(humanoid);
			if (specificType != nullptr) {
				int dist = humanoid->getPosition().distance(h.getPosition());
				if (dist < minDist) {
					minDist = dist;
					closest = specificType;
				}
			}
		}
		return closest;
	}

	/**
	 * @brief Get the number of humans on the field.
	 * @return The number of humans on the field.
	 */
	size_t getNbHuman() const;

	/**
	 * @brief Get the number of vampires on the field.
	 * @return The number of vampires on the field.
	 */
	size_t getNbVampire() const;

	/**
	 * @brief Get the list of humanoids on the field.
	 * @return The list of humanoids on the field.
	 */
	std::list<Humanoid *> getHumanoids() const;

	/**
	 * @brief Get the width of the field.
	 * @return The width of the field.
	 */
	size_t getWidth() const;

	/**
	 * @brief Get the height of the field.
	 * @return The height of the field.
	 */
	size_t getHeight() const;

	/**
	 * @brief Get the current turn.
	 * @return The current turn.
	 */
	int getTurn() const;

	/**
	 * @brief Decrease the number of vampires by one.
	 */
	void vampireDie();

	/**
	 * @brief Decrease the number of humans by one.
	 */
	void humanDie();

	/**
	 * @brief Increase the number of vampires by one.
	 */
	void vampireBorn();

	/**
	 * @brief Add a humanoid to the field.
	 * @param humanoid The humanoid to add.
	 */
	void addHumanoid(Humanoid *humanoid);
};

#endif //LAB4_FIELD_HPP
