#include <Character.hpp>

Character::Character(void) : name("any character")
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}


Character::Character(const std::string &name) : name(name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &character)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = character;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}

Character	&Character::operator=(const Character &character)
{
	std::cout << "Character copy assingment called" << std::endl;
	if (this != &character)
	{
		name = character.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (character.inventory[i])
				inventory[i] = character.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return (*this);
}

const std::string	&Character::getName(void) const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << name << " equiping " << m->getType() << " materia at slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "can't equip materia " <<  m->getType() << " - inventory is full" << std::endl;
	std::cout << "Deleting " << m->getType() << " materia" << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		std::cout << name << " unequiping " << inventory[idx]->getType() << " materia from slot " << idx << std::endl;
		inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		inventory[idx]->use(target);
		return ;
	}
	std::cout << name << " doing nothing" << std::endl;
}
