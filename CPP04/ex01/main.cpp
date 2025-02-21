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

    // NEW: Test for ideas storage and retrieval
    std::cout << "\n--- Test 8: Brain Ideas Storage and Retrieval ---" << std::endl;
    
    Dog brainyDog;
    Cat brainyCat;

    // Set ideas
    brainyDog.getBrain()->setIdea(0, "Chase the cat");
    brainyDog.getBrain()->setIdea(1, "Bark at the postman");
    brainyCat.getBrain()->setIdea(0, "Sleep on the keyboard");
    brainyCat.getBrain()->setIdea(1, "Knock things off the table");

    // Retrieve and display ideas
    std::cout << "Dog Idea 0: " << brainyDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog Idea 1: " << brainyDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "Cat Idea 0: " << brainyCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat Idea 1: " << brainyCat.getBrain()->getIdea(1) << std::endl;

    // Test copying ideas
    Dog copiedDog = brainyDog;
    Cat copiedCat = brainyCat;

    bool dogsAreEqual = copiedDog.getBrain()->getIdea(0) == brainyDog.getBrain()->getIdea(0);
    bool catsAreEqual = copiedCat.getBrain()->getIdea(0) == brainyCat.getBrain()->getIdea(0);

    std::cout << "Dogs are equal before modification: " << (dogsAreEqual ? "YES" : "NO") << std::endl;
    std::cout << "Cats are equal before modification: " << (catsAreEqual ? "YES" : "NO") << std::endl;

    std::cout << "\nCopied Dog Idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 1: " << copiedDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "Copied Cat Idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat Idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;

    // Modify original and check if copied remains unchanged (Deep Copy Test)
    brainyDog.getBrain()->setIdea(0, "New Dog Idea");
    brainyCat.getBrain()->setIdea(0, "New Cat Idea");

    std::cout << "\nModified Original Dog Idea 0: " << brainyDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0 (Should be unchanged): " << copiedDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "Modified Original Cat Idea 0: " << brainyCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat Idea 0 (Should be unchanged): " << copiedCat.getBrain()->getIdea(0) << std::endl;

    dogsAreEqual = copiedDog.getBrain()->getIdea(0) == brainyDog.getBrain()->getIdea(0);
    catsAreEqual = copiedCat.getBrain()->getIdea(0) == brainyCat.getBrain()->getIdea(0);

    std::cout << "Dogs are equal after modification: " << (dogsAreEqual ? "YES" : "NO") << std::endl;
    std::cout << "Cats are equal after modification: " << (catsAreEqual ? "YES" : "NO") << std::endl;


    // Accessing out-of-bounds ideas
    std::cout << "\n--- Test 9: Out-of-bounds Access ---" << std::endl;
    std::cout << "Dog Out of Bounds Idea: " << brainyDog.getBrain()->getIdea(200) << std::endl;
    std::cout << "Cat Negative Index Idea: " << brainyCat.getBrain()->getIdea(-1) << std::endl;

    std::cout << "\n--- Test Complete ---" << std::endl;
   

    return 0;
}

