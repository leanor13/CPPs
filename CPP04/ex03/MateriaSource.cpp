#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other.learned[i])
            learned[i] = other.learned[i]->clone();
        else
            learned[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete learned[i];
            learned[i] = (other.learned[i] ? other.learned[i]->clone() : NULL);
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete learned[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        std::cout << "[MateriaSource] Cannot learn NULL Materia" << std::endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (!learned[i]) {
            learned[i] = m;
            std::cout << "[MateriaSource] Learned new Materia: " << m->getType() << std::endl;
            return;
        }
    }

    std::cout << "[MateriaSource] Cannot learn more than 4 Materia! Deleting extra." << std::endl;
    delete m;
}


AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (learned[i] && learned[i]->getType() == type) {
            AMateria* cloned = learned[i]->clone();
            if (!cloned) {
                std::cout << "[MateriaSource] Failed to clone Materia: " << type << std::endl;
                return NULL;
            }
            return cloned;
        }
    }
    std::cout << "[MateriaSource] Cannot create Materia of type: " << type << std::endl;
    return NULL;
}
