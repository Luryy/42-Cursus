#include <Data.hpp>

Data::Data(void) : i(1) {}

Data::~Data(void) {}

Data::Data(const Data &data)
{
	*this = data;
}

Data	&Data::operator=(const Data &data)
{
	if (this != &data)
		this->i = data.i;
	return (*this);
}

int Data::getI(void) const
{
	return i;
}
