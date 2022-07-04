#include <iostream>
#include <Fixed.hpp>

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integer) : value(integer << fractional)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floater) : value(roundf(floater * (1 << fractional)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = src.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)value / (1 << fractional);
}

int	Fixed::toInt(void) const
{
	return value >> fractional;
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->value < fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->value <= fixed.getRawBits());
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->value > fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->value >= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->value == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->value != fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	++(this->value);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--(this->value);
	return (*this);
}

Fixed Fixed::operator++(int n)
{
	Fixed result(*this);

	if (n >= 0)
		for (int i = 0; i <= n; i++)
			operator++();
	else
		for (int i = 0; i <= -n; i++)
			operator--();
	return result;
}

Fixed Fixed::operator--(int n)
{
	Fixed result(*this);

	if (n >= 0)
		for (int i = 0; i <= n; i++)
			operator--();
	else
		for (int i = 0; i <= -n; i++)
			operator++();
	return result;
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 <= fixed2)
		return (fixed1);
	return (fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 <= fixed2)
		return (fixed1);
	return (fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 >= fixed2)
		return (fixed1);
	return (fixed2);
}

std::ostream	&operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}
