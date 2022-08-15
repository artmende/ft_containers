/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:10:27 by artmende          #+#    #+#             */
/*   Updated: 2022/08/15 17:19:12 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <list>
#include "set.hpp"

//# define ft std

int	main()
{
	std::srand(19);

	ft::set<int>	s1, s2;

	for (size_t i = 0; i < 5; i++)
	{
		s1.insert(rand() % 50);
		s2.insert(rand() % 50);
	}


	std::cout << "value of s1 :\n";
	for (ft::set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "\nvalue of s2 :\n";
	for (ft::set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "\nSwapping...\n\n";
	s1.swap(s2);

	std::cout << "value of s1 :\n";
	for (ft::set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "\nvalue of s2 :\n";
	for (ft::set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	s1.clear();

	//std::list<int> lst;
	//unsigned int lst_size = 7;
	//for (unsigned int i = 0; i < lst_size; ++i)
	//	lst.push_back(lst_size - i);

	//ft::set<int> st(lst.begin(), lst.end());
	//ft::set<int>::iterator it = st.begin(), ite = st.end();

	//ft::set<int> st_range(it, --(--ite));
	//for (int i = 0; i < 5; ++i)
	//	st.insert(i * 5);

	//it = st.begin(); ite = --(--st.end());
	//ft::set<int> st_copy(st);
	//for (int i = 0; i < 7; ++i)
	//	st.insert(i * 7);

	//std::cout << "\t-- PART ONE --" << std::endl;
	////printSize(st);
	////printSize(st_range);
	////printSize(st_copy);

	//st = st_copy;
	//st_copy = st_range;
	//st_range.clear();

	//std::cout << "\t-- PART TWO --" << std::endl;
	////printSize(st);
	////printSize(st_range);
	////printSize(st_copy);
	//return (0);
}