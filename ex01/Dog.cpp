#include <Dog.hpp>

Dog::Dog(void) : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog default contructor called" << std::endl;
};

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
};

Dog::Dog(const Dog &dog) : Animal(dog), brain(new Brain(*(dog.brain)))
{
	std::cout << "Dog copy contructor called" << std::endl;
};

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &dog)
	{
		type = dog.type;
		*(this->brain) = *(dog.brain);
	}
	return (*this);
};

void	Dog::makeSound(void) const
{
	std::cout << "*auauauau*" << std::endl;
};

void	Dog::printIdea(int i) const
{
	std::cout << "Dog idea:" << i << " " << brain->getIdea(i) << std::endl;
};

