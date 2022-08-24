#ifndef SET_HPP
#define SET_HPP

#include <functions.hpp>
#include <rb_tree.hpp>

namespace ft {

	template <class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:
			typedef T key_type;
			typedef T value_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef size_t size_type;

		private:
			typedef rb_tree<value_type, key_compare> rb_tree_type;
			rb_tree_type _rb_tree;
			key_compare _key_comp;
			allocator_type _alloc;

		public:
			typedef typename rb_tree_type::iterator iterator;
			typedef typename rb_tree_type::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type difference_type;

			explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _rb_tree(), _key_comp(comp), _alloc(alloc) {};

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _rb_tree(), _key_comp(comp), _alloc(alloc)
			{
				while (first != last) {
					insert(*first);
					++first;
				}
			};

			set(const set& x)  { *this = x; };

			~set(void) {};

			iterator begin() { return _rb_tree.begin(); };
			const_iterator begin() const { return _rb_tree.begin(); };

			iterator end() { return _rb_tree.end(); };
			const_iterator end() const { return _rb_tree.end(); };

			reverse_iterator rbegin() { return reverse_iterator(end()); };
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };

			reverse_iterator rend() { return reverse_iterator(begin()); };
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

			set& operator=(const set& x)
			{
				if (this != &x)
				{
					clear();
					_key_comp = x._key_comp;
					_alloc = x._alloc;
					_rb_tree = x._rb_tree;
				}
				return *this;
			};

			bool empty() const { return (_rb_tree.empty()); }
			size_type size() const { return (_rb_tree.size()); }
			size_type max_size() const { return (_rb_tree.max_size()); }

			ft::pair<iterator, bool> insert(const value_type& val) { return (_rb_tree.insert(val));	};

			iterator insert(iterator position, const value_type& val)
			{
				return (_rb_tree.insert(val, position.base()).first);
			};

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(*first++);
			};

			void erase(iterator position) { _rb_tree.remove(*position); };

			size_type erase(const value_type& val)
			{
				return _rb_tree.remove(val);
			};

			void erase(iterator first, iterator last)
			{
				iterator tmp;
				while (first != last)
				{
					tmp = first;
					first++;
					_rb_tree.remove(*tmp);
				}
			};

			void swap(set& x)
			{
				_rb_tree.swap(x._rb_tree);

				key_compare tmp_key_comp = x._key_comp;
				allocator_type tmp_alloc = x._alloc;

				x._key_comp = _key_comp;
				x._alloc = _alloc;

				_key_comp = tmp_key_comp;
				_alloc = tmp_alloc;
			};

			void clear(void) { _rb_tree.clear(); };

			key_compare key_comp(void) const { return _key_comp; };
			value_compare value_comp(void) const { return key_comp(); };

			iterator find(const value_type& val) const { return iterator(_rb_tree.search(val)); };

			size_type count(const value_type& val) const
			{
				const_iterator it = find(val);
				if (it != end())
					return (1);
				return (0);
			};

			iterator lower_bound(const value_type& val) const
			{
				iterator _ite = begin();
				while (_ite != end())
				{
					if (!_key_comp(*_ite, val))
						break;
					_ite++;
				}
				return _ite;
			};

			iterator upper_bound(const value_type& val) const
			{
				iterator _ite = begin();
				while (_ite != end())
				{
					if (_key_comp(val, *_ite))
						break;
					_ite++;
				}
				return _ite;
			};

			ft::pair<iterator, iterator> equal_range(const value_type& val) const
			{ return (ft::make_pair(lower_bound(val), upper_bound(val))); };

			allocator_type get_allocator(void) const { return _alloc; };
	};

	template <class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}


	template <class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		return !(rhs > lhs);
	}

	template <class Key, class Compare, class Alloc>
	void swap(ft::set<Key, Compare, Alloc>& lhs, ft::set<Key, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

}

#endif
