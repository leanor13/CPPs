#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		Contact(const Contact& other);
		Contact& operator=(const Contact& other);
		~Contact();

		void setContactDetails();
		void displayShortInfo(int index) const;
		void displayFullInfo() const;
};

#endif