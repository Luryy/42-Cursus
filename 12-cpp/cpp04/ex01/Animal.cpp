#include <Animal.hpp>

Animal::Animal(void) : type("Animal Base")
{
	std::cout << "Animal default contructor called" << std::endl;
};

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
};

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal contructor called" << std::endl;
};

Animal::Animal(const Animal &animal)
{
	std::cout << "Animal copy contructor called" << std::endl;
	*this = animal;
};

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &animal)
		type = animal.type;
	return (*this);
};

std::string		Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << "*noise*" << std::endl;
}
