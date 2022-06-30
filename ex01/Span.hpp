#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <limits>

class Span
{
	private:
		unsigned int		max;
		std::vector<int>	content;

	public:
		Span(void);
		Span(const unsigned int N);
		Span(const Span &span);
		virtual ~Span(void);

		Span	&operator=(const Span &span);

		void	addNumber(const int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	fill(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif
