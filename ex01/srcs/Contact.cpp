#include "../includes/Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(string firstName, string lastName, string nickName, string phoneNumber,string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void	Contact::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(string lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickName(string nickName)
{
	this->nickName = nickName;
}

void	Contact::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

string	Contact::getFirstName(void)
{
	return (this->firstName);
}

string	Contact::getLastName(void)
{
	return (this->lastName);
}

string	Contact::getNickName(void)
{
	return (this->nickName);
}

string	Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

string	Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}

void	Contact::viewContact(void)
{
	cout << "First Name		: " << this->firstName << endl;
	cout << "Last Name		: " << this->lastName << endl;
	cout << "Nick Name		: " << this->nickName << endl;
	cout << "Phone Number		: " << this->phoneNumber << endl;
	cout << "Darkest Secret		: " << this->darkestSecret << endl;
}

Contact::~Contact()
{
}
