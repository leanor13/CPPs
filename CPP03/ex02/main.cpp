#include "FragTrap.hpp"
#include <iostream>

int main() {
    // Test 1: Default constructor
    std::cout << "\n[TEST 1: Default constructor]" << std::endl;
    FragTrap fragDefault;

    // Test 2: Constructor with name
    std::cout << "\n[TEST 2: Constructor with name]" << std::endl;
    FragTrap fragNamed("Fraggy");

    // Test 3: Copy constructor
    std::cout << "\n[TEST 3: Copy constructor]" << std::endl;
    FragTrap fragCopy(fragNamed);

    // Test 4: Copy assignment operator
    std::cout << "\n[TEST 4: Copy assignment operator]" << std::endl;
    FragTrap fragAssigned;
    fragAssigned = fragNamed;

    // Test 5: Attack
    std::cout << "\n[TEST 5: FragTrap Attack method]" << std::endl;
    fragNamed.attack("Target Dummy");

    // Test 6: High Fives
    std::cout << "\n[TEST 6: FragTrap High Fives]" << std::endl;
    fragNamed.highFivesGuys();

    // End of tests
    std::cout << "\n[End of tests]" << std::endl;

    return 0;
}
