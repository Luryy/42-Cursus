#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <Weapon.hpp>

class HumanB
{
	public:
	HumanB(std::string name);
	~HumanB();

	void	setWeapon(Weapon &type);
	void	attack(void);

	private:
	std::string name;
	Weapon*		type;
};

#endif
