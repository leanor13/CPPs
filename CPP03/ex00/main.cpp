#include "ClapTrap.hpp"
#include <iostream>

int main() {
    // Test 1: Default constructor
    std::cout << "\n[TEST 1: Default constructor]" << std::endl;
    ClapTrap defaultClap;

    // Test 2: Constructor with name
    std::cout << "\n[TEST 2: Constructor with name]" << std::endl;
    ClapTrap namedClap("Clappy");

    // Test 3: Copy constructor
    std::cout << "\n[TEST 3: Copy constructor]" << std::endl;
    ClapTrap copiedClap(namedClap);

    // Test 4: Copy assignment operator
    std::cout << "\n[TEST 4: Copy assignment operator]" << std::endl;
    ClapTrap assignedClap;
    assignedClap = namedClap;

    // Test 5: Additional copy and assignment checks
    std::cout << "\n[TEST 5: Multiple objects and chaining]" << std::endl;
    ClapTrap anotherClap("Another");
    ClapTrap thirdClap;
    thirdClap = anotherClap = namedClap; // Chain assignment

    // Verify all objects
    std::cout << "\nVerifying objects after chaining:" << std::endl;
    defaultClap.attack("Test Target 1");
    namedClap.attack("Test Target 2");
    copiedClap.attack("Test Target 3");
    assignedClap.attack("Test Target 4");
    anotherClap.attack("Test Target 5");
    thirdClap.attack("Test Target 6");

    // Test 6: Attack
    std::cout << "\n[TEST 6: Attack method]" << std::endl;
    namedClap.attack("Target Dummy");

    // Test 7: Take Damage
    std::cout << "\n[TEST 7: Take Damage method]" << std::endl;
    namedClap.takeDamage(5);

    // Test 8: Be Repaired
    std::cout << "\n[TEST 8: Be Repaired method]" << std::endl;
    namedClap.beRepaired(3);

    // End of tests
    std::cout << "\n[End of tests]" << std::endl;

    return 0;
}