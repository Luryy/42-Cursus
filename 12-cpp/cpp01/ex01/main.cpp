#include <Zombie.hpp>

int	main(void)
{
	int		n = 4;
	Zombie	*horde = zombieHorde(n, "Lury");

	while (n--)
		horde[n].announce();
	delete [] horde;
}
