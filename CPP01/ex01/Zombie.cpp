#include "Zombie.hpp"

Zombie::Zombie() : name("Noname") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
	std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce() const {
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}