#ifndef RB_TREE_ITERATOR_HPP
#define RB_TREE_ITERATOR_HPP

#include <functions.hpp>
#include <rb_tree_node.hpp>

namespace ft {
	template <class T>
	class rb_tree_iterator : public iterator<ft::bidirectional_iterator_tag, T> {
		public:
			typedef T iterator_type;
			typedef typename iterator_traits<T>::value_type value_type;
			typedef typename iterator_traits<T>::difference_type difference_type;
			typedef typename iterator_traits<T>::pointer pointer;
			typedef typename iterator_traits<T>::reference reference;

			typedef Rb_tree_node<value_type>* node_ptr;
			typedef const Rb_tree_node<value_type>* const_node_ptr;

		private:
			node_ptr _node;

		public:
			rb_tree_iterator(void) : _node(NULL) {}
			rb_tree_iterator(node_ptr node) : _node(node) {}
			template <typename It>
			rb_tree_iterator(const rb_tree_iterator<It> &src) : _node(src.base()) {}
			~rb_tree_iterator(void) {}

			node_ptr base() const { return _node; }

			reference operator*() const { return _node->data; }

			pointer operator->() const { return &(operator*()); }

			rb_tree_iterator &operator++()
			{
				_node = sucessor(_node);
				return *this;
			}

			rb_tree_iterator operator++(int)
			{
				rb_tree_iterator _tmp = *this;
				operator++();
				return _tmp;
			}

			rb_tree_iterator &operator--()
			{
				_node = predecessor(_node);
				return *this;
			}

			rb_tree_iterator operator--(int)
			{
				rb_tree_iterator _tmp = *this;
				operator--();
				return _tmp;
			}
	};

	template <class It1, class It2>
	bool operator==(const rb_tree_iterator<It1> &it1, const rb_tree_iterator<It2> &it2)
	{
		return (it1.base() == it2.base());
	}

	template <class It1, class It2>
	bool operator!=(const rb_tree_iterator<It1> &it1, const rb_tree_iterator<It2> &it2)
	{
		return (it1.base() != it2.base());
	}

	template <typename Iterator>
	bool operator==(const rb_tree_iterator<Iterator>& lhs, const rb_tree_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename Iterator>
	bool operator!=(const rb_tree_iterator<Iterator>& lhs, const rb_tree_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
}

#endif
