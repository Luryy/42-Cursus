#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <ClapTrap.hpp>

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap);
		FragTrap& operator=(FragTrap const &fragTrap);
		~FragTrap(void);

		void	highFivesGuys(void);
		void	attack(std::string const &target);
};

#endif
