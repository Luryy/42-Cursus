/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:10:28 by lle-briq          #+#    #+#             */
/*   Updated: 2022/06/30 00:26:43 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : max(0) {}

Span::Span(const unsigned int N) : max(N) {}

Span::Span(const Span &span)
{
	*this = span;
}

Span::~Span()
{
	content.clear();
}

Span	&Span::operator=(const Span &span)
{
	if (this != &span)
	{
		this->content.clear();
		this->max = span.max;
		this->content = span.content;
	}
	return (*this);
}

void	Span::addNumber(const int n)
{
	if (content.size() >= max)
		throw std::exception();
	content.push_back(n);
}

int		Span::longestSpan(void) const
{
	if (content.size() <= 1)
		throw std::exception();

	std::vector<int>::const_iterator minSpan;
	minSpan = std::min_element(content.begin(), content.end());

	std::vector<int>::const_iterator maxSpan;
	maxSpan = std::max_element(content.begin(), content.end());

	return (*maxSpan - *minSpan);
}

int		Span::shortestSpan(void) const
{
	if (content.size()  <= 1)
		throw std::exception();

	std::vector<int> copySorted(max);

    std::partial_sort_copy(content.begin(), content.end(), copySorted.begin(), copySorted.end());

	int minSpan = copySorted[1] - copySorted[0];
	for (size_t i = 0; i + 1 < content.size(); i++)
		minSpan = std::min(minSpan, copySorted[i + 1] - copySorted[i]);
	return (minSpan);
}

void	Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator	it;

	it = begin;
	while (it != end)
	{
		addNumber(*it);
		it++;
	}
}
