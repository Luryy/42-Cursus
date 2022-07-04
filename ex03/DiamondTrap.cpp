#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &diamondTrap)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &diamondTrap) {
		ClapTrap::name = diamondTrap.ClapTrap::name;
		this->name = diamondTrap.name;
		this->hitPoints = diamondTrap.hitPoints;
		this->energyPoints = diamondTrap.energyPoints;
		this->attackDamage = diamondTrap.attackDamage;
	}
	return *this;
}


void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name as DiamondTrap is " << this->name << std::endl;
	std::cout << "My name as ClapTrap is " << ClapTrap::name << std::endl;
}
