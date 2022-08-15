/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:31:37 by artmende          #+#    #+#             */
/*   Updated: 2022/08/15 15:07:50 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>
#include <vector>
#include <math.h>

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
