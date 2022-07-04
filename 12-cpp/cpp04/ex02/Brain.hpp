#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <cstdlib>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &brain);

		Brain &operator=(const Brain &brain);
		std::string getIdea(int i) const;
};

#endif
