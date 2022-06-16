#ifndef CAT_HPP
# define CAT_HPP

#include <AAnimal.hpp>
#include <Brain.hpp>
#include <iostream>

class Cat : public AAnimal
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
