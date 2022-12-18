#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->addCount = -1;
}

int		PhoneBook::getContactSize(void)
{
	return (this->addCount < 8 ? (this->addCount + 1) : 8);
}

void	PhoneBook::openPhoneBook(PhoneBook &phoneBook)
{
	string	cmd;

	while (1)
	{
		cout << endl << "Wellcome to phonebook." << endl;
		cout << "Please enter the command [ ADD / SEARCH / EXIT ]: ";
		getline(cin, cmd);
		if (cmd.compare("ADD") == 0)
			addPhoneBook(phoneBook);
		else if (cmd.compare("SEARCH") == 0)
			searchPhoneBook(phoneBook);
		else if (cmd.compare("EXIT") == 0)
		{
			cout << endl << "Thank you for using. Good luck." << endl;
			break ;
		}
		else
			cout << endl << "Error : Wrong command. Please must use uppercase character." << endl << endl;
	}
}

void	PhoneBook::addPhoneBook(PhoneBook &phoneBook)
{
	int		idx;
	string	str[5];

	phoneBook.addCount++;
	cout << endl << endl;
	cout << "1. Please enter the first name		: "; getline(cin, str[0]);
	cout << "2. Please enter the last name		: "; getline(cin, str[1]);
	cout << "3. Please enter the nick name		: "; getline(cin, str[2]);
	cout << "4. Please enter the phone number	: "; getline(cin, str[3]);
	cout << "5. Please enter the darkest secret	: "; getline(cin, str[4]);
	cout << endl << endl;
	
	idx = phoneBook.addCount % 8;
	phoneBook.contact[idx].setFirstName(str[0]);
	phoneBook.contact[idx].setLastName(str[1]);
	phoneBook.contact[idx].setNickName(str[2]);
	phoneBook.contact[idx].setPhoneNumber(str[3]);
	phoneBook.contact[idx].setDarkestSecret(str[4]);

	cout << "Your contact has been successfully saved." << endl;
	cout << endl << endl;
}

void	PhoneBook::searchPhoneBook(PhoneBook &phoneBook)
{
	int		idx;
	string	str;

	idx = -1;
	cout << "|------------------Contact------------------|" << endl;
	cout << "|     index|First Name| Last Name| Nick Name|" << endl;
	cout << "|-------------------------------------------|" << endl;

	while (++idx < phoneBook.getContactSize())
	{
		cout << "|" << setw(10) << idx;
		phoneBook.printTenChar(phoneBook.contact[idx].getFirstName());
		phoneBook.printTenChar(phoneBook.contact[idx].getLastName());
		phoneBook.printTenChar(phoneBook.contact[idx].getNickName());
		cout << "|" << endl;
	}

	cout << "|-------------------------------------------|" << endl << endl;

	if (phoneBook.getContactSize() == 0)
		return ;
	while (1)
	{
		cout << "Please enter the index of the contact you want to see [0 ~ 7] : "; getline(cin, str);
		if (std::stoi(str) > 7)
			cout << "Wrong Input data. " << endl << endl;
		else
		{
			idx = std::stoi(str);
			if (idx > phoneBook.getContactSize() - 1)
			{
				cout << "Can't search to the index in Phonebook." << endl;
				break ;
			}
			phoneBook.contact[idx].viewContact();
			break ;
		}
	}

}

void	PhoneBook::printTenChar(string str)
{
	if (str.size() <= 10)
		cout << "|" << setw(10) << str;
	else
		cout << "|" << setw(10) << str.substr(0, 9) << ".";
}

PhoneBook::~PhoneBook()
{
}