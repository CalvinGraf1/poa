/**
 * @file Container.hpp
 * @brief Declaration of the Container class and related operators.
 * @authors Demont Kilian & Graf Calvin
 */

#ifndef RIVER_CONTAINER_HPP
#define RIVER_CONTAINER_HPP

#include <string>
#include <list>
#include <memory>
#include "../people/Person.hpp"
#include "../people/drivers/Driver.hpp"

/**
 * @brief Class representing a container.
 * @details Provides functionalities for adding, removing, and displaying
 * people in the container.
 */
class Container {

private:
	const std::string name;

	std::list<const Person*> people;

	const static std::string PERSON_NOT_FOUND;

protected:
	/**
	 * @brief Construct a new Container object.
	 * @param name The name of the container.
	 */
	explicit Container(const std::string & name);

	/**
	 * @brief Construct a new Container object.
	 * @param name The name of the container.
	 * @param people The people to add to the container.
	 */
	Container(const std::string & name, std::list<const Person*> people);

public:

	/**
 	* @brief Destroy the Container object.
 	*/
	~Container() = default;

	/**
	 * @brief Construct a new Container object by copying.
	 * @param container The container to copy.
	 */
	Container(const Container&) = default;

	// To respect the rule of three, we delete the assignment by copying
	Container& operator=(const Container&) = delete;

	/**
	 * @brief Virtual function to add a person to the container.
	 * @param person The person to add.
	 */
	virtual void addPerson(const Person* person);

	/**
	 * @brief Remove a person from the container.
	 * @param person The person to remove.
	 * @throws std::runtime_error if the person is not in the container.
	 */
	void removePerson(const Person* person);

	/**
	 * @brief Get a string representation of the container.
	 * @return The string representation of the container.
	 */
	virtual std::string toString() const;

	/**
	 * @brief Get the number of people in the container.
	 * @return The number of people in the container
	 */
	size_t size() const;

	/**
	 * @brief Check if the container is empty.
	 * @return True if the container is empty, false otherwise.
	 */
	bool isEmpty() const;

	/**
	 * @brief Clear the container.
	 */
	void clear();

	/**
	 * @brief Check if the container contains a person.
	 * @param person The person to check.
	 * @return True if the container contains the person, false otherwise.
	 */
	bool contains(const Person&  person) const;

	/**
	 * @brief Get the name of the container.
	 * @return The name of the container.
	 */
	std::string getName() const;

	/**
	 * @brief Get the people in the container.
	 * @return The people in the container.
	 */
	[[nodiscard]] const std::list<const Person*>& getPeople() const;

	/**
	 * @brief Get a string representation of the people in the container.
	 * @return The string representation of the people in the container.
	 */
	const std::string peopleToString() const;

    /**
    * @brief Clone the container.
    * @return A pointer to a new container that is a clone of the current container.
    */
    [[nodiscard]] virtual Container * clone() const = 0;
};


#endif //RIVER_CONTAINER_HPP