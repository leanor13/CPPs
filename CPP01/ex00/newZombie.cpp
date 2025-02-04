#include "Zombie.hpp"

// here we are using heap and the object will be deleted only when we call delete
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
