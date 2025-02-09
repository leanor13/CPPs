#include "Brain.hpp"

Brain::Brain() {
	std::cout << "[Brain] default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "";
    }
}

Brain::Brain(const Brain& other) {
	std::cout << "[Brain] Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i ++) {
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "[Brain] assignment operator is called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i ++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor is called" << std::endl;
}