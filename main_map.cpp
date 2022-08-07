/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/08/07 17:42:15 by artmende         ###   ########.fr       */
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

struct test
{
	bool	operator==(test const & x) const {return (this == &x);}
	bool	operator<(test const & x) const {return (this < &x);}
};


template <typename T>
void printBT(const std::string& prefix, const ft::red_black_node<T>* node, bool isLeft)
{
    if( node != NULL )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->v.first << (node->color == true ? " black" : " red") << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template <typename T>
void printBT(const ft::red_black_node<T>* node)
{
    printBT("", node, false);    
}

// pass the root node of your binary tree


int main ()
{
/*	int j = 5;
	ft::red_black_node<int>	y(&j, true, true);

	std::allocator<ft::red_black_node<int> >	al;

	ft::red_black_node<int>	*n = al.allocate(1);

	al.construct(n, &j, false, false);*/


	ft::map<int, int>	mm;

	for (size_t i = 0; i < 20; i++)
	{
		mm[i] = i;
	}

	//for (ft::map<int, int>::iterator it = mm.begin(); it != mm.end(); it++)
	//{
	//	std::cout << (*it).first << std::endl;
	//}

	std::cout << "\n\n";

	printBT(mm._tree._root);


	//ft::map<char, int> first;

	//first['a'] = 10;
	//first['b'] = 30;
	//first['c'] = 50;
	//first['d'] = 70;

	//ft::map<char, int>	second;
	//second = first;

	//second['5'] = 50;

	//for (ft::map<char, int>::iterator i = second.begin(); i != second.end(); i++)
	//{
	//	std::cout << (*i).first << " -> " << (*i).second << std::endl;
	//}

	//std::cout << "-----------------\n";

	//for (ft::map<char, int>::reverse_iterator	rit = first.rbegin(); rit != first.rend(); rit++)
	//{
	//	std::cout << (*rit).first << " -> " << (*rit).second << std::endl;
	//}

	//test	t1, t2;

	//ft::map<int, test>	m1, m2;

	//m1[2] = test();

	//std::cout << "t1 == t2 ? " << (t1 == t2) << std::endl;

	//std::cout << "m1 == m2 ? " << (m1 == m2) << std::endl;

	//std::cout << "first > second ? " << (first > second) << std::endl;

	//std::cout << "max size is : " << m1.max_size() << std::endl;

	return 0;
}



//int	main()
//{
//	ft::map<char, int> mymap;

//	mymap['a'] = 10;
//	mymap['b'] = 20;
//	mymap['c'] = 30;

//	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
//	ret = mymap.equal_range('b');

//	std::cout << "lower bound points to: ";
//	std::cout << ret.first->first << " => " << ret.first->second << '\n';

//	std::cout << "upper bound points to: ";
//	std::cout << ret.second->first << " => " << ret.second->second << '\n';

//	return 0;
//}

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