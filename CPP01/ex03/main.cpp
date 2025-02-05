#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {
    Weapon club("crude spiked club");

    std::cout << "\n== Test 1: HumanA attacks ==" << std::endl;
    std::cout << "[Expected] Amalia attacks with their crude spiked club" << std::endl;
    HumanA amalia("Amalia", club);
    amalia.attack();
    
    std::cout << "[Expected] Amalia attacks with their some other type of club" << std::endl;
    club.setType("some other type of club");
    amalia.attack();

    std::cout << "\n== Test 2: HumanB without weapon ==" << std::endl;
    std::cout << "[Expected] Ben has no weapon!" << std::endl;
    HumanB ben("Ben");
    ben.attack();

    std::cout << "[Expected] Ben attacks with their some other type of club" << std::endl;
    ben.setWeapon(club);
    ben.attack();

    std::cout << "\n== Test 3: HumanB changes weapon ==" << std::endl;
    std::cout << "[Expected] Ben attacks with their sharp sword" << std::endl;
    Weapon sword("sharp sword");
    ben.setWeapon(sword);
    ben.attack();

    std::cout << "\n== Test 4: HumanA continues using updated weapon ==" << std::endl;
    std::cout << "[Expected] Amalia attacks with their reinforced club" << std::endl;
    club.setType("reinforced club");
    amalia.attack();

    return 0;
}
