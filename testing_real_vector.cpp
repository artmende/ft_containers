/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_real_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:03:40 by artmende          #+#    #+#             */
/*   Updated: 2022/07/01 18:28:10 by artmende         ###   ########.fr       */
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

//int	main()
//{
//	ft::vector<int>	v(5, -7);

//	ft::vector<int>::iterator	it = v.begin();

//	std::cout << it.base() << std::endl;
//	std::cout << (it += 2).base() << std::endl;
//	return 0;
//}


template <typename T>
void	printSize(ft::vector<T> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


int		main(void)
{
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::reverse_iterator it = vct.rbegin();
//	ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	for (size_t i = 0; i < vct.size(); i++)
	{
		std::cout << vct[i] << std::endl;
	}
	

	//it = it + 5;
	//it = 1 + it;
	//it = it - 4;
	//std::cout << *(it += 2) << std::endl;
	//std::cout << *(it -= 1) << std::endl;

	//*(it -= 2) = 42;
	//*(it += 2) = 21;

	//std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	//std::cout << "(it == const_it): " << (ite == it) << std::endl;
	//std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	//std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	//printSize(vct, true);
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