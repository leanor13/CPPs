#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), oldest(0){}

PhoneBook::~PhoneBook(){}

void PhoneBook::addContact(){
	if (count < 8){
		contacts[count].setContactDetails();
		count ++;
	} else {
		std::cout << "replacing oldest contact" << std::endl;
		contacts[oldest].setContactDetails();
		oldest = (oldest + 1) % 8;
	}
	std::cout << "contact added" << std::endl;
}

void PhoneBook::searchContacts() const {
    if (count == 0) {
        std::cout << "The phonebook is empty!" << std::endl;
        return;
    }

    // Print header
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    // Print each contact's short info
    for (int i = 0; i < count; i++) {
        contacts[i].displayShortInfo(i);
    }

    // Ask for an index
    std::cout << "Enter the index of the contact to display: ";
    std::string input;
    std::getline(std::cin, input);

    // Validate input (must be a number and within range)
    if (input.length() != 1 || input[0] < '0' || input[0] >= '0' + count) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    int index = input[0] - '0'; // Convert char to int
    contacts[index].displayFullInfo();
}






