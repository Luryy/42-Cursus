#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <WrongAnimal.hpp>
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat &wrongCat);

		WrongCat &operator=(const WrongCat &wrongCat);

		void	makeSound(void) const;
};

#endif
