/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:52:27 by artmende          #+#    #+#             */
/*   Updated: 2022/06/01 11:43:56 by artmende         ###   ########.fr       */
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

/*	std::vector<ClapTrap>	v;

	ft::vector<int>	vi;


	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "Capacity : " << v.capacity() << " | Size : " << v.size() << std::endl;
		v.push_back(ClapTrap());
	}*/

/*
	std::allocator<ClapTrap>	al;

	ClapTrap	*ar = al.allocate(5);

	ClapTrap const & val = ClapTrap("yop");

	for (size_t i = 0; i < 5; i++)
	{
		al.construct(ar + i, val);
	}

	std::cout << ar[3] << std::endl;

*/



	ft::vector<ClapTrap>	v(20, ClapTrap("yop"));

	ClapTrap	*ar = (ClapTrap *)v.get();

	for (size_t i = 0; i < 20; i++)
	{
		std::cout << *(ar + i) << std::endl;
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
