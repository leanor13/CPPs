#include "Brain.hpp"

Brain::Brain() : ideas{} {
	std::cout << "[Brain] default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "[Brain] Copy constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEAS; i ++) {
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "[Brain] assignment operator is called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < MAX_IDEAS; i ++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index < 0 || index >= MAX_IDEAS) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= MAX_IDEAS || ideas[index].empty()) {
        std::cout << "No idea at index " << index << std::endl;
        return "";
    }
    return ideas[index];
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor is called" << std::endl;
}