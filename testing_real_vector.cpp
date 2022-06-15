/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/15 19:51:26 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "vector.hpp"
#include "ClapTrap.hpp"

/*#define ft std*/

int	main()
{
	ft::vector<int>		fv;
	std::vector<int>	stdv;
	for (size_t i = 0; i < 10; i++)
	{
		fv.push_back(i);
		stdv.push_back(i);
	}

	ft::vector<int>::const_reverse_iterator	rbfv	= fv.rbegin();
	ft::vector<int>::reverse_iterator	refv	= fv.rend();
	std::vector<int>::reverse_iterator	rbstdv	= stdv.rbegin();
	std::vector<int>::reverse_iterator	restdv	= stdv.rend();

	std::cout << rbfv - refv << std::endl;
	std::cout << stdv.rbegin() - stdv.rend() << std::endl;




	return (0);
}
