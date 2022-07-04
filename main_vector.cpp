/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:37:18 by artmende          #+#    #+#             */
/*   Updated: 2022/07/04 09:49:40 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <list>

int	main()
{
	std::srand(time(NULL));
	{	// CONSTRUCTORS - ASSIGNMENT OPERATOR
		std::cout << "\nTESTING CONSTRUCTORS AND ASSIGMENT OPERATOR\n\n";

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
		std::cout << "\nTESTING ITERATOR FUNCTIONS\n\n";
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
		

		
	}


	return 0;
}