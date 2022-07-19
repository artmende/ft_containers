/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/07/19 14:40:26 by artmende         ###   ########.fr       */
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

	ft::map<int, int> mm;
	ft::pair<int, char>	p1;

	ft::pair<int, char>	p2 = ft::pair<int, char>(6, 'j');

	p1.first = 4;
	p1.second = 'b';

	p2.first = 4;
	p2.second = 'a';

(void)p2;

	std::cout << ft::make_pair(9, 'h').first << std::endl;

	std::cout << "(p1 < p2) ? " << (p1 < ft::pair<int, char>(7, 'h')) << std::endl;

	std::cout << "(p1 > p2) ? " << (p1 > p2) << std::endl;

	std::cout << "a < b ? " << ('a' < 'b') << std::endl; 

	return 0;
}
