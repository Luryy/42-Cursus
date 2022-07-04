#include <AMateria.hpp>

AMateria::AMateria(void) : type("unknown materia") {}

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria &aMateria)
{
	*this = aMateria;
}

AMateria::~AMateria() {}

AMateria	&AMateria::operator=(const AMateria &aMateria)
{
	if (this != &aMateria)
		type = aMateria.type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "unkown usage of this materia" << target.getName() << std::endl;
}
