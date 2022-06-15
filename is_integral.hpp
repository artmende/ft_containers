/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:37:14 by artmende          #+#    #+#             */
/*   Updated: 2022/06/15 19:56:55 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include <type_traits>

namespace ft
{

	// this section is inspired by the source code of std::is_integral

	typedef	std::integral_constant<bool, true>	true_type;
	typedef	std::integral_constant<bool, false>	false_type;

	template <typename T>	struct is_integral							: public false_type {};

	template <typename T>	struct is_integral<const T>					: public is_integral<T> {};
	template <typename T>	struct is_integral<volatile T>				: public is_integral<T> {};
	template <typename T>	struct is_integral<volatile const T>		: public is_integral<T> {};

	template <>				struct is_integral<bool>					: public true_type {};
	template <>				struct is_integral<char>					: public true_type {};
	template <>				struct is_integral<char16_t>				: public true_type {};
	template <>				struct is_integral<char32_t>				: public true_type {};
	template <>				struct is_integral<wchar_t>					: public true_type {};
	template <>				struct is_integral<signed char>				: public true_type {};
	template <>				struct is_integral<short int>				: public true_type {};
	template <>				struct is_integral<int>						: public true_type {};
	template <>				struct is_integral<long int>				: public true_type {};
	template <>				struct is_integral<long long int>			: public true_type {};
	template <>				struct is_integral<unsigned char>			: public true_type {};
	template <>				struct is_integral<unsigned short int>		: public true_type {};
	template <>				struct is_integral<unsigned int>			: public true_type {};
	template <>				struct is_integral<unsigned long int>		: public true_type {};
	template <>				struct is_integral<unsigned long long int>	: public true_type {};

	/*
	fundamental integral types
	bool
	char
	char16_t
	char32_t
	wchar_t
	signed char
	short int
	int
	long int
	long long int
	unsigned char
	unsigned short int
	unsigned int
	unsigned long int
	unsigned long long int
	*/
}

#endif
