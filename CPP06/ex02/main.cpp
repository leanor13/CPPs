#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(std::time(0));

    Base* obj = generate();

    std::cout << "Identifying by pointer: ";
    identify(obj);

    std::cout << "Identifying by reference: ";
    identify(*obj);

    delete obj;

    std::cout << "\nTesting with NULL pointer:\n";
    identify(NULL);

    std::cout << "\nTesting with unknown type:\n";
    struct Fake : public Base {};
    Fake unknown;
    identify(&unknown);
    identify(unknown);

    return 0;
}
