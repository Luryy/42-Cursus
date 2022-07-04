#include <WrongCat.hpp>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default contructor called" << std::endl;
};

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
};

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat contructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat &wrongCat)
{
	std::cout << "WrongCat copy contructor called" << std::endl;
	*this = wrongCat;
};

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &wrongCat)
		type = wrongCat.type;
	return (*this);
};

void	WrongCat::makeSound(void) const
{
	std::cout << "*miauuuu*" << std::endl;
};
