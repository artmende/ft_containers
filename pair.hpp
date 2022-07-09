/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:22:33 by artmende          #+#    #+#             */
/*   Updated: 2022/07/09 15:37:28 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
	template <class T1, class T2> struct pair
	{
		typedef	T1	first_type;
		typedef	T2	second_type;

		pair() {}

		template<class U1, class U2>
		pair(const pair<U1, U2>& pr) : first(pr.first), second(pr.second)
		{}

		pair(const first_type& a, const second_type& b) : first(a), second(b)
		{}

		pair&	operator=(const pair& pr)
		{
			if (&pr != this)
			{
				this->first = pr.first;
				this->second = pr.second;
			}
			return (*this);
		}

		T1	first;
		T2	second;
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}

# endif
