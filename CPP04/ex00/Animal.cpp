#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Unknown") {
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "[Animal] Copy constructor called" << std::endl;
	type = other.type;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		std::cout << "[Animal] Assignment operator called" << std::endl;
		type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "[Animal] Destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << " ... {unknown animal sound} ... " << std::endl;
}

std::string Animal::getType() const {
	return type;
}