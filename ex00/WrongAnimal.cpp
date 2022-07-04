#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal(void) : type("WrongAnimal Base")
{
	std::cout << "WrongAnimal default contructor called" << std::endl;
};

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal contructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	std::cout << "WrongAnimal copy contructor called" << std::endl;
	*this = wrongAnimal;
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &wrongAnimal)
		type = wrongAnimal.type;
	return (*this);
};

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*noise*" << std::endl;
}

std::string		WrongAnimal::getType(void) const
{
	return (type);
}
