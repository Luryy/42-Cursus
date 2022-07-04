#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &wrongAnimal);

		WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

	std::string		getType(void) const;
	void	makeSound(void) const;

};

#endif
