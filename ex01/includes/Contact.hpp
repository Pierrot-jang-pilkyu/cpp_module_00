#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

using	std::cout;
using	std::cin;
using	std::endl;
using	std::string;
using	std::getline;
using	std::setw;

class Contact
{
private:
	string	firstName;
	string	lastName;
	string	nickName;
	string	phoneNumber;
	string	darkestSecret;
public:
	Contact();
	Contact(string firstName, string lastName, string nickName, string phoneNumber,string darkestSecret);
	void	setFirstName(string firstName);
	void	setLastName(string lastName);
	void	setNickName(string nickName);
	void	setPhoneNumber(string phoneNumber);
	void	setDarkestSecret(string firstName);
	string	getFirstName(void);
	string	getLastName(void);
	string	getNickName(void);
	string	getPhoneNumber(void);
	string	getDarkestSecret(void);
	void	viewContact(void);
	~Contact();
};

#endif