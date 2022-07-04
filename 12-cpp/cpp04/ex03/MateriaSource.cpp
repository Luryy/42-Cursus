#include <MateriaSource.hpp>

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &materiaSource)
{
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (materiaSource.inventory[i])
				inventory[i] = materiaSource.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			std::cout << "MateriaSource learning " << m->getType() << std::endl;
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "MateriaSource have a full inventory" << std::endl;
	std::cout << "Deleting " << m->getType() << " materia" << std::endl;
	delete m;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL && inventory[i]->getType() == type)
			return (inventory[i]->clone());
	}
	std::cout << "MateriaSource can't create " << type << " materia (not learned)" << std::endl;
	return (NULL);
}
