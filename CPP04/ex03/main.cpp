#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main() {
    std::cout << "\n--- Test 1: Creating MateriaSource and Learning Materia ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n--- Test 2: Creating Character and Equipping Materia ---" << std::endl;
    ICharacter* me = new Character("me");

    AMateria* tmp;
	tmp = src->createMateria("ice");
    if (tmp) {
        if (!me->equip(tmp)) {
        delete tmp;
        }
    }  
    tmp = src->createMateria("cure");
    if (tmp) {
        if (!me->equip(tmp)) {
            delete tmp;
        }
    }

    std::cout << "\n--- Test 3: Using Materia ---" << std::endl;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n--- Test 4: Unequipping and Re-equipping Materia ---" << std::endl;
    me->unequip(0);
    me->unequip(1);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n--- Test 5: Inventory Overload ---" << std::endl;
    me->equip(new Ice());
    me->equip(new Cure());
    me->equip(new Ice()); // Should not be equipped (inventory full)

    std::cout << "\n--- Test 6: Copying Characters ---" << std::endl;
    Character* clone = new Character(*(static_cast<Character*>(me)));
    clone->use(0, *bob);
    clone->use(1, *bob);

    std::cout << "\n--- Cleanup ---" << std::endl;
    delete bob;
    delete me;
    delete clone;
    delete src;

    return 0;
}
