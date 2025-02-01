#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), 
					nickName(""), phoneNumber(""), darkestSecret(""){
}

// copy constructor
Contact::Contact(const Contact& other){
	*this = other;
}

// assignment operator
Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        this->firstName = other.firstName;
        this->lastName = other.lastName;
        this->nickName = other.nickName;
        this->phoneNumber = other.phoneNumber;
        this->darkestSecret = other.darkestSecret;
    }
    return *this;
}

// destructor
Contact::~Contact(){}

// getters
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickName() const { return nickName; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }

void Contact::displayFullInfo() const {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

void Contact::displayShortInfo(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|"
              << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|"
              << std::setw(10) << (nickName.length() > 10 ? nickName.substr(0, 9) + "." : nickName) << std::endl;
}

bool isValidPhoneNumber(const std::string& number) {
    if (number.empty()) return false;

    for (size_t i = 0; i < number.length(); i++) {
        if (!isdigit(number[i])) return false;
    }
    return true;
}

void Contact::setContactDetails() {
    std::cout << "Enter first name: ";
    while (std::getline(std::cin, firstName) && firstName.empty())
        std::cout << "First name cannot be empty. Try again: ";

    std::cout << "Enter last name: ";
    while (std::getline(std::cin, lastName) && lastName.empty())
        std::cout << "Last name cannot be empty. Try again: ";

    std::cout << "Enter nickname: ";
    while (std::getline(std::cin, nickName) && nickName.empty())
        std::cout << "Nickname cannot be empty. Try again: ";

    std::cout << "Enter phone number: ";
    while (std::getline(std::cin, phoneNumber) && !isValidPhoneNumber(phoneNumber))
        std::cout << "Phone number cannot be empty and should contain only digits. Try again: ";

    std::cout << "Enter darkest secret: ";
    while (std::getline(std::cin, darkestSecret) && darkestSecret.empty())
        std::cout << "Darkest secret cannot be empty. Try again: ";
}