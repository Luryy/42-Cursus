#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <Contact.hpp>
#include <iomanip>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	run(void);

	private:
		int		running;
		int		size;
		int		last_index;
		Contact	contacts[8];
		std::string	command;

		void	indexContacts(void);
		void	addContact(void);
		void	showContactInline(int index);
		void	showContactDetails();
		void	execCommand(void);
		void	stop(void);
		std::string	truncate(std::string info);
};

#endif
