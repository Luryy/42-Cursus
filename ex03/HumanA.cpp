#include <HumanA.hpp>

HumanA::HumanA(std::string name, Weapon &type) : name(name), type(type) {}

HumanA::~HumanA() {}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->type.getType() << std::endl;
}
