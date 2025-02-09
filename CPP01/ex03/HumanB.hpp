#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(std::string name);
	// protection from getting NULL as weapon
    void setWeapon(Weapon& newWeapon);
    void attack() const;
};

#endif
