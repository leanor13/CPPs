#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

		void checkEOF();

	public:
		Contact();
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		~Contact();

		void setContactDetails();
		void displayShortInfo(int index) const;
		void displayFullInfo() const;

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
};

#endif