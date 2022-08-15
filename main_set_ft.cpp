/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set_ft.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:10:27 by artmende          #+#    #+#             */
/*   Updated: 2022/08/15 17:52:51 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <list>
#include "set.hpp"

int	main()
{
	std::srand(19);

	std::list<int>	l;
	for (size_t i = 0; i < 5; i++)
		l.push_back(rand() % 50);

	ft::set<int>	s1; // empty
	ft::set<int>	s2(l.begin(), l.end()); // range
	ft::set<int>	s3(s2); // copy

	s1 = s3; // operator=

	std::cout << "value of s1 :\n";
	for (ft::set<int>::const_iterator it = s1.begin(); it != s1.end(); it++) // iterators
	{
		std::cout << *it << std::endl;
	}

	std::cout << "\nclearing s2\n";

	s2.clear();
	std::cout << "\nsize of s2 : " << s2.size() << std::endl;

	std::cout << "\ninserting new elements in s2\n";
	s2.insert(19);
	s2.insert(l.begin(), l.end());
	s2.insert(s2.begin(), 14);

	std::cout << "\nvalue of s2 :\n";
	for (ft::set<int>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "\nErasing first element in s2, element with value 19, and last 2 elements\n";
	s2.erase(s2.begin());
	s2.erase(19);
	ft::set<int>::iterator	itdel = s2.end();
	--itdel; --itdel;
	s2.erase(itdel, s2.end());

	std::cout << "\nvalue of s2 :\n";
	for (ft::set<int>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "\nSwapping s1 and s2\n";
	s1.swap(s2);

	std::cout << "\nvalue of s2 :\n";
	for (ft::set<int>::const_iterator it = s2.begin(); it != s2.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "\nSearching for element with value -40\n";
	ft::set<int>::iterator	itfind = s2.find(-40);
	if (itfind == s2.end())
		std::cout << "-40 is not part of the set\n";
	else
		std::cout << "Found it ! : " << *itfind << std::endl;

	std::cout << "\nSearching for element with value 29\n";
	itfind = s2.find(29);
	if (itfind == s2.end())
		std::cout << "29 is not part of the set\n";
	else
		std::cout << "Found it ! : " << *itfind << std::endl;

	std::cout << "\nThere are " << s2.count(26) << " elements with value 26\n";
	std::cout << "There are " << s2.count(100) << " elements with value 100\n";

	std::cout << "\nDisplaying elements of s1 in reverse order :\n";
	for (ft::set<int>::const_reverse_iterator it = s1.rbegin(); it != s1.rend(); it++) // iterators
	{
		std::cout << *it << std::endl;
	}

	return 0;
}