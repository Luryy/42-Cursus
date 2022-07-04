#ifndef DOG_HPP
# define DOG_HPP

#include <AAnimal.hpp>
#include <Brain.hpp>
#include <iostream>

class Dog : public AAnimal
{
	private:
		Brain* brain;

	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(std::string type);
		Dog(const Dog &dog);

		Dog &operator=(const Dog &dog);

		void	makeSound(void) const;
		void	printIdea(int i) const;
};

#endif
