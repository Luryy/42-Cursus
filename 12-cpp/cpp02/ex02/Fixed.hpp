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

		bool 	operator>(Fixed const &fixed) const;
		bool 	operator>=(Fixed const &fixed) const;
		bool 	operator<(Fixed const &fixed) const;
		bool 	operator<=(Fixed const &fixed) const;
		bool 	operator==(Fixed const &fixed) const;
		bool 	operator!=(Fixed const &fixed) const;

		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed	&min(Fixed &fixed1, Fixed &fixed2);
		static Fixed	&max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
		static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream	&operator<<(std::ostream &output, const Fixed &fixed);

#endif
