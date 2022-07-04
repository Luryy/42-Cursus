#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <IMateriaSource.hpp>

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria			*inventory[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &materiaSource);
		virtual ~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &materiaSource);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(const std::string &type);
};

#endif
