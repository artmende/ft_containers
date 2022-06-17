/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/17 18:00:28 by artmende         ###   ########.fr       */
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
	ft::vector<ClapTrap>	a(5);
	a.reserve(20);

	std::cout << "About to insert..." << std::endl;

	a.insert(a.end() - 2, ClapTrap("coucou"));

	std::cout << "Insert is done\n";

	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << std::endl;
	}
	

	return (0);
}
