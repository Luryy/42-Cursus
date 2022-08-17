#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP

#include <iterator_traits.hpp>

namespace ft {

	template <class Iterator>
	class reverse_iterator {
		public:
			typedef Iterator iterator_type;
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::iterator_category iterator_category;

			reverse_iterator(void) {}
			explicit reverse_iterator(iterator_type it) : _it(it) {}
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &rev_it) : _it(rev_it.base()) {}
			~reverse_iterator() {}

			iterator_type base() const { return _it; }

			typename reverse_iterator::reference operator[](typename reverse_iterator::difference_type index) const
			{
				return (base()[-index - 1]);
			}

			reverse_iterator &operator++()
			{
				--_it;
				return *this;
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--_it;
				return tmp;
			}

			reverse_iterator &operator--()
			{
				++_it;
				return *this;
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++_it;
				return tmp;
			}

			reference operator*() const
			{
				iterator_type tmp = _it;
				return (*--tmp);
			}
			pointer operator->() const { return &(operator*()); }

			reverse_iterator &operator-=(typename reverse_iterator<Iterator>::difference_type amount)
			{
				this->_it += amount;
				return *this;
			}

			reverse_iterator &operator+=(typename reverse_iterator::difference_type amount)
			{
				this->_it -= amount;
				return *this;
			}

			reverse_iterator operator-(difference_type n) const
			{
				reverse_iterator tmp = *this;
				tmp._it += n;
				return tmp;
			}

			reverse_iterator operator+(difference_type n) const
			{
				reverse_iterator tmp = *this;
				tmp._it -= n;
				return tmp;
			}

		protected:
			iterator_type _it;
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return rev_it + n;
	}

	template <typename Iterator1, typename Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(
		const reverse_iterator<Iterator1> lhs, const reverse_iterator<Iterator2> rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &rhs, const reverse_iterator<Iterator2> &lhs)
	{
		return (rhs.base() != lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &rhs, const reverse_iterator<Iterator2> &lhs)
	{
		return (rhs.base() == lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &rhs, const reverse_iterator<Iterator2> &lhs)
	{
		return (rhs.base() < lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &rhs, const reverse_iterator<Iterator2> &lhs)
	{
		return (rhs.base() > lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &rhs, const reverse_iterator<Iterator2> &lhs)
	{
		return (rhs.base() <= lhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &rhs, const reverse_iterator<Iterator2> &lhs)
	{
		return (rhs.base() >= lhs.base());
	}

}

#endif
