/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_rbt.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:54:25 by artmende          #+#    #+#             */
/*   Updated: 2022/07/20 18:55:11 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "red_black_tree.hpp"
#include "stack.hpp"



template <typename T>
void printBT(const std::string& prefix, const ft::red_black_node<T>* node, bool isLeft)
{
    if( node != NULL )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->v << std::endl;

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




int	main()
{

	std::srand(19);

	ft::vector<int>	st;



	for (size_t i = 0; i < 20; i++)
	{
		st.push_back(rand() % 200);
	}



	ft::red_black_tree<int>	rbt;






	for (size_t i = 0; i < st.size(); i++)
	{
		rbt.insert(st[i]);
	}

	//int	cinquante = 50;
	//int	quarantequatre = 44;

	rbt.insert(50);
	rbt.insert(44);

	printBT(rbt._root);



	ft::red_black_node<int>	*browse = rbt._root;
	while (browse->left)
		browse = browse->left;

	while (browse)
	{
		std::cout << browse->v << std::endl;
		browse = rbt.find_successor(browse);
	}



	//std::cout << "\ndeleting 173, 198, 106, 51, 181, 180\n" << std::endl;

	//std::cout << rbt.find(44)->v << "\n\n";

	//rbt.find(44)->v = 45;

	//rbt.remove(173);
	//rbt.remove(198);
	//rbt.remove(106);
	//rbt.remove(51);
	//rbt.remove(181);
	//rbt.remove(180);
	//rbt.remove(133);
	//rbt.remove(37);


//std::cout << rbt._root->right->p.first << std::endl;

//	printBT(rbt._root);

//	std::cout << rbt.find(181)->first << std::endl;

	return 0;
}
