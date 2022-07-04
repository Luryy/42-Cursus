#include <Contact.hpp>

Contact::Contact(void) {}

Contact::~Contact(void) {}

void	Contact::setId(int id) {
	this->id = id;
};

void	Contact::setFirstName(std::string name) {
	this->firstName = name;
};

void	Contact::setLastName(std::string name) {
	this->lastName = name;
};

void	Contact::setNickName(std::string name) {
	this->nickName = name;
};

void	Contact::setPhoneNumber(std::string number) {
	this->phoneNumber = number;
};

void	Contact::setDarkSecret(std::string secret) {
	this->darkSecret = secret;
};

int	Contact::getId(void) {
	return this->id;
};

std::string	Contact::getFirstName(void) {
	return this->firstName;
};

std::string	Contact::getLastName(void) {
	return this->lastName;
};

std::string	Contact::getNickName(void) {
	return this->nickName;
};

std::string	Contact::getPhoneNumber(void) {
	return this->phoneNumber;
};

std::string	Contact::getDarkSecret(void) {
	return this->darkSecret;
};
