#include "Zombie.hpp"

// here it's created on stack and deleted after the function ends
void randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}