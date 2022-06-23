/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/23 23:32:06 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "vector.hpp"
#include "ClapTrap.hpp"
#include <list>
#include <stdlib.h>

// #define ft std

#define current b



int	main()
{

	std::list<int> lst;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::vector<int> vct(lst.begin(), lst.end());
	
	for (auto value : vct)
		std::cout << value << std::endl;
	std::cout << "\n";

	std::list<int>::iterator lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());

	for (auto value : vct)
		std::cout << value << std::endl;
	std::cout << "\n";

	vct.insert(vct.end(), lst.rbegin(), lst.rend());

	for (auto value : vct)
		std::cout << value << std::endl;
	std::cout << "\n";

	return (0);
}
