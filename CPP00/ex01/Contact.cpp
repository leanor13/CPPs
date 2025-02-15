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

static bool isValidPhoneNumber(const std::string& number) {
    if (number.empty()) return false;

    for (size_t i = 0; i < number.length(); i++) {
        if (!isdigit(number[i])) return false;
    }
    return true;
}

void Contact::checkEOF() {
    if (std::cin.eof()) {
        std::cerr << "\n*End of input detected. Exiting...*\n";
        exit(1);
    }
}

void Contact::setContactDetails() {
    const std::string fieldNames[] = {
        "first name", "last name", "nickname", "phone number", "darkest secret"
    };
    std::string* fields[] = {
        &firstName, &lastName, &nickName, &phoneNumber, &darkestSecret
    };

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter " << fieldNames[i] << ": ";
        while (true) {
            if (!std::getline(std::cin, *fields[i])) {
                checkEOF();
            }
            if (i == 3) {
                if (isValidPhoneNumber(*fields[i])) break;
                std::cout << "Invalid phone number! Must contain only digits (0-9). Try again: ";
            } else {
                if (!fields[i]->empty()) break;
                std::cout << fieldNames[i] << " cannot be empty. Try again: ";
            }
        }
    }
    std::cout << "Contact added successfully!\n";
}
