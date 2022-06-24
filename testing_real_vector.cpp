/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/24 18:03:17 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "vector.hpp"
#include "ClapTrap.hpp"
#include <list>
#include <stdlib.h>
#include <stack>
#include "stack.hpp"

#include <iomanip>
#include <math.h>

//#define ft std

int	main()
{
	ft::stack<int, ft::vector<int> > s1, s2;

	for (size_t i = 0; i < 10; i++)
	{
		s1.push(pow(-1, i) * i);
		s2.push(i);
	}
	s2.pop();

	std::cout << "Comparison operators : \n" << std::boolalpha;
	std::cout << "s1 == s2 : " << (s1 == s2) << '\n';
	std::cout << "s1 != s2 : " << (s1 != s2) << '\n';
	std::cout << "s1 < s2 : " << (s1 < s2) << '\n';
	std::cout << "s1 <= s2 : " << (s1 <= s2) << '\n';
	std::cout << "s1 > s2 : " << (s1 > s2) << '\n';
	std::cout << "s1 >= s2 : " << (s1 >= s2) << "\n\n";

	std::cout << "s1 (size " << s1.size() << " ) : \n";
	while (!(s1.empty()))
	{
		std::cout << s1.top() << '\n';
		s1.pop();
	}

	std::cout << "\ns2 (size " << s2.size() << " ) : \n";
	while (!(s2.empty()))
	{
		std::cout << s2.top() << '\n';
		s2.pop();
	}

	return (0);
}
