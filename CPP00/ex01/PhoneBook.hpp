#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook {
	private:
		Contact contacts[8];
		int count;
		int oldest;

	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContacts() const;
};

#endif