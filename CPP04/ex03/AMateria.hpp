#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp" // for use() method

class AMateria {
protected:
    std::string type;

public:
    AMateria(std::string const & type);
    virtual ~AMateria();

    std::string const & getType() const; // Return type (ice, cure etc)
    virtual AMateria* clone() const = 0; // has to be defined in children
    virtual void use(ICharacter& target); // interaction with character
};

#endif
