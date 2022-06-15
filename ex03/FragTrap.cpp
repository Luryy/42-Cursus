#include <FragTrap.hpp>

FragTrap::FragTrap(void) : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &fragTrap)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &fragTrap) {
		this->name = fragTrap.name;
		this->hitPoints = fragTrap.hitPoints;
		this->energyPoints = fragTrap.energyPoints;
		this->attackDamage = fragTrap.attackDamage;
	}
	return *this;
}

void	FragTrap::attack(const std::string &target)
{

	if (this->energyPoints <= 0) {
		std::cout << "FragTrap " << this->name << " without enought energyPoints to attack" << std::endl;
		return ;
	}
	if (this->hitPoints <= 0) {
		std::cout << "FragTrap " << this->name << " is dead" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " <<
	this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " high five guys!" << std::endl;
}
