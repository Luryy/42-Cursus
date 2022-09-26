#ifndef MAP_HPP
#define MAP_HPP

#include <functions.hpp>
#include <rb_tree.hpp>
#include <utils.hpp>

namespace ft {
	template<	class Key,
				class T,
				class Compare = ft::less<Key>,
				class Alloc = std::allocator<ft::pair<const Key, T> >
			>
	class map {
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef size_t size_type;

		class value_compare {
			friend class map<Key, T, Compare, Alloc>;

			protected:
				Compare _key_comp;

			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;

				explicit value_compare(key_compare c = key_compare()) : _key_comp(c) {}

				bool operator()(const value_type& x, const value_type& y) const {
					return _key_comp(x.first, y.first);
				}
		};

		private:
			typedef rb_tree<value_type, value_compare> rb_tree_type;
			rb_tree_type _rb_tree;
			key_compare _key_comp;
			allocator_type _alloc;

		public:
			typedef typename rb_tree_type::iterator iterator;
			typedef typename rb_tree_type::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type difference_type;

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _rb_tree(value_compare(comp)), _key_comp(comp), _alloc(alloc) {};

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _rb_tree(value_compare(comp)), _key_comp(comp), _alloc(alloc)
			{
				for (; first != last; first++)
					insert(*first);
			};

			map(const map& x) { *this = x; };

			~map(void) {};

			map& operator=(const map& src)
			{
				if (this != &src)
				{
					clear();
					_key_comp = src._key_comp;
					_alloc = src._alloc;
					_rb_tree = src._rb_tree;
				}
				return *this;
			};

			iterator begin() { return _rb_tree.begin(); };
			const_iterator begin() const { return _rb_tree.begin(); };

			iterator end() { return _rb_tree.end(); };
			const_iterator end() const { return _rb_tree.end(); };

			reverse_iterator rbegin() { return reverse_iterator(end()); };
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };

			reverse_iterator rend() { return reverse_iterator(begin()); };
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };

			mapped_type& operator[](const key_type& k) {
				pair<iterator, bool> inserted_pair = (insert(ft::make_pair(k, mapped_type())));
				return (inserted_pair.first)->second;
			}


			bool empty() const { return (_rb_tree.empty()); }
			size_type size() const { return (_rb_tree.size()); }
			size_type max_size() const { return (_rb_tree.max_size()); }

			pair<iterator, bool> insert(const value_type& val) { return (_rb_tree.insert(val));	}

			iterator insert(iterator position, const value_type& val)
			{
				return (_rb_tree.insert(val, position.base()).first);
			}

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(*first++);
			}

			void erase(iterator position) { _rb_tree.remove(*position); }

			size_type erase(const key_type& k)
			{
				return _rb_tree.remove(value_type(k, mapped_type()));
			}

			void erase(iterator first, iterator last)
			{
				iterator tmp;
				while (first != last)
				{
					tmp = first;
					first++;
					_rb_tree.remove(*tmp);
				}
			}

			void swap(map& x)
			{
				_rb_tree.swap(x._rb_tree);

				key_compare tmp_key_comp = x._key_comp;
				allocator_type tmp_alloc = x._alloc;

				x._key_comp = _key_comp;
				x._alloc = _alloc;

				_key_comp = tmp_key_comp;
				_alloc = tmp_alloc;
			}

			void clear() { _rb_tree.clear(); }

			key_compare key_comp() const { return _key_comp; }

			value_compare value_comp() const { return value_compare(_rb_tree.key_comp()); }

			iterator find(const key_type& k) { return iterator(_rb_tree.search(value_type(k, mapped_type()))); }

			const_iterator find(const key_type& k) const { return const_iterator(_rb_tree.search(value_type(k, mapped_type()))); }

			size_type count(const key_type& k) const
			{
				const_iterator it = find(k);
				if (it != end())
					return (1);
				return (0);
			}

			iterator lower_bound(const key_type& k)
			{
				return _rb_tree.lower_bound(value_type(k, mapped_type()));

			}

			const_iterator lower_bound(const key_type& k) const
			{
				return _rb_tree.lower_bound(value_type(k, mapped_type()));

			}

			iterator upper_bound(const key_type& k)
			{
				return _rb_tree.upper_bound(value_type(k, mapped_type()));
			}

			const_iterator upper_bound(const key_type& k) const
			{
				return _rb_tree.upper_bound(value_type(k, mapped_type()));
			}

			pair<iterator, iterator> equal_range(const key_type& k) { return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			pair<const_iterator, const_iterator> equal_range(const key_type& k) const { return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			allocator_type get_allocator() const { return _alloc; }
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs > lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

}

#endif
