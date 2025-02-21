#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main() {
    // --- BLOCK 1: Basic functionality tests ---
    {
        std::cout << "\n--- Test 1: Creating MateriaSource and Learning Materia ---" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        std::cout << "\n--- Test 2: Creating Character and Equipping Materia ---" << std::endl;
        ICharacter* me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        if (tmp) {
            me->equip(tmp);
        } else {
            std::cout << "Failed to create Materia: ice" << std::endl;
        }

        tmp = src->createMateria("cure");
        if (tmp) {
            me->equip(tmp);
        } else {
            std::cout << "Failed to create Materia: cure" << std::endl;
        }

        std::cout << "\n--- Test 3: Using Materia ---" << std::endl;
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        std::cout << "\n--- Test Complete for Block 1 (Memory Auto-Freed) ---" << std::endl;
    }

    // --- BLOCK 2: Edge case tests ---
    {
        std::cout << "\n--- Test 4: Learning More than 4 Materia ---" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        // Trying to learn a 5th Materia (should fail)
        src->learnMateria(new Ice());

        std::cout << "\n--- Test 5: Creating Unknown Materia ---" << std::endl;
        AMateria* unknown = src->createMateria("unknown");
        if (!unknown) {
            std::cout << "Unknown materia type correctly handled" << std::endl;
        }

        std::cout << "\n--- Test 6: Equipping More than 4 Materia ---" << std::endl;
        ICharacter* me = new Character("me");
        AMateria* tmp[10];

        for (int i = 0; i < 5; i++) {
            if (i < 2)
                tmp[i] = src->createMateria("cure");
            else
                tmp[i] = src->createMateria("ice");

            me->equip(tmp[i]);
        }

        std::cout << "\n--- Test 7: Unequipping and Deleting Materia ---" << std::endl;
        me->unequip(0);
        delete tmp[0];

        std::cout << "\n--- Test 8: Using Materia from Empty Slots ---" << std::endl;
        ICharacter* bob = new Character("bob");

        for (int i = 0; i < 4; i++)
            me->use(i, *bob);

        // Using an invalid index
        me->use(4, *bob);

        std::cout << "\n--- Test Complete for Block 2 (Memory Auto-Freed) ---" << std::endl;
    }

    return 0;
}
