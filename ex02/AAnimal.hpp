#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(std::string type);
		AAnimal(const AAnimal &animal);

		AAnimal &operator=(const AAnimal &animal);

	std::string		getType(void) const;
	virtual void	makeSound(void) const = 0;

};

#endif
