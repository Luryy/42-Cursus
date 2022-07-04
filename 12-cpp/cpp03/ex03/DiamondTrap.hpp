#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <FragTrap.hpp>
# include <ScavTrap.hpp>

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &diamondTrap);
		DiamondTrap& operator=(DiamondTrap const &diamondTrap);
		~DiamondTrap(void);

		using	ScavTrap::attack;
		void	whoAmI(void);
};

#endif
