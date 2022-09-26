#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <functions.hpp>

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef random_access_iterator<value_type> iterator;
			typedef random_access_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;

		private:
			allocator_type _alloc;
			size_type _size;
			size_type _capacity;
			pointer _array;

		public:
			explicit vector(const allocator_type & alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _array(NULL){};

			explicit vector(size_type n, const value_type& val = value_type(),
			const allocator_type & alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n), _array(_alloc.allocate(_capacity))
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_array + i, val);
			};

			template <class InputIterator>
			vector(InputIterator first,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
				const allocator_type & alloc = allocator_type())
			: _alloc(alloc), _size(static_cast<size_type>(ft::distance(first, last))), _capacity(_size), _array(_alloc.allocate(_capacity))
			{
				for (int i = 0; first != last; first++, i++)
					_alloc.construct (_array + i, *first);
			};

			vector(const vector& src): _size(0), _capacity(0), _array(NULL)
			{
				*this = src;
			};

			~vector(void)
			{
				if (_capacity > 0)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_array + i);
					_alloc.deallocate(_array, _capacity);
				}
			};

			vector& operator= (const vector& v)
			{
				if (this != &v)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_array + i);
					if (_capacity < v.size())
					{
						_alloc.deallocate(_array, _capacity);
						_array = _alloc.allocate(v._size);
						_capacity = v._size;
					}
					for (_size = 0; _size < v._size; _size++)
						_alloc.construct(_array + _size, v[_size]);
				}

				return (*this);
			};


			iterator begin() { return iterator(_array); };
			const_iterator begin() const { return const_iterator(_array); };

			iterator end() { return iterator(_array + _size); }
			const_iterator end() const { return const_iterator(_array + _size); };

			reverse_iterator rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };

			reverse_iterator rend() { return reverse_iterator(begin()); };
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

			size_type size() const { return _size; };
			size_type max_size() const { return _alloc.max_size(); };

			void resize(size_type n, value_type value = value_type())
			{
				if (n > _size)
					insert(end(), n - _size, value);
				else
					erase(begin() + n, end());
			};

			size_type capacity() const { return _capacity; };

			bool empty() const { return _size == 0; };

			void reserve(size_type n)
			{
				if (n >= _capacity && n > 0)
				{
					pointer tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(tmp + i, _array[i]);
						_alloc.destroy(&_array[i]);
					}
					_alloc.deallocate(_array, _capacity);
					_array = tmp;
					_capacity = n;
				}
			}

			reference operator[] (size_type n) { return _array[n]; };
			const_reference operator[] (size_type n) const { return const_reference(_array[n]); };

			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("vector");
				return _array[n];
			};

			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector");
				return const_reference(_array[n]);
			};

			reference front() { return _array[0]; };
			const_reference front() const { return const_reference(_array[0]); };

			reference back() { return _array[_size - 1]; };
			const_reference back() const { return const_reference(_array[_size - 1]); };

			void assign (size_type n, const value_type& val)
			{
				iterator it;
				clear();
				_alloc.deallocate(_array, _capacity);
				_size = n;
				if (_capacity < _size)
					_capacity = _size;
				_array = _alloc.allocate(_capacity);
				it = begin();
				iterator last = end();
				while (it < last)
				{
					_alloc.construct(&(*it), val);
					it++;
				}
			};

			template <class InputIterator>
			void assign(InputIterator first,
				typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
			{
				clear();
				size_type initial_capacity = _capacity;
				while (first != last)
				{
					push_back(*first);
					first++;
				}
				if (initial_capacity < _size)
					_capacity = _size;
			}

			void push_back(value_type const &val)
			{
				if (_capacity <= _size)
					_capacity <= 0 ? reserve(1) : reserve(_capacity *= 2);
				_alloc.construct(&(*end()), val);
				_size++;
			};

			void pop_back()
			{
				_alloc.destroy(&(*end()));
				_size--;
			};

			iterator insert(iterator position, value_type const &val)
			{
				int index = position - begin();
				insert(position, 1, val);
				return iterator(&(_array[index]));
			};

			void insert(iterator position, size_type n, value_type const &val)
			{
				if (n > 0) {
					int index = position - begin();
					if (_size + n > _capacity)
					{
						if (_size * 2 < _size + n)
							reserve(_size + n);
						else
							reserve(_size * 2);
					}

					for (int offset_index = _size - 1; offset_index >= index; offset_index--)
					{
						_alloc.construct(_array + offset_index + n, _array[offset_index]);
						_alloc.destroy(_array + offset_index);
					}

					int final_index = index + n;
					while (index < final_index)
					{
						_alloc.construct(_array + index, val);
						index++;
					}
					_size += n;
				}
			};

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_t n = ft::distance(first, last);

				if (n > 0)
				{
					int index = position - begin();
					if (_size + n > _capacity)
					{
						if (_capacity * 2 < _size + n)
							reserve(_size + n);
						else
							reserve(_size * 2);
					}

					for (int offset_index = _size - 1; offset_index >= index; offset_index--)
					{
						_alloc.construct(_array + offset_index + n, _array[offset_index]);
						_alloc.destroy(_array + offset_index);
					}

					int final_index = index + n;
					while (index < final_index)
					{
						_alloc.construct(_array + index, *first);
						index++;
						first++;
					}
					_size += n;
				}
			}

			iterator erase(iterator position)
			{
				_alloc.destroy(&(*position));
				for (iterator it = position; it != end(); it++)
				{
					_alloc.construct(&(*it), *(it + 1));
					_alloc.destroy(&(*(it + 1)));
				}
				_size--;
				return position;
			}

			iterator erase(iterator first, iterator last)
			{
				iterator it = first;
				while (it != last--)
					erase(it);
				return first;
			}

			void swap(vector &x)
			{
				size_type temp_size = _size;
				size_type temp_capacity = _capacity;
				pointer temp_array = _array;

				_size = x._size;
				x._size = temp_size;

				_capacity = x._capacity;
				x._capacity = temp_capacity;

				_array = x._array;
				x._array = temp_array;
			}

			void clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy (_array + i);
				_size = 0;
			}

			allocator_type get_allocator() const
			{
				return _alloc;
			}
	};

	template <class T, class Alloc>
	bool operator== (const vector<T, Alloc> lsh, const vector<T, Alloc> rsh)
	{ return ft::equal(lsh.begin(), lsh.end(), rsh.begin()) && lsh.size() == rsh.size(); };

	template <class T, class Alloc>
	bool operator!= (const vector<T, Alloc> lsh, const vector<T, Alloc> rsh)
	{ return !(lsh == rsh); };

	template <class T, class Alloc>
	bool operator< (const vector<T, Alloc> lsh, const vector<T, Alloc> rsh)
	{ return ft::lexicographical_compare(lsh.begin(), lsh.end(), rsh.begin(), rsh.end()); };

	template <class T, class Alloc>
	bool operator> (const vector<T, Alloc> lsh, const vector<T, Alloc> rsh)
	{ return rsh < lsh; };

	template <class T, class Alloc>
	bool operator <= (const vector<T, Alloc> lsh, const vector<T, Alloc> rsh)
	{ return !(lsh > rsh); };

	template <class T, class Alloc>
	bool operator >= (const vector<T, Alloc> lsh, const vector<T, Alloc> rsh)
	{ return !(lsh < rsh); };

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &a, vector<T, Alloc> &b)
	{ a.swap(b); };
}

#endif
