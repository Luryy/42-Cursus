#include <PhoneBook.hpp>

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to your PhoneBook" << std::endl;
	std::cout << "Type \"ADD\" to add a new contact" << std::endl;
	std::cout << "Type \"SEARCH\" to display your contact list" << std::endl;
	std::cout << "Type \"EXIT\" to exit" << std::endl;

	this->running = 1;
	this->size = 0;
	this->last_index = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::run(void)
{
	while (this->running)
	{
		std::cout << "Command: ";
		std::getline(std::cin, this->command);
		execCommand();
	}
};

void	PhoneBook::addContact()
{
	Contact	new_contact;
	if (this->last_index > 7)
		this->last_index = 0;
	new_contact.setId(this->last_index);
	while (new_contact.getFirstName().empty())
	{

		std::cout << "First Name: ";
		std::getline(std::cin, this->command);
		new_contact.setFirstName(this->command);
	}
	while (new_contact.getLastName().empty())
	{
		std::cout << "Last Name: ";
		std::getline(std::cin, this->command);
		new_contact.setLastName(this->command);
	}
	while (new_contact.getNickName().empty())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, this->command);
		new_contact.setNickName(this->command);
	}
	while (new_contact.getPhoneNumber().empty())
	{
		std::cout << "PhoneNumber: ";
		std::getline(std::cin, this->command);
		new_contact.setPhoneNumber(this->command);
	}
	while (new_contact.getDarkSecret().empty())
	{
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, this->command);
		new_contact.setDarkSecret(this->command);
	}
	this->contacts[this->last_index] = new_contact;
	this->last_index++;
	if (this->size < 8)
		this->size++;
}

void	PhoneBook::showContactInline(int index)
{
	if (index >= 0 && index <= 7)
	{
		std::cout << std::right <<
		std::setw(10) << this->contacts[index].getId() <<
		'|' << std::setw(10) << truncate(this->contacts[index].getFirstName()) <<
		'|' << std::setw(10) << truncate(this->contacts[index].getLastName()) <<
		'|' << std::setw(10) << truncate(this->contacts[index].getNickName()) <<
		'|' << std::endl;
	}
}

void	PhoneBook::showContactDetails()
{
	int	index = -1;

	if (isdigit(this->command[0]))
		index = std::stoi(this->command);
	if (index >= 0 && index < this->size)
	{
		std::cout << "Index: " << this->contacts[index].getId() << std::endl;
		std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << this->contacts[index].getNickName() << std::endl;
		std::cout << "PhoneNumber: " << this->contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[index].getDarkSecret() << std::endl;
	}
	else
		std::cout << "Contact not found" << std::endl;
}

void	PhoneBook::indexContacts(void)
{
	std::cout << std::setfill(' ') << std::setw(10)  << "Index" << "|" ;
	std::cout << std::setfill(' ') << std::setw(10)  << "First Name" << "|" ;
	std::cout << std::setfill(' ') << std::setw(10)  << "Last Name" << "|" ;
	std::cout << std::setfill(' ') << std::setw(10)  << "Nickname" << "|" ;
	std::cout << std::endl;

	for (int i = 0; i < this->size; i++)
		showContactInline(i);
}

void	PhoneBook::execCommand(void)
{
	if (this->command == "EXIT")
		stop();
	else if (this->command == "ADD")
		this->addContact();
	else if (this->command == "SEARCH")
	{
		this->indexContacts();
		std::cout << "Contact's index: ";
		std::getline(std::cin, this->command);
		this->showContactDetails();
	}
};

void	PhoneBook::stop(void)
{
	this->running = 0;
};

std::string	PhoneBook::truncate(std::string info) {
	std::string truncInfo;

	if (info.length() > 10) {
		truncInfo = info.substr(0, 10);
		truncInfo[9] = '.';
		return truncInfo;
	}
	return info;
}
