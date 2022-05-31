/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:52:27 by artmende          #+#    #+#             */
/*   Updated: 2022/05/31 16:54:53 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <vector>
#include <array>

#include "vector.hpp"

#include "ClapTrap.hpp"
#include "Array.hpp"


int	main()
{



//	ClapTrap	b("Coucou");

	std::vector<ClapTrap>	v;

	ft::vector<int>	vi;


	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "Capacity : " << v.capacity() << " | Size : " << v.size() << std::endl;
		v.push_back(ClapTrap());
	}

/*
	v.resize(10, b);
	v.resize(5);
	v.resize(10);

//	system("leaks a.out");
	
	int	a;
	std::cin >> a;

	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	*/

	return 0;
}
