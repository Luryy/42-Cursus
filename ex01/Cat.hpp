#ifndef CAT_HPP
# define CAT_HPP

#include <Animal.hpp>
#include <Brain.hpp>
#include <iostream>

class Cat : public Animal
{
	private:
		Brain* brain;

	public:
		Cat(void);
		virtual ~Cat(void);
		Cat(std::string type);
		Cat(const Cat &cat);

		Cat &operator=(const Cat &cat);

		void	makeSound(void) const;
		void	printIdea(int i) const;

};

#endif
