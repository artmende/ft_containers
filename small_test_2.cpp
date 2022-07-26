/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_test_2.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:45:55 by artmende          #+#    #+#             */
/*   Updated: 2022/07/26 16:00:47 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <stdlib.h>
#include <unistd.h>

#define ft std

int	main()
{
	srand(getpid());

	ft::map<int, int>	m;

	for (size_t i = 0; i < 100; i++)
	{
		m[rand() % 500] = rand();
	}

	for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}

	std::cout << (*(m.begin())).first << std::endl;
	std::cout << (*((m.rend()))).first << std::endl;

	return 0;
}
