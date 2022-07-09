/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/07/09 15:45:39 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

#include "ClapTrap.hpp"
#include "pair.hpp"

#define ft std

int	main()
{
	ft::pair<char, int>	p = ft::make_pair<char, int>('g', 42);

	ft::pair<char, int>	f(p);

	p.first = 'h';
	

	std::cout << f.first << std::endl;
	std::cout << f.second << std::endl;

	return 0;
}