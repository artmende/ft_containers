/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_rbt.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:54:25 by artmende          #+#    #+#             */
/*   Updated: 2022/07/18 16:07:31 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "red_black_tree.hpp"
#include "stack.hpp"



template <typename Key, typename T>
void printBT(const std::string& prefix, const ft::red_black_node<Key, T>* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->p.first << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template <typename Key, typename T>
void printBT(const ft::red_black_node<Key, T>* node)
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



	

	ft::red_black_tree<int, int>	rbt;




	for (size_t i = 0; i < st.size(); i++)
	{
		ft::pair<const int, int>	pa(st[i], st[i]);
		rbt.insert(pa);
	}


	ft::pair<const int, int>	cinquante(50, 50);
	ft::pair<const int, int>	quarantequatre(44, 44);
	rbt.insert(cinquante);
	rbt.insert(quarantequatre);

	printBT(rbt._root);

	std::cout << "\ndeleting 173, 198, 106, 51, 181, 180\n" << std::endl;




	rbt.delete_node(173);
	rbt.delete_node(198);
	rbt.delete_node(106);
	rbt.delete_node(51);
	rbt.delete_node(181);
	rbt.delete_node(180);


//std::cout << rbt._root->right->p.first << std::endl;

	printBT(rbt._root);

//	std::cout << rbt.find(181)->first << std::endl;

	return 0;
}
