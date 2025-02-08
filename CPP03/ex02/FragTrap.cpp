#include "FragTrap.hpp"
#include <iostream>

const std::string	DEFAULT_NAME = "Noname_FragTrap";
const int			DEFAULT_HIT_POINTS = 100;
const int			DEFAULT_ENERGY_POINTS = 100;
const int			DEFAULT_ATTACK_DAMAGE = 30;

FragTrap::FragTrap() : ClapTrap(DEFAULT_NAME)
{
	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;

	std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {

	_hitPoints = DEFAULT_HIT_POINTS;
	_energyPoints = DEFAULT_ENERGY_POINTS;
	_attackDamage = DEFAULT_ATTACK_DAMAGE;

	std::cout << "FragTrap: Default constructor called with name: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << ": Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap " << _name << ": assignment operator called" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << ": Destructor called" << std::endl;
}


void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " enthusiastically sends HIGH FIVE request!" << std::endl;
}


