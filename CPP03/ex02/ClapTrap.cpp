#include "ClapTrap.hpp"

const std::string	DEFAULT_NAME = "Noname";
const int			DEFAULT_HIT_POINTS = 10;
const int			DEFAULT_ENERGY_POINTS = 10;
const int			DEFAULT_ATTACK_DAMAGE = 0;

ClapTrap::ClapTrap()
	: _name(DEFAULT_NAME),
	  _hitPoints(DEFAULT_HIT_POINTS),
	  _energyPoints(DEFAULT_ENERGY_POINTS),
	  _attackDamage(DEFAULT_ATTACK_DAMAGE) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	  _hitPoints(DEFAULT_HIT_POINTS),
	  _energyPoints(DEFAULT_ENERGY_POINTS),
	  _attackDamage(DEFAULT_ATTACK_DAMAGE) {
	std::cout << "ClapTrap Constructor called with name: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap " << _name << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		std::cout << "ClapTrap " << _name << " Copy assignment operator called" << std::endl;
		this->_name = other._name;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << _name << " attacks " << target 
	<< " causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " takes " << amount 
	<< " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " restores " << amount 
	<< " hit points" << std::endl;
}
