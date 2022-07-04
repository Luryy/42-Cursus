#include <ScavTrap.hpp>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scavTrap)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &scavTrap) {
		this->name = scavTrap.name;
		this->hitPoints = scavTrap.hitPoints;
		this->energyPoints = scavTrap.energyPoints;
		this->attackDamage = scavTrap.attackDamage;
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{

	if (this->energyPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " without enought energyPoints to attack" << std::endl;
		return ;
	}
	if (this->hitPoints <= 0) {
		std::cout << "ScavTrap " << this->name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " <<
	this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}
