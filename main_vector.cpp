/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:37:18 by artmende          #+#    #+#             */
/*   Updated: 2022/07/04 11:30:49 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <list>
#include <algorithm>

//#define ft std

int	main()
{
	std::srand(time(NULL));
	{	// CONSTRUCTORS - ASSIGNMENT OPERATOR
		std::cout << "\nTESTING CONSTRUCTORS AND ASSIGMENT OPERATOR\n";

		ft::vector<int>	vdefault; //default constructor
		std::cout << "size of vdefault : " << vdefault.size() << "\n\n";

		ft::vector<int>	vfill(4, -5); //fill constructor
		std::cout << "Displaying the content of vfill :\n";
		for (size_t i = 0; i < vfill.size(); i++)
			std::cout << vfill[i] << '\n';

		std::list<int>	templist;
		for (size_t i = 0; i < 4; i++) // putting some data in temporary list
			templist.push_back(i * i);
		ft::vector<int>	vrange(templist.begin(), templist.end()); // range construcor
		std::cout << "\nDisplaying the content of vrange :\n";
		for (size_t i = 0; i < vrange.size(); i++)
			std::cout << vrange[i] << '\n';

		ft::vector<int>	vcopy(vfill); // copy constructor
		std::cout << "\nDisplaying the content of vcopy :\n";
		for (size_t i = 0; i < vcopy.size(); i++)
			std::cout << vcopy[i] << '\n';

		std::cout << "\nvdefault = vrange\n";
		vdefault = vrange;
		std::cout << "\nDisplaying the content of vdefault :\n";
		for (size_t i = 0; i < vdefault.size(); i++)
			std::cout << vdefault[i] << '\n';
	}

	{	// ITERATORS
		std::cout << "\nTESTING ITERATOR\n";
		ft::vector<int>	v;
		for (size_t i = 0; i < 10; i++)
			v.push_back(rand() % 1000);
		std::cout << "Displaying initial content of vector : \n";
		ft::vector<int>::iterator	it1 = v.begin();
		ft::vector<int>::const_iterator	it2(v.end());
		while (it1 < it2) // const and non const can be compared
		{
			std::cout << *it1 << std::endl; // dereferencing iterator
			++it1;
		}

		ft::vector<int>::reverse_iterator	rit = v.rbegin();
		*rit = -5; // dereferencing reverse iterator to make an assignation
		*(v.begin()) = *rit;
		std::cout << "\nDisplaying in the reverse order, firt and last element have been set to -5.\n";
		while (rit.base() != v.begin()) // base of reverse iterator is a normal iterator, that can be compared to begin()
		{
			std::cout << *rit << std::endl;
			++rit;
		}

		ft::vector<int>::const_reverse_iterator	crit(it1); // const reverse iterator can be constructed from const or non const iterator
		std::cout << "Displaying last element one more time : " << *crit << std::endl;

	//	ft::vector<int>::reverse_iterator	critnon(it2); // non const reverse iterator cannot be constructed from non const iterator (This line does not compile)
	//	*crit = 7; // cannot assign with a const iterator (This line does not compile)
		std::sort(v.begin(), v.end());
		std::cout << "\nDisplaying elements after applying standard algorithm 'std::sort' :\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;
	}

	{	// CAPACITY
		std::cout << "\nTESTING CAPACITY FUNCTIONS\n";

		ft::vector<int>	v;

		std::cout << "New vector created with default constructor. Is it emtpy ? " << (v.empty() ? "yes" : "no") << std::endl;
		std::cout << "\nPushing 5 elements in the vector\n";
		for (size_t i = 0; i < 5; i++)
			v.push_back(i);
		std::cout << "size : " << v.size() << " | capacity : " << v.capacity() << " | max_size : " << v.max_size() << std::endl;

		std::cout << "\nResizing to 10 with value -7\n";
		v.resize(10, -7);
		std::cout << "size : " << v.size() << " | capacity : " << v.capacity() << " | max_size : " << v.max_size() << std::endl;

		std::cout << "\nReserving for 20 elements\n";
		v.reserve(20);
		std::cout << "size : " << v.size() << " | capacity : " << v.capacity() << " | max_size : " << v.max_size() << std::endl;

		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;
	}

	{	// ELEMENT ACCESS
		std::cout << "\nTESTING ELEMENT ACCESS FUNCTIONS\n";

		ft::vector<int>	v;
		v.reserve(10);
		for (size_t i = 0; i < v.capacity(); i++)
			v.push_back(rand() % 50);

		std::cout << "\nWriting -7 on index 3 and 8\n";
		v[3] = -7;
		v.at(8) = -7;

		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << "index " << i << " : " << v[i] << std::endl;

		std::cout << "\nDisplaying front and back :\n";
		std::cout << "front : " << v.front() << " | back : " << v.back() << std::endl;
		std::cout << "\nDisplaying element with index 2, 7 and 19 (will throw an exception) :\n";
		std::cout << "index 2 : " << v[2] << " | index 7 : " << v.at(7) << std::endl;
		try
		{
			std::cout << v.at(19);
		}
		catch(const std::exception& e)
		{
			std::cout << "Exception : " << e.what() << '\n';
		}
	}

	{	// MODIFIERS
		std::cout << "\nTESTING MODIFIERS FUNCTIONS\n";

		ft::vector<int>	v;
		std::cout << "\nAssigning vector to 9 elements with value -3\n";
		v.assign(9, -3);
		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;

		std::list<int>	l;
		for (size_t i = 0; i < 5; i++)
			l.push_front(i);
		std::cout << "\nAssigning vector to the size and values of list l\n";
		v.assign(l.begin(), l.end());
		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;

		std::cout << "\nPopping back last element of vector and pushing back -5\n";
		v.pop_back();
		v.push_back(-5);

		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;

		std::cout << "\nInserting -2 at second position\n";
		v.insert(v.begin() + 1, -2);
		std::cout << "\nInserting -19 five times just before the last element\n";
		v.insert(v.end() - 1, 5, -19);

		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;

		std::cout << "\nInserting the last 3 elements of list l in the reverse order right at the beginning of the vector\n";
		std::list<int>::reverse_iterator	ritl = l.rbegin();
		for (size_t i = 0; i < 3; i++)
			++ritl;
		
		v.insert(v.begin(), l.rbegin(), ritl);

		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;

		std::cout << "\nErasing element with index 4 and last 5 elements of vector\n";
		v.erase(v.begin() + 4);
		v.erase(v.end() - 5, v.end());

		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;
		
		std::cout << "\nSwapping the vector with temporary vector containing only 3 elements of value -7\n";
		ft::vector<int>(3, -7).swap(v);
		std::cout << "size : " << v.size() << " | capacity : " << v.capacity() << std::endl;

		std::cout << "\nDisplaying content\n";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << std::endl;
		
		std::cout << "\nClearing the vector\n";
		v.clear();
		std::cout << "size : " << v.size() << " | capacity : " << v.capacity() << std::endl;
	}

	{	// RELATIONAL OPERATORS
		std::cout << "\nTESTING RELATIONAL OPERATORS\n";

		ft::vector<int>	s1, s2;
		for (size_t i = 0; i < 5; i++)
		{
			s1.push_back(rand() % 5);
			s2.push_back(rand() % 5);
		}

		std::cout << "Comparison operators : \n" << std::boolalpha;
		std::cout << "s1 == s2 : " << (s1 == s2) << '\n';
		std::cout << "s1 != s2 : " << (s1 != s2) << '\n';
		std::cout << "s1 < s2 : " << (s1 < s2) << '\n';
		std::cout << "s1 <= s2 : " << (s1 <= s2) << '\n';
		std::cout << "s1 > s2 : " << (s1 > s2) << '\n';
		std::cout << "s1 >= s2 : " << (s1 >= s2) << "\n\n";

		std::cout << "\nDisplaying content of s1\n";
		for (size_t i = 0; i < s1.size(); i++)
			std::cout << s1[i] << std::endl;

		std::cout << "\nDisplaying content of s2\n";
		for (size_t i = 0; i < s2.size(); i++)
			std::cout << s2[i] << std::endl;
	}

	return 0;
}
