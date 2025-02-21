#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            inventory[i] = (other.inventory[i] ? other.inventory[i]->clone() : NULL);
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
	std::cout << "[Character] Equipped " << m->getType() << std::endl;
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
	std::cout << "[Character] Cannot equip " << m->getType() << ", inventory full!" << std::endl;
	delete m;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
		delete inventory[idx];
        inventory[idx] = NULL;
		std::cout << "[Character] Unequipped slot " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
