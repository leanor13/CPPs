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

    std::cout << "\n--- Test 2: Array of Animals ---" << std::endl;
    const Animal* animals[4] = { new Dog(), new Cat(), new Dog(), new Cat() };
    for (int k = 0; k < 4; ++k) {
        animals[k]->makeSound();
        delete animals[k];
    }

    std::cout << "\n--- Test 3: Copying Objects ---" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "I want a bone!");
    dog1.getBrain()->setIdea(1, "Chase the cat!");

    Dog dog2 = dog1; // deepcopy
    std::cout << "Dog1 Idea 0: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 Idea 0 (copied): " << dog2.getBrain()->getIdea(0) << std::endl;

    Cat cat1;
    cat1.getBrain()->setIdea(0, "I want to sleep!");
    cat1.getBrain()->setIdea(1, "Knock things off the table!");

    Cat cat2(cat1); // deepcopy
    std::cout << "Cat1 Idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 Idea 0 (copied): " << cat2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Test 4: Assigning Objects ---" << std::endl;
    Dog dog3;
    dog3 = dog1;
    std::cout << "Dog3 Idea 0 (assigned): " << dog3.getBrain()->getIdea(0) << std::endl;

    Cat cat3;
    cat3 = cat1;
    std::cout << "Cat3 Idea 0 (assigned): " << cat3.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Test 5: Dynamic Creation ---" << std::endl;
    const Animal* dynamicDog = new Dog();
    const Animal* dynamicCat = new Cat();
    dynamicDog->makeSound();
    dynamicCat->makeSound();
    delete dynamicDog;
    delete dynamicCat;

    std::cout << "\n--- Test 6: Deep Copy Test ---" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Original Dog Idea");
    Dog copiedDog(originalDog);

    // chainging original
    originalDog.getBrain()->setIdea(0, "Changed Dog Idea");

    std::cout << "Original Dog Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0 (should remain unchanged): " << copiedDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}

