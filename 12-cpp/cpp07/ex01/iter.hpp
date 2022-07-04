#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T> void iter(const T *array, int length, void function(const T &))
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}

template<typename T> void	print(const T &data)
{
	std::cout << data << std::endl;
}

#endif
