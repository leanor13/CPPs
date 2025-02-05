#include "Harl.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    Harl harl;

    switch (argc) {
        case 2:
            harl.complain(argv[1]);
            break;
        default:
            std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    return 0;
}
