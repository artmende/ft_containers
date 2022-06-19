/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/19 18:36:33 by artmende         ###   ########.fr       */
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

	v.insert(v.begin(), 8);


	std::cout << "capacity : " << v.capacity() << std::endl;

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
