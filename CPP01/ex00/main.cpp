#include "Zombie.hpp"

int main() {
    std::cout << "== Test 1: Creating single zombie in heap ==" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "\n== Test 2: Creating single zombie in stack ==" << std::endl;
    randomChump("StackZombie");

    std::cout << "\n== Test 3: Creating multiple zombies in heap ==" << std::endl;
    Zombie* heapZombie1 = newZombie("HeapZombie1");
    Zombie* heapZombie2 = newZombie("HeapZombie2");
    heapZombie1->announce();
    heapZombie2->announce();
    delete heapZombie1;
    delete heapZombie2;

    std::cout << "\n== Test 4: Creating multiple zombies in stack ==" << std::endl;
    randomChump("StackZombie1");
    randomChump("StackZombie2");

    std::cout << "\n== Test 5: Creating zombies with empty names ==" << std::endl;
    Zombie* emptyZombie = newZombie("");
    emptyZombie->announce();
    delete emptyZombie;

    randomChump(" ");
    randomChump("");

    return 0;
}
