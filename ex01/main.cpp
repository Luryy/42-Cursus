#include <ScavTrap.hpp>

int main(void)
{
	ScavTrap scav;
	ScavTrap scavNamedLury("Lury");
	ScavTrap scavNamedZombie("Zombie");
	ScavTrap scavAssingned(scavNamedZombie);
	scav.attack("Any");
	scav = scavNamedLury;

	scavAssingned.beRepaired(20);
	for (int i = 0; i <= 5; i++)
	{
		scav.attack("Zombie");
		scavAssingned.takeDamage(20);
	}
	scav.guardGate();
	scavAssingned.beRepaired(20);
	for (int i = 0; i < 45; i++)
		scav.beRepaired(i);
	scav.attack("Zombie");

	return 0;
}
