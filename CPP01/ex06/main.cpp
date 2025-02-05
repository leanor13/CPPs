#include "Harl.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }

    Harl harl;
    std::string level = argv[1];

    int index = -1;
    if (level == "DEBUG") index = 0;
    else if (level == "INFO") index = 1;
    else if (level == "WARNING") index = 2;
    else if (level == "ERROR") index = 3;

    switch (index) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cerr << "Unknown log level" << std::endl;
            return 1;
    }

    return 0;
}
