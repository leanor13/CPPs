#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    Bureaucrat alice("Alice", 2);

    AForm* form1 = intern.makeForm("shrubbery creation", "home");
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    AForm* form3 = intern.makeForm("presidential pardon", "Ford Prefect");
    AForm* form4 = intern.makeForm("unknown form", "TargetX"); // this one should through exception

    if (form1) {
        alice.signForm(*form1);
        alice.executeForm(*form1);
        delete form1;
    }
    if (form2) {
        alice.signForm(*form2);
        alice.executeForm(*form2);
        delete form2;
    }
    if (form3) {
        alice.signForm(*form3);
        alice.executeForm(*form3);
        delete form3;
    }
    if (form4) {
        alice.signForm(*form3);
        alice.executeForm(*form3);
        delete form3;
    }

    return 0;
}
