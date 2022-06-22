/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/22 11:30:31 by artmende         ###   ########.fr       */
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


/*	std::list<ClapTrap>	l;
	for (size_t i = 0; i < 10; i++)
	{
		l.push_back(std::to_string(i));
	}
	ft::vector<ClapTrap>	v(l.begin(), l.end());

	std::cout << "BEFORE ERASING '" << *(v.begin() + 5) << "'" << std::endl;
	ft::vector<ClapTrap>::iterator	ittest = v.erase(v.begin() + 5);
	std::cout << "AFTER ERASING - pointing to '" << *ittest << "'" << std::endl;

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}*/


	std::vector<ClapTrap>	v;

	std::cout << v.begin().base() << std::endl;

	std::vector<ClapTrap>::iterator	it = v.erase(v.begin());

	std::cout << it.base() << std::endl;


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
