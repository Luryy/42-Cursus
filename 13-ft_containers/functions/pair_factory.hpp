#ifndef FT_PAIR_FACTORY_HPP
#define FT_PAIR_FACTORY_HPP

namespace ft {
	template <class T1, class T2>
	class pair {
		public:
			T1 first;
			T2 second;

			pair(void) : first(), second() {}

			pair(const T1 &a, const T2 &b) : first(a), second(b) {}

			template <class U, class V>
			pair(const pair<U, V> &src) : first(src.first), second(src.second) {}

			~pair() {}

			pair &operator=(const pair &src) {
				if (*this != src) {
					first = src.first;
					second = src.second;
				}
				return *this;
			}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }
}

#endif
