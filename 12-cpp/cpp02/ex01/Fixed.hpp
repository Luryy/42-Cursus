#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int fractional = 8;

	public:
		Fixed(void);
		Fixed(int const integer);
		Fixed(float const floater);
		Fixed(Fixed const &fixed);
		~Fixed(void);

		Fixed &operator=(Fixed const &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &output, const Fixed &fixed);

#endif
