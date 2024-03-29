#ifndef FT_ENABLE_IF_HPP
#define FT_ENABLE_IF_HPP

namespace ft {

	template <bool, class>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

#endif
