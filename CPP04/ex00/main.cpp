#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << "\n--- Array of Animals Tests ---" << std::endl;
    const Animal* animals[3] = { new Animal(), new Cat(), new Dog() };
    for (int k = 0; k < 3; ++k) {
        std::cout << "Animal type: " << animals[k]->getType() << std::endl;
        animals[k]->makeSound();
    }
    for (int k = 0; k < 3; ++k) {
        delete animals[k];
    }

    std::cout << "\n--- Copy Constructor and Assignment Tests ---" << std::endl;
    Cat cat1;
    Cat cat2(cat1);
    Dog dog1;
    Dog dog2 = dog1;
    Cat cat3;
    cat3 = cat1;
    Dog dog3;
    dog3 = dog1;

    std::cout << "\n--- Destructor Order Tests ---" << std::endl;
    const Animal* catDestructorTest = new Cat();
    const Animal* dogDestructorTest = new Dog();
    delete catDestructorTest;
    delete dogDestructorTest;

    std::cout << "\n--- Multiple Objects Creation and Deletion ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        const Animal* animalCycle = new Cat();
        animalCycle->makeSound();
        delete animalCycle;
    }

	std::cout << "\n--- Equality Check using getType() ---" << std::endl;
	if (cat3.getType() == dog3.getType()) {
		std::cout << "Cat and Dog are equal." << std::endl;
	} else {
		std::cout << "Cat and Dog are not equal." << std::endl;
	}

	return 0;
}