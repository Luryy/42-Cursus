#include <Cat.hpp>

Cat::Cat(void) : AAnimal("Cat"), brain(new Brain())
{
	std::cout << "Cat default contructor called" << std::endl;
};

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
};

Cat::Cat(const Cat &cat) : AAnimal(cat), brain(new Brain(*(cat.brain)))
{
	std::cout << "Cat copy contructor called" << std::endl;
};

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &cat)
	{
		type = cat.type;
		*brain = *(cat.brain);
	}
	return (*this);
};

void	Cat::makeSound(void) const
{
	std::cout << "*miauuuu*" << std::endl;
};

void	Cat::printIdea(int i) const
{
	std::cout << "Cat idea:" << i << " " << brain->getIdea(i) << std::endl;
};
