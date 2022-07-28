/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_delete_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:25:58 by artmende          #+#    #+#             */
/*   Updated: 2022/07/28 16:59:17 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include "map.hpp"
#include "vector.hpp"



int	main()
{
	ft::vector<int>	v;
	v.push_back(5);
	v.push_back(7);
	v.push_back(-3);

	ft::vector<int>	copy(v);

	ft::vector_random_access_iterator<int>	it(&(v[0]));
	ft::vector_random_access_iterator<const int>	cit/*(it)*/;

	cit = it;



	std::cout << *it << std::endl;
//	*it = 3;

	std::cout << copy[0] << std::endl;

	return 0;
}
