#include "Zombie.hpp"

int main() {
    std::cout << "== Test 1: Creating a horde of 5 zombies ==" << std::endl;
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zomb");

    if (horde) {
        for (int i = 0; i < N; i++) {
            horde[i].announce();
        }
        delete[] horde;
		horde = nullptr;
    }

    std::cout << "\n== Test 2: Edge case (N = 1) ==" << std::endl;
    N = 1;
    horde = zombieHorde(N, "LoneZombie");
    if (horde) {
        horde[0].announce();
        delete[] horde;
		horde = nullptr;
    }

    std::cout << "\n== Test 3: Invalid case (N = 0) ==" << std::endl;
    horde = zombieHorde(0, "NoZombie");

    std::cout << "\n== Test 4: Invalid case (N = -3) ==" << std::endl;
    horde = zombieHorde(-3, "NegativeZombie");

    return 0;
}
