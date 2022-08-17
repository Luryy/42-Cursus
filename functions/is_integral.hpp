#ifndef FT_IS_INTEGRAL_HPP
#define FT_IS_INTEGRAL_HPP

namespace ft {
	struct false_type {
		static const bool value = false;
		bool value_type;
	};

	struct true_type {
		static const bool value = true;
		bool value_type;
	};

	template <typename>
	struct is_integral : false_type {};

	template <>
	struct is_integral<bool> : true_type {};

	template <>
	struct is_integral<char> : true_type {};

	template <>
	struct is_integral<wchar_t> : true_type {};

	template <>
	struct is_integral<signed char> : true_type {};

	template <>
	struct is_integral<short int> : true_type {};

	template <>
	struct is_integral<int> : true_type {};

	template <>
	struct is_integral<long int> : true_type {};

	template <>
	struct is_integral<long long int> : true_type {};

	template <>
	struct is_integral<unsigned char> : true_type {};

	template <>
	struct is_integral<unsigned short int> : true_type {};

	template <>
	struct is_integral<unsigned int> : true_type {};

	template <>
	struct is_integral<unsigned long int> : true_type {};

	template <>
	struct is_integral<unsigned long long int> : true_type {};
}

#endif
