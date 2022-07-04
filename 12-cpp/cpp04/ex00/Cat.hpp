#ifndef CAT_HPP
# define CAT_HPP

#include <Animal.hpp>
#include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(std::string type);
		Cat(const Cat &cat);

		Cat &operator=(const Cat &cat);

		void	makeSound(void) const;
};

#endif
