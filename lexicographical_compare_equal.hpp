/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare_equal.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:57:52 by artmende          #+#    #+#             */
/*   Updated: 2022/06/23 18:07:10 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_EQUAL
# define LEXICOGRAPHICAL_COMPARE_EQUAL

/*
	The following code is taken from :
	https://cplusplus.com/reference/algorithm/lexicographical_compare/
	https://cplusplus.com/reference/algorithm/equal/
*/

namespace ft
{

	//	lexicographical_compare returns true only if range1 < range2
	//	returns false in all other cases (range1 == range2 || range1 > range2)
	//	If both sequences compare equal until one of them ends, the shorter sequence is lexicographically less than the longer one.

	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
			return false;
			++first1; ++first2;
		}
		return true;
	}
}

#endif
