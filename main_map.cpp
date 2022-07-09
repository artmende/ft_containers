/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/07/09 13:48:51 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

#include "ClapTrap.hpp"

int	main()
{
	std::map<int, ClapTrap>	m;

//	m[5] = 'p';

	std::cout << m.empty() << std::endl;

	std::cout << m[5] << '\n';

	std::cout << m.empty() << std::endl;

	return 0;
}