/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_delete_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:25:58 by artmende          #+#    #+#             */
/*   Updated: 2022/07/29 17:07:46 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include "map.hpp"
#include "vector.hpp"
#include "ClapTrap.hpp"

template<typename T>
class test_template
{
	public:
	test_template() : t(T()) {}
	T	t;
	T &	display()
	{
		return t;
	}
};

template<typename T>
class test_it
{
	public:
	test_it(test_template<T>	*ptr)
	{
		std::cout << "inside contructor\n";
		(void)ptr;
	}
};

int	main()
{

	test_template<int>	tt;


	test_it<const int> t(&tt);

	return 0;
}
