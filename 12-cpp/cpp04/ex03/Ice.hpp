#ifndef ICE_HPP
# define ICE_HPP

#include <AMateria.hpp>

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &ice);
		virtual ~Ice();

		Ice	&operator=(const Ice &ice);

		Ice		*clone() const;
		void	use(ICharacter &target);
};

#endif
