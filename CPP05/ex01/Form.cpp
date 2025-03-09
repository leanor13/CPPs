#include "Form.hpp"
#include "Bureaucrat.hpp"

// --- Exception implementations ---
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high to sign!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low to sign!";
}

// --- Constructors ---
Form::Form(const std::string& name, int signGrade, const int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

// --- Getters ---
std::string Form::getName() const { return _name; }
bool Form::isFormSigned() const { return _isSigned; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }

// --- Signing function ---
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

// --- Overloaded << operator (now outside the class) ---
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << " (Sign Grade: " << form.getSignGrade()
       << ", Exec Grade: " << form.getExecGrade() << ", Signed: " << (form.isFormSigned() ? "Yes" : "No") << ")";
    return os;
}
