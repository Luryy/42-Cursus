#include <ScavTrap.hpp>
#include <FragTrap.hpp>

int main(void)
{
	FragTrap frag;
	FragTrap fragNamedLury("Lury");
	ScavTrap scavNamedZombie("Zombie");
	ScavTrap scavAssingned(scavNamedZombie);
	frag = fragNamedLury;

	scavAssingned.guardGate();
	frag.highFivesGuys();
	scavAssingned.attack("Alien");
	frag.attack("Human");
	frag.takeDamage(90);

	return 0;
}
