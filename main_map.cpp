/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/07/12 16:31:59 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

#include "ClapTrap.hpp"
#include "pair.hpp"

#ifndef USE_STD
# define ft std
#endif

int	main()
{

	// 8 -7 12 5 0 1 13 20 2 7

	// in the order : 
	// -7 0 1 2 5 7 8 12 13 20 

	ft::map<int, int>	g;


	g[5] = 5;
	g[3] = 3;

	g[2] = 2;
	g[1] = 1;


	g[6] = 6;
	g[4] = 4;
// 0 2 12 5 8 7 1 20 -7 13

	for (ft::map<int, int>::iterator it = g.begin(); it != g.end(); ++it)
	{
		std::cout << (*it).first << std::endl;
	}
	

	return 0;
}
