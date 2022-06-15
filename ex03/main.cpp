#include <DiamondTrap.hpp>

int main(void)
{
	DiamondTrap diamond;
	DiamondTrap diamondNamedLury("Lury");
	DiamondTrap diamondNamedZombie("Zombie");
	DiamondTrap diamondAssingned(diamondNamedZombie);
	diamond = diamondNamedLury;

	diamondAssingned.guardGate();
	diamond.highFivesGuys();
	diamondAssingned.attack("Alien");
	diamond.attack("Human");
	diamond.takeDamage(90);
	diamond.whoAmI();
	diamondAssingned.whoAmI();

	return 0;
}
