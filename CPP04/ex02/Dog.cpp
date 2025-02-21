#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal() {
	type = "Dog";
	brain = new Brain;
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog] assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "[Dog] Destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Hau-Hau" << std::endl;
}

Brain *Dog::getBrain() const {
	return brain;
}