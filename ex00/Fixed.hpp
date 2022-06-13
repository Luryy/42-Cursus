#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractional = 8;

	public:
		Fixed(void);
		Fixed(Fixed const &fixed);
		~Fixed(void);

		Fixed &operator=(Fixed const &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};



#endif
