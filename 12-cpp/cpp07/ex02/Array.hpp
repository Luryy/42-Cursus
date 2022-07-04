#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T> class Array
{
	private:
		T				*data;
		unsigned int	_size;

	public:
		Array(void) : data(NULL), _size(0) {}
		Array(const unsigned int n) : data(new T[n]), _size(n) {}
		Array(const Array<T> &array) : data(NULL), _size(0) { *this = array; }
		virtual ~Array() { delete [] data; }

		Array<T>	&operator=(const Array<T> &array)
		{
			if (this != &array)
			{
				delete [] data;
				_size = array._size;
				data = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					data[i] = array.data[i];
			}
			return (*this);
		}

		T	&operator[](const int index) const
		{
			if (index < 0 || static_cast<unsigned int>(index) >= _size)
				throw std::exception();
			return data[index];
		}

		unsigned int	size(void) const { return _size; }
};


#endif
