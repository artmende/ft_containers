/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:31:37 by artmende          #+#    #+#             */
/*   Updated: 2022/07/10 11:52:25 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <math.h>

#ifdef USE_STD
# define ft std
#endif

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
