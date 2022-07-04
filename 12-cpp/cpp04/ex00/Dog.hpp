#ifndef DOG_HPP
# define DOG_HPP

#include <Animal.hpp>
#include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(std::string type);
		Dog(const Dog &dog);

		Dog &operator=(const Dog &dog);

		void	makeSound(void) const;
};

#endif
