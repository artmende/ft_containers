/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/21 19:27:11 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "vector.hpp"
#include "ClapTrap.hpp"
#include <list>
#include <stdlib.h>

#define ft std

#define current b



int	main()
{

//	ft::vector<int>	v;
//	ft::vector<int>::iterator	it;


	std::list<ClapTrap>	l;
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(std::to_string(i));
	}
	ft::vector<ClapTrap>	v(l.begin(), l.end());
	v.reserve(100);

	std::list<ClapTrap>::iterator	itl = l.begin();
	for (size_t i = 0; i < 6; i++)
	{
		++itl;
	}
	

	std::cout << "BEFORE INSERTING\n";
	v.insert(v.begin() + 3, l.begin(), itl);
	std::cout << "AFTER INSERTING\n";

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	

/*	std::cout << "iserting... : " << *(it = v.insert(v.begin(), 8)) << " : " << it - v.begin() << std::endl;

	std::cout << "capacity : " << v.capacity() << " | begin : " << v.begin().base() << std::endl;

		std::cout << "iserting... : " << *(it = v.insert(v.begin()+1, 5)) << " : " << it - v.begin() << std::endl;

	std::cout << "capacity : " << v.capacity() << " | begin : " << v.begin().base() << std::endl;

	v.insert(v.begin(), 5, -8);

	std::cout << "capacity : " << v.capacity() << " | begin : " << v.begin().base() << std::endl;

		std::cout << "iserting... : " << *(it = v.insert(v.end() - 2, 80)) << " : " << it - v.begin() << std::endl;

	std::cout << "capacity : " << v.capacity() << " | begin : " << v.begin().base() << std::endl;

	v.insert(v.begin() + 5, 6, -4);

	std::cout << "capacity : " << v.capacity() << " | begin : " << v.begin().base() << std::endl;





	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	
*/


	return (0);
}
