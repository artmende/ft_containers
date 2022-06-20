/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/20 02:42:10 by artmende         ###   ########.fr       */
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

	ft::vector<int>	v;
	ft::vector<int>::iterator	it;

	std::cout << "iserting... : " << *(it = v.insert(v.begin(), 8)) << " : " << it - v.begin() << std::endl;

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
	

	//std::cout << "About to insert..." << std::endl;

	//a.insert(a.end() - 2, ClapTrap("coucou"));

	//std::cout << "Insert is done\n";

	//std::cout << "capacity : " << a.capacity() << std::endl;

	return (0);
}
