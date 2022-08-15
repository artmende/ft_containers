/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:10:27 by artmende          #+#    #+#             */
/*   Updated: 2022/08/15 16:47:39 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"

//# define ft std

int	main()
{
	std::srand(19);

	ft::set<int>	s;

	for (size_t i = 0; i < 20; i++)
	{
		s.insert(rand() % 50);
	}

	ft::set<int>::iterator itmodif = s.begin();
	++itmodif;
	//*itmodif = 23;

	for (ft::set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	

	return 0;
}