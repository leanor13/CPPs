#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    // Test 1: Default constructor
    std::cout << "\n[TEST 1: Default constructor]" << std::endl;
    ScavTrap scavDefault;

    // Test 2: Constructor with name
    std::cout << "\n[TEST 2: Constructor with name]" << std::endl;
    ScavTrap scavNamed("Guardian");

    // Test 3: Copy constructor
    std::cout << "\n[TEST 3: Copy constructor]" << std::endl;
    ScavTrap scavCopy(scavNamed);

    // Test 4: Copy assignment operator
    std::cout << "\n[TEST 4: Copy assignment operator]" << std::endl;
    ScavTrap scavAssigned;
    scavAssigned = scavNamed;

    // Test 5: Attack
    std::cout << "\n[TEST 5: ScavTrap Attack method]" << std::endl;
    scavNamed.attack("Target Dummy");
    scavNamed.attack("Another Dummy");

    // Test 6: Gate Keeper mode
    std::cout << "\n[TEST 6: ScavTrap Gate Keeper mode]" << std::endl;
    scavNamed.guardGate();

    // Test 7: Destructor calls
    std::cout << "\n[TEST 8: Destructor calls at the end of scope]" << std::endl;

    return 0;
}
