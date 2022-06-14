/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/14 18:14:38 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

int	main()
{
	std::vector<int>	g;
	for (size_t i = 0; i < 10; i++)
	{
		g.push_back(i);
	}
	

	std::vector<int>::const_reverse_iterator	ritb = g.rbegin();
	std::vector<int>::const_reverse_iterator	rite = g.rend();
	std::vector<int>::const_iterator			itb = g.begin();
	std::vector<int>::const_iterator			ite = g.end();

	for (size_t i = 0; i < g.size(); i++)
	{
		std::cout << g[i] << std::endl;
	}
	std::cout << std::endl;
	

	std::cout << "ritb: " << *ritb << std::endl;
	std::cout << "itb: " << *itb << std::endl;


	return (0);
}
