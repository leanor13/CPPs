#include "ScavTrap.hpp"
#include <iostream>

const std::string	DEFAULT_NAME = "Noname_ScavTrap";
const int			DEFAULT_HIT_POINTS = 100;
const int			DEFAULT_ENERGY_POINTS = 50;
const int			DEFAULT_ATTACK_DAMAGE = 20;

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = DEFAULT_NAME;
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;

	std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {

	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;

	std::cout << "ScavTrap: Default constructor called with name: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;

	std::cout << "ScavTrap " << _name << ": Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << _name << ": assignment operator called" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << ": Destructor called" << std::endl;
}

// attack method is different from parent - has different message and validation
void ScavTrap::attack(const std::string& target) {
    if (_energyPoints > 0) {
        std::cout << "ScavTrap " << _name << " viciously attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << _name << " is out of energy and cannot attack!" << std::endl;
    }
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " ENTERED GATE KEEPER MODE" << std::endl;
}


