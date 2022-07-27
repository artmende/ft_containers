/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/07/27 17:03:57 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

#include "ClapTrap.hpp"
#include "pair.hpp"
#include "map.hpp"


#ifdef USE_STD
# define ft std
#endif

int	main()
{

	std::less<int>	ll;

	std::cout << ll(8, 7) << std::endl;

	ft::map<int, int>::value_compare	vc(ll);






	ft::pair<int, ClapTrap>	p1;


	ft::pair<int, ClapTrap>	p2;

	p1.first = 4;
	p1.second = ClapTrap("josh");

	p2.first = 8;
	p2.second = ClapTrap("Max");


	ft::red_black_tree<const ClapTrap>	rbtclap;

	rbtclap.insert(ClapTrap("bob"));
	rbtclap.insert(ClapTrap("Danny"));
	rbtclap.insert(ClapTrap("max"));

	ft::red_black_tree<const ClapTrap>	copy(rbtclap);

	ft::red_black_node<const ClapTrap>	*n = copy._root;
	while (copy.find_predecessor(n))
		n = copy.find_predecessor(n);
	while (n)
	{
		std::cout << n->v << std::endl;
		n = copy.find_successor(n);
	}

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

	return 0;
}
