/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/08/02 15:04:38 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

#include "ClapTrap.hpp"
#include "pair.hpp"
#include "map.hpp"
#include "bst_iterator.hpp"


#ifdef USE_STD
# define ft std
#endif

int	main()
{
	
	ft::map<int, int>	mm;

	for (size_t i = 0; i < 20; i++)
	{
		mm._tree.insert(ft::make_pair(i, i));
	}

	ft::map<int, int>::iterator	cite = mm.begin();
	(*cite).second = 4;

	mm[8] = 1000;
	mm[51] = -10;

	for (ft::map<int, int>::const_iterator it = mm.begin(); it != mm.end(); ++it)
	{
		std::cout << (*it).second << std::endl;
	}




	return 0;
}

/*

int	main()
{



	{

	ft::map<int, int>	mm;

	mm.base()->insert(ft::make_pair<int, int>(5, 5));

	ft::map<int, int>::iterator	itm = mm.begin();

	itm++;

	std::cout << (*itm).first << std::endl;

	ClapTrap		testclap1("un");
	const ClapTrap	testclap2(testclap1);

	ClapTrap		testclap3(testclap2);


	ft::pair<int, ClapTrap>	p1;


	ft::pair<int, ClapTrap>	p2;

	p1.first = 4;
	p1.second = ClapTrap("josh");

	p2.first = 8;
	p2.second = ClapTrap("Max");


	ft::red_black_tree<ClapTrap>	rbtclap;



	rbtclap.insert(ClapTrap("bob"));
	rbtclap.insert(ClapTrap("Danny"));
	rbtclap.insert(ClapTrap("max"));

	ft::red_black_tree<ClapTrap>	copy(rbtclap);

	copy = *(&copy);

	const ft::red_black_node<ClapTrap>	*n = copy._root->find_first_node();
	//while (copy.find_predecessor(n))
	//	n = copy.find_predecessor(n);
	while (n)
	{
		std::cout << n->v << std::endl;
		n = n->find_successor();
	}

	std::cout << "testing iterators :\n\n";

	ft::bst_iterator<ClapTrap, ft::red_black_node<ClapTrap> >	it(copy._root);
	ft::bst_iterator<const ClapTrap, ft::red_black_node<ClapTrap> >	cit(it);


	*it = ClapTrap("yoppp");

	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	std::cout << std::endl;
	for (size_t i = 0; i < 5; ++i)
	{
		std::cout << *cit << std::endl;
		cit--;
	}




	//std::cout << "\ndown here is map declaration\n\n";

	//ft::map<int, ClapTrap> mm;

	//mm.base()->insert(p1);
	//mm.base()->insert(p2);
	//mm.base()->insert(ft::make_pair(5, ClapTrap("Denis")));

	//ft::red_black_node<ft::pair<const int, ClapTrap> >	*node = mm.base()->_root;

	//while (mm.base()->find_predecessor(node))
	//	node = mm.base()->find_predecessor(node);

	//while (node)
	//{
	//	std::cout << node->v.second << std::endl;
	//	node = mm.base()->find_successor(node);
	//}

(void)p2;

	

//	std::cout << "(p1 > p2) ? " << (p1 > p2) << std::endl;

	std::cout << "a < b ? " << ('a' < 'b') << std::endl; 

	}


	return 0;
}

*/