/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:45:10 by artmende          #+#    #+#             */
/*   Updated: 2022/08/14 17:59:28 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

#include "ClapTrap.hpp"
#include "pair.hpp"
#include "map.hpp"
#include "bst_iterator.hpp"

# include <vector>

#ifdef USE_STD
# define ft std
#endif

struct test
{
	bool	operator==(test const & x) const {return (this == &x);}
	bool	operator<(test const & x) const {return (this < &x);}
};


//template <typename T>
//void printBT(const std::string& prefix, const ft::red_black_node<T>* node, bool isLeft)
//{
//    if( node != NULL )
//    {
//        std::cout << prefix;

//        std::cout << (isLeft ? "├──" : "└──" );

//        // print the value of the node
//        std::cout << node->v.first << (node->color == true ? " black" : " red") << std::endl;

//        // enter the next tree level - left and right branch
//        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
//        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
//    }
//}

//template <typename T>
//void printBT(const ft::red_black_node<T>* node)
//{
//    printBT("", node, false);    
//}



int main ()
{

	{
		std::cout << "Testing constructors, assignment operator, iterators and capacity:\n\n";

		ft::map<int, std::string>	temp;
		for (size_t i = 0; i < 5; i++)
		{
			temp[i] = "some string";
		}

		ft::map<int, std::string>	map_default; // default constructor
		ft::map<int, std::string>	map_range(temp.begin(), temp.end());
		ft::map<int, std::string>	map_copy(map_range);
		ft::map<int, std::string>	map_assigned;
		map_assigned = map_copy;

		std::cout << "size of map_default : " << map_default.size() << " | size of map_range : " << map_range.size() << " | size of map_copy : " << map_copy.size() << " | size of map_assigned : " << map_assigned.size() << std::endl;
		std::cout << "content of map_assigned : \n";
		for (ft::map<int, std::string>::const_iterator	it = map_assigned.begin(); it != map_assigned.end(); it++)
		{
			std::cout << (*it).first << " --> " << (*it).second << std::endl;
		}

		std::cout << "\niterating through map_range in the reverse order :\n";
		for (ft::map<int, std::string>::const_reverse_iterator it = map_range.rbegin(); it != map_range.rend(); it++)
		{
			std::cout << (*it).first << " --> " << (*it).second << std::endl;
		}

		std::cout << "\nmap_default.empty() : " << map_default.empty() << std::endl;
		std::cout << "map_copy.empty() : " << map_copy.empty() << std::endl;
		std::cout << "Max size of map_default : " << map_default.max_size() << std::endl;

		std::cout << "\n\n";
	}

	{
		std::cout << "Testing Element access and modifiers:\n\n";

		ft::map<int, char>	temp;
		temp[-10] = '~';
		temp[2] = '1';
		temp[17] = '?';

		ft::map<int, char>	my_ascii_letters;
		for (size_t i = 65; i < 70; i++)
		{
			my_ascii_letters[i] = i;
		}
		std::cout << "inserting single element... Was it already there ? " << !(my_ascii_letters.insert(ft::make_pair<int, char>(33, 33))).second << std::endl; // single element (1)
		std::cout << "inserting single element... Was it already there ? " << !(my_ascii_letters.insert(ft::make_pair<int, char>(33, 33))).second << std::endl;
		my_ascii_letters.insert(my_ascii_letters.begin(), ft::make_pair<int, char>(92, 92)); // with hint (2)
		my_ascii_letters.insert(temp.rbegin(), temp.rend()); // range (3)
		std::cout << my_ascii_letters[200] << std::endl; // this create an element with key 200 but the 'second' is set to default value (\0);


		for (ft::map<int, char>::const_iterator	it = my_ascii_letters.begin(); it != my_ascii_letters.end(); it++)
		{
			std::cout << (*it).first << " --> " << (*it).second << std::endl;
		}

	}




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