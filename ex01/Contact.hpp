#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact {
	public:
		Contact(void);
		~Contact(void);

		void	setId(int id);
		void	setFirstName(std::string name);
		void	setLastName(std::string name);
		void	setNickName(std::string name);
		void	setPhoneNumber(std::string number);
		void	setDarkSecret(std::string secret);

		int	getId(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkSecret(void);

	private:
		int 		id;
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;
};

#endif
