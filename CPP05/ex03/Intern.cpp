#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

static AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(std::string) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cerr << "Intern couldn't create form: unknown form name '" << formName << "'" << std::endl;
    return nullptr;
}
