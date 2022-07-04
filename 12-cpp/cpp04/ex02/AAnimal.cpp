#include <AAnimal.hpp>

AAnimal::AAnimal(void) : type("AAnimal Base")
{
	std::cout << "AAnimal default contructor called" << std::endl;
};

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
};

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal contructor called" << std::endl;
};

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout << "AAnimal copy contructor called" << std::endl;
	*this = animal;
};

AAnimal &AAnimal::operator=(const AAnimal &animal)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &animal)
		type = animal.type;
	return (*this);
};

std::string		AAnimal::getType(void) const
{
	return (type);
}
