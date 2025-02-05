#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
	// Human A always has weapon, so we can put a reference here
    Weapon &weapon;

public:
    HumanA(std::string name, Weapon &weapon);
    void attack() const;
};

#endif // HUMANA_HPP
