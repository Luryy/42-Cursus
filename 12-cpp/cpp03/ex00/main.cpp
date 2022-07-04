#include <ClapTrap.hpp>

int main(void)
{
	ClapTrap clap;
	ClapTrap clapNamedLury("Lury");
	ClapTrap clapNamedZombie("Zombie");
	ClapTrap clapAssingned(clapNamedZombie);
	clap = clapNamedLury;

	clap.attack("Zombie");
	clapAssingned.takeDamage(0);
	clapAssingned.beRepaired(2);
	for (int i = 0; i < 10; i++)
		clap.beRepaired(i);
	clap.attack("Zombie");

	return 0;
}
