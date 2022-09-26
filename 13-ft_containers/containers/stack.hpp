#ifndef STACK_HPP
#define STACK_HPP

#include <vector.hpp>

namespace ft {
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type value_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;
			typedef typename Container::size_type size_type;
			typedef Container container_type;

		protected:
			container_type c;

		public:
			explicit stack(const container_type &cont = container_type()) : c(cont) {};

			~stack(void) {};

			bool empty(void) const { return c.empty(); };
			size_type size(void) const { return c.size(); };
			reference top(void) { return c.back(); };
			const_reference top(void) const { return c.back(); };
			void push(const value_type& x) { c.push_back(x); };
			void pop(void) { c.pop_back(); };

			template <typename T1, typename C1>
			friend bool operator==(const stack<T1, C1>&, const stack<T1, C1>&);

			template <typename T1, typename C1>
			friend bool operator<(const stack<T1, C1>&, const stack<T1, C1>&);
	};

	template <typename T, typename Container>
	inline bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return (x.c == y.c); };

	template <typename T, typename Container>
	inline bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return (!(x == y)); };

	template <typename T, typename Container>
	inline bool operator<(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return (x.c < y.c); }

	template <typename T, typename Container>
	inline bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return (!(y < x)); };

	template <typename T, typename Container>
	inline bool operator>(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return (y < x); };

	template <typename T, typename Container>
	inline bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
	{ return (!(x < y)); };
}

#endif
