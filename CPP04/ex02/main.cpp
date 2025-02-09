#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main() {
    // Test from pdf
    std::cout << "\n--- Test 1: Basic Creation and Deletion ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    //const Animal* an = new Animal();
    delete j;
    delete i;

    std::cout << "\n--- Test: Array of Animals ---" << std::endl;
    const Animal* animals[2] = { new Dog(), new Cat() };
    for (int k = 0; k < 2; ++k) {
        animals[k]->makeSound();
        delete animals[k];
    }

    // Test: Copying Objects
    std::cout << "\n--- Test: Copying Objects ---" << std::endl;
    Dog dog1;
    Dog dog2 = dog1;
    Cat cat1;
    Cat cat2(cat1);

    // Test: Assigning Objects
    std::cout << "\n--- Test: Assigning Objects ---" << std::endl;
    Dog dog3;
    dog3 = dog1;
    Cat cat3;
    cat3 = cat1;

    // Test: Dynamic Creation
    std::cout << "\n--- Test: Dynamic Creation ---" << std::endl;
    const Animal* dynamicDog = new Dog();
    const Animal* dynamicCat = new Cat();
    dynamicDog->makeSound();
    dynamicCat->makeSound();
    delete dynamicDog;
    delete dynamicCat;

    return 0;
}

