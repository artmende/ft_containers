/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/15 16:53:48 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "vector.hpp"

/*#define ft std*/

int	main()
{
	ft::vector<int>	g;
	for (size_t i = 0; i < 10; i++)
	{
		g.push_back(i);
	}
	

	ft::vector<int>::/*const_*/reverse_iterator	ritb = g.rbegin();
	ft::vector<int>::const_reverse_iterator	rite = g.rend();
	ft::vector<int>::const_iterator			itb = g.begin();
	ft::vector<int>::const_iterator			ite = g.end();

	for (; ritb != rite; ++ritb)
	{
		std::cout << *ritb << std::endl;
		*ritb += 5;
	}
	std::cout << std::endl;

	while (itb < ite)
	{
		std::cout << *itb << std::endl;
		itb++;
	}

	std::cout << "ritb: " << *ritb << std::endl;
	std::cout << "itb: " << *itb << std::endl;




	return (0);
}
