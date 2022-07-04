#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <ICharacter.hpp>

class ICharacter;

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &aMateria);
		virtual ~AMateria();

		AMateria	&operator=(const AMateria &aMateria);

		std::string const	&getType() const;

		virtual	AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif
