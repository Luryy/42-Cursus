#include <Dog.hpp>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default contructor called" << std::endl;
};

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
};

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog contructor called" << std::endl;
};

Dog::Dog(const Dog &dog)
{
	std::cout << "Dog copy contructor called" << std::endl;
	*this = dog;
};

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &dog)
		type = dog.type;
	return (*this);
};

void	Dog::makeSound(void) const
{
	std::cout << "*auauauau*" << std::endl;
};
