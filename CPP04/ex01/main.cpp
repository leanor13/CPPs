#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main() {
    // Test from pdf
    std::cout << "\n--- Test 1: Basic Creation and Deletion ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n--- Test 2: Array of Animals ---" << std::endl;
    const Animal* animals[4] = { new Dog(), new Cat(), new Dog(), new Cat() };
    for (int k = 0; k < 4; ++k) {
        delete animals[k];
    }

    std::cout << "\n--- Test 3: Copying Objects ---" << std::endl;
    Dog dog1;
    Dog dog2 = dog1;
    Cat cat1;
    Cat cat2(cat1);

    std::cout << "\n--- Test 4: Assigning Objects ---" << std::endl;
    Dog dog3;
    dog3 = dog1;
    Cat cat3;
    cat3 = cat1;

    std::cout << "\n--- Test 5: Dynamic Creation ---" << std::endl;
    Dog* dynamicDog = new Dog();
    dynamicDog->makeSound();
    Cat* dynamicCat = new Cat();
    dynamicCat->makeSound();
    delete dynamicDog;
    delete dynamicCat;

    std::cout << "\n--- Test 6: Polymorphism with Animal Pointers ---" << std::endl;
    Animal* polymorphicAnimals[2];
    polymorphicAnimals[0] = new Dog();
    polymorphicAnimals[1] = new Cat();

    for (int k = 0; k < 2; ++k) {
        polymorphicAnimals[k]->makeSound();
        delete polymorphicAnimals[k];
    }

    std::cout << "\n--- Test 7: Assigning via Pointers ---" << std::endl;
    Dog* dogPointer1 = new Dog();
    Dog* dogPointer2 = new Dog();
    *dogPointer2 = *dogPointer1;
    delete dogPointer1;
    delete dogPointer2;

    std::cout << "\n--- Test Complete ---" << std::endl;

    return 0;
}

