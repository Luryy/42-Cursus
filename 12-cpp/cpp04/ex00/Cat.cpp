#include <Cat.hpp>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default contructor called" << std::endl;
};

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
};

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat contructor called" << std::endl;
};

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy contructor called" << std::endl;
	*this = cat;
};

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &cat)
		type = cat.type;
	return (*this);
};

void	Cat::makeSound(void) const
{
	std::cout << "*miauuuu*" << std::endl;
};
