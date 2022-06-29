/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/06/29 16:03:07 by artmende         ###   ########.fr       */
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

#define ft std





int		main(void)
{
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::iterator it_ = vct.begin();
	ft::vector<int>::reverse_iterator it(it_);

	it_ - (it_ + 3);
	3 + it_;
	it_ - 3;
	ft::vector<int>::const_iterator	cit_ = it_ - 2;

	cit_ - it_;

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
//	printSize(vct);

//	ft::vector<int>::iterator	test = (ft::vector<int>::iterator)(it_ + 3).base();

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (3 + it).base()) << std::endl;

	std::cout << *(it_ + 3) << std::endl;

	//std::cout << *(it.base() + 1) << std::endl;
	//std::cout << *(it - 3) << std::endl;
	//std::cout << *(it - 3).base() << std::endl;
	//it -= 3;
	//std::cout << *it.base() << std::endl;

	//std::cout << "TEST OFFSET" << std::endl;
	//std::cout << *(it) << std::endl;
	//std::cout << *(it).base() << std::endl;
	//std::cout << *(it - 0) << std::endl;
	//std::cout << *(it - 0).base() << std::endl;
	//std::cout << *(it - 1).base() << std::endl;

	return (0);
}



/*
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
*/