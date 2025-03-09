#include "AForm.hpp"
#include "Bureaucrat.hpp"

// --- Exception implementations ---
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high to sign!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low to sign!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// --- Constructors ---
AForm::AForm(const std::string& name, int signGrade, const int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::isFormSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

// --- Signing function ---
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm " << form.getName() << " (Sign Grade: " << form.getSignGrade()
       << ", Exec Grade: " << form.getExecGrade() << ", Signed: " << (form.isFormSigned() ? "Yes" : "No") << ")";
    return os;
}
