#include <ClapTrap.hpp>

ClapTrap::ClapTrap(void) : name("Clap Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap)
{

	std::cout << "Copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &clapTrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clapTrap) {
		this->name = clapTrap.name;
		this->hitPoints = clapTrap.hitPoints;
		this->energyPoints = clapTrap.energyPoints;
		this->attackDamage = clapTrap.attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{

	if (this->energyPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " without enought energyPoints to attack" << std::endl;
		return ;
	}
	if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " <<
	this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{

	std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
	this->hitPoints = this->hitPoints - amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{

	if (this->energyPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " without enought energyPoints to repair" << std::endl;
		return ;
	}
	if (this->hitPoints <= 0) {
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " repaired " << amount << " of hit points" << std::endl;
	this->hitPoints = this->hitPoints + amount;
	this->energyPoints--;
}
