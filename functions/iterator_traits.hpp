#ifndef FT_ITERATOR_TRAITS_HPP
#define FT_ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft {
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T *, class Reference = T &>
	struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::difference_type difference_type;
	};

	template <class T>
	struct iterator_traits<T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T *> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template <class Iterator>
	typename iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last)
	{
		size_t size = 0;

		while (first++ != last)
			size++;
		return (size);
	}

	template <class Iterator, class Distance>
	void advance(Iterator &it, Distance n)
	{
		it += n;
	}

	template <class Iterator>
	class random_access_iterator
	{
		public:
			typedef typename iterator<ft::random_access_iterator_tag, Iterator>::value_type value_type;
			typedef typename iterator<ft::random_access_iterator_tag, Iterator>::pointer pointer;
			typedef typename iterator<ft::random_access_iterator_tag, Iterator>::reference reference;
			typedef typename iterator<ft::random_access_iterator_tag, Iterator>::difference_type difference_type;
			typedef typename iterator<ft::random_access_iterator_tag, Iterator>::iterator_category iterator_category;

		random_access_iterator(void) {}
		explicit random_access_iterator(pointer const it) : _it(it) {}
		random_access_iterator(const random_access_iterator &src) : _it(src._it) {}
		template <typename Iter>
		random_access_iterator(const random_access_iterator<Iter>& it) : _it(it.base()) {}
		~random_access_iterator() {}

		pointer base() const { return _it; }

		reference operator*() const { return *_it; }

		pointer operator->() const { return _it; }

		reference operator[](difference_type index) const { return (_it[index]); }

		random_access_iterator &operator=(const random_access_iterator &rhs)
		{
			if (this != &rhs)
				_it = rhs.base();
			return *this;
		}

		random_access_iterator &operator++()
		{
			_it++;
			return *this;
		}

		random_access_iterator operator++(int) {
			random_access_iterator tmp = *this;
			operator++();
			return tmp;
		}

		random_access_iterator &operator--() {
			_it--;
			return *this;
		}

		random_access_iterator operator--(int) {
			random_access_iterator tmp = *this;
			operator--();
			return tmp;
		}

		random_access_iterator &operator-=(const difference_type n) {
			_it -= n;
			return (*this);
		}

		random_access_iterator &operator+=(const difference_type n) {
			_it += n;
			return (*this);
		}

		random_access_iterator operator-(const difference_type n) {
			return (random_access_iterator(_it - n));
		}

		random_access_iterator operator+(const difference_type n) {
			return (random_access_iterator(_it + n));
		}

		difference_type operator-(const random_access_iterator &rhs) {
			return (_it - rhs._it);
		}

		difference_type operator+(const random_access_iterator &rhs) {
			return (_it + rhs._it);
		}

		bool operator>(random_access_iterator const &rhs) const {
			return (_it > rhs._it);
		}

		bool operator>=(random_access_iterator const &rhs) const {
			return (_it >= rhs._it);
		}

		bool operator<(random_access_iterator const &rhs) const {
			return (_it < rhs._it);
		}

		bool operator<=(random_access_iterator const &rhs) const {
			return (_it <= rhs._it);
		}

		protected:
			pointer _it;
	};

	template <class Iterator>
	random_access_iterator<Iterator> operator+(
		typename random_access_iterator<Iterator>::difference_type n, random_access_iterator<Iterator> &it)
	{
		return (it + n);
	}

	template <class Iterator1, class Iterator2>
	typename random_access_iterator<Iterator1>::difference_type operator-(
		random_access_iterator<Iterator1> lsh, random_access_iterator<Iterator2> rsh)
	{
		return (lsh.base() - rsh.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const random_access_iterator<Iterator1> &rhs, const random_access_iterator<Iterator2> &lhs)
	{
		return (rhs.base() != lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator==(const random_access_iterator<Iterator1> &rhs, const random_access_iterator<Iterator2> &lhs)
	{
		return (rhs.base() == lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const random_access_iterator<Iterator1> &rhs, const random_access_iterator<Iterator2> &lhs)
	{
		return (rhs.base() > lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const random_access_iterator<Iterator1> &rhs, const random_access_iterator<Iterator2> &lhs)
	{
		return (rhs.base() < lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const random_access_iterator<Iterator1> &rhs, const random_access_iterator<Iterator2> &lhs)
	{
		return (rhs.base() >= lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const random_access_iterator<Iterator1> &rhs, const random_access_iterator<Iterator2> &lhs)
	{
		return (rhs.base() <= lhs.base());
	}

}

#endif
