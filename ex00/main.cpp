#include <Zombie.hpp>

int	main(void)
{
	Zombie	*rick = new Zombie("Rick");
	Zombie	*morty = newZombie("Morty");
	Zombie	bart("Bart");
	Zombie	unamed;

	randomChump("Chump");
	unamed.announce();
	bart.announce();
	rick->announce();
	morty->announce();
	delete morty;
	delete rick;
}
