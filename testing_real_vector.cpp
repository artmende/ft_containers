/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/23 18:53:25 by artmende         ###   ########.fr       */
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



	ft::vector<int>	v(10, 5);
	ft::vector<int>	y(10, -6);
	ft::vector<int>	z(8, -2);

	int	*ptr = (v.begin().base()) - 10;

	for (size_t i = 0; i < 50; i++)
	{
		std::cout << *(ptr + i) << std::endl;
	}
	

	return (0);
}
