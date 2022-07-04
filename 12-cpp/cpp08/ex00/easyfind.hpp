#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T> void easyfind(T &t, int i)
{
	typename T::iterator iter;

	iter = std::find(t.begin(), t.end(), i);
	if (iter == t.end())
		throw std::exception();
}

#endif
